/* 3-D missing data interpolation with adaptive PEFs. */
/*
  Copyright (C) 2010 University of Texas at Austin
  
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

#include "nmis3.h"

int main(int argc, char* argv[])
{
    int niter, n1, n2, i, nf1, nf2, nf3, nf4, nf5, nf6, n3, n4, i4, nf;
    float *mm, *kk, *filt, eps;
    bool *known, exact, verb;
    sf_file in, out, fil, mask=NULL;

    sf_init (argc,argv);
    in = sf_input("in");
    fil = sf_input("filt");
    out = sf_output("out");

    if (!sf_getint("niter",&niter)) niter=100;
    /* Number of iterations */

    if (!sf_getbool("exact",&exact)) exact=true;
    /* If y, preserve the known data values */

    if (!sf_getfloat("eps",&eps)) eps=0.;
    /* regularization parameter */

    if (!sf_getbool("verb",&verb)) verb = false;
    /* verbosity flag */

    /* input data, output model */
    if (!sf_histint(in,"n1",&n1)) sf_error("No n1= in input");
    if (!sf_histint(in,"n2",&n2)) sf_error("No n2= in input");
    if (!sf_histint(in,"n3",&n3)) sf_error("No n3= in input");
    n4 = sf_leftsize(in,3);

    if (1==n1 && 1==n2 && 1==n3) {
	if (!sf_histint(in,"n4",&n1)) sf_error("No n4= in input");
	if (!sf_histint(in,"n5",&n2)) sf_error("No n5= in input");
	if (!sf_histint(in,"n6",&n3)) sf_error("No n6= in input");
	n4 = sf_leftsize(in,6);
    }

    sf_fileflush(out,in);  /* copy data dimensions */

    /* input filter */
    if (!sf_histint(fil,"n1",&nf1)) sf_error("No n1= in filter");
    if (!sf_histint(fil,"n2",&nf2)) sf_error("No n2= in filter");
    if (!sf_histint(fil,"n3",&nf3)) sf_error("No n3= in filter");
    if (!sf_histint(fil,"n4",&nf4)) sf_error("No n4= in filter");
    if (!sf_histint(fil,"n5",&nf5)) sf_error("No n5= in filter");
    if (!sf_histint(fil,"n6",&nf6)) sf_error("No n6= in filter");
    
    if (nf4!=n1 || nf5!=n2 || nf6!=n3) 
	sf_error("need n1==nf4 && n2==nf5 && n3==nf6");
    
    nf = nf1*nf2*nf3*nf4*nf5*nf6;
    filt = sf_floatalloc(nf);
    mm = sf_floatalloc(n1*n2*n3);
    kk = sf_floatalloc(n1*n2*n3);
    known = sf_boolalloc(n1*n2*n3);

    for (i=0; i < n1*n2*n3; i++) {
	mm[i]=0.;
	kk[i]=0.;
	known[i]=false;
    }

    if (NULL != sf_getstring("mask")) {
	/* optional input mask file for known data */
	mask = sf_input("mask");
    }

    for (i4=0; i4 < n4; i4++) {
	sf_warning("slice %d of %d",i4+1,n4);
	sf_floatread(mm,n1*n2*n3,in);
	sf_floatread(filt,nf,fil);
	
	if (NULL != sf_getstring("mask")) {
	    sf_floatread(kk,n1*n2*n3,mask);
	    
	    for (i=0; i < n1*n2*n3; i++) {
		known[i] = (bool) (kk[i] != 0.);
	    }
	} else {
	    for (i=0; i < n1*n2*n3; i++) {
		known[i] = (bool) (mm[i] != 0.);
	    }
	}
	
	if (exact) {
	    for (i=0; i < n1*n2*n3; i++) {
		if (known[i]) kk[i] = mm[i];
	    }
	}
	
	nmis3(niter, nf1, nf2, nf3, nf4, nf5, nf6, filt, mm, known, eps, verb);
	
	if (exact) {
	    for (i=0; i < n1*n2*n3; i++) {
		if (known[i]) mm[i] = kk[i];
	    }
	}
	
	sf_floatwrite(mm,n1*n2*n3,out);
    }

    exit (0);
}

/* 	$Id: Mmiss43.c 7107 2011-04-10 02:04:14Z ivlad $	 */
