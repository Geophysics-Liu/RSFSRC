/* 1-D and 2-D edge-preserving smoothing (EPS) filter. 
1D filter (nfw2=1); 2D filter (otherwise)
*/
/*
  Copyright (C) 2009 University of Texas at Austin
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <rsf.h>
#include <stdio.h>
#include <math.h>

#include "mean.h"
#include "median.h"
#include "deviation.h"
#include "boundary.h"

int main (int argc, char* argv[]) 
{
    int n1,n2,n3;     /* data dimension */
    int nfw1,nfw2;    /* filter-window length in sample direction (nfw1) and trace direction (nfw2) */
    int m1,m2,index,*nindex;
    char *type;
   
    int i,j,k,p,ii,kk,pp; /* loop index */
    bool boundary, verb, weight;
    
    float tindex,*trace,*tempt,*temp1,*extendt,*sdev,*result,sigma,*w;
    sf_file in, out;
    
    sf_init (argc, argv); 
    in = sf_input("in");
    out = sf_output("out");
    
    if (!sf_histint(in,"n1",&n1)) sf_error("No n1= in input");
    if (!sf_histint(in,"n2",&n2)) sf_error("No n2= in input");
    n3 = sf_leftsize(in,2);
    /* get the trace length (n1) and the number of traces (n2) and n3 */
    
    if (!sf_getint("nfw1",&nfw1)) sf_error("Need integer input");
    /* filter-window length in n1 direction (positive and odd integer) */
    
    if (!sf_getint("nfw2",&nfw2)) nfw2=1;
    /* filter-window length in n2 direction (default=1, 1D case)*/
    
    if (nfw1 < 1 || nfw2 < 1)  sf_error("Need positive integer input"); 
    if (nfw1%2 == 0)  nfw1 = (nfw1+1);
    if (nfw2%2 == 0)  nfw2 = (nfw2+1);
    m1=nfw1-1;
    m2=nfw2-1;
    
    if (!sf_getbool("boundary",&boundary)) boundary=false;
    /* if y, boundary is data, whereas zero*/

    if (NULL == (type=sf_getstring("type"))) type="stack";
    /* [stack,median] filter choice, the default is stack (mean) */

    if (!sf_getbool("verb",&verb)) verb=false;
    /* verbosity flag */

    if ('s'==type[0]) {
	if (!sf_getbool("weight",&weight)) weight=false;
	/* Gaussian weight flag (only for stack) */
	
	if (!sf_getfloat("sigma",&sigma)) sigma=3.;
	/* Gaussian weight radius (only for stack) */

	if (0==sigma) sf_error("Need non-zero float input");
    }

    trace = sf_floatalloc(n1*n2);
    tempt = sf_floatalloc(n1*n2);
    extendt = sf_floatalloc((n1+2*m1)*(n2+2*m2));

    temp1 = sf_floatalloc(nfw1*nfw2);
    w = sf_floatalloc(nfw1*nfw2);
    sdev = sf_floatalloc(nfw1*nfw2);
    result = sf_floatalloc(nfw1*nfw2);
    nindex = sf_intalloc(nfw1*nfw2);
    for(ii=0;ii<n3;ii++) {
	if (verb) sf_warning("slice %d of %d",ii+1,n3);
	sf_floatread(trace,n1*n2,in);
	for(i=0;i<n1*n2;i++){
	    tempt[i]=trace[i];
	}
	
	bound3(tempt,extendt,2*nfw1-1,2*nfw2-1,n1,n2,boundary);
	
	/************edge-preserving smoothing filter****************/
	for(i=0;i<n2;i++){
	    for(j=0;j<n1;j++) {
		for(p=0;p<nfw1*nfw2;p++){
		    nindex[p]=p;
		}
		for(p=0;p<nfw2;p++){
		    for(pp=0;pp<nfw1;pp++) {
			for(k=0;k<nfw2;k++){
			    for(kk=0;kk<nfw1;kk++) {
				temp1[k*nfw1+kk]=extendt[(n1+2*m1)*(i+p+k)+j+pp+kk];
				if (weight) {
				    w[k*nfw1+kk] = exp(-1*((p+k-m2)*(p+k-m2)+(pp+kk-m1)*(pp+kk-m1))/(2*sigma*sigma+FLT_EPSILON));
				}
			    }
			}
			sdev[p*nfw1+pp]=sdeviation(temp1,nfw1*nfw2);
			switch(type[0]) {
			    case 's':
				if (weight) {
				    for (k=0;k<nfw1*nfw2;k++) {
					temp1[k] = temp1[k]*w[k];
				    }
				}
				result[p*nfw1+pp]=mean(temp1,nfw1*nfw2);
				break;
			    case 'm':
				result[p*nfw1+pp]=medianfilter(temp1,nfw1*nfw2);
				break;
			    default:
				sf_error("Unknown method type=%c",type[0]);
				break;
			}	    
		    }
		}
		index=0;
		for(p=0;p<nfw1*nfw2-1;p++){
		    if(sdev[p]<sdev[p+1]){
			tindex=sdev[p];
			sdev[p]=sdev[p+1];
			sdev[p+1]=tindex;
			index=nindex[p];
			nindex[p]=nindex[p+1];
			nindex[p+1]=index;
		    }
		}
		index=nindex[nfw1*nfw2-1];
		trace[n1*i+j]=result[index];
	    }
	}
	sf_floatwrite(trace,n1*n2,out);
    }

    exit (0);
}

/* 	$Id: Mepsf.c 7107 2011-04-10 02:04:14Z ivlad $	 */

