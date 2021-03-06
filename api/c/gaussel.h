/* This file is automatically generated. DO NOT EDIT! */

#ifndef _sf_gaussel_h
#define _sf_gaussel_h


void sf_gaussel_init (int size);
/*< initialize >*/


void sf_gaussel_close (void);
/*< free allocated storage >*/


void sf_gaussel_solve (float **a       /* matrix [size][size] */, 
		       const float *b  /* rhs [size] */, 
		       float *x        /* solution [size] */);
/*< solve a*x = b >*/

#endif
