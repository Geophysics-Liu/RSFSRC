/* This file is automatically generated. DO NOT EDIT! */

#ifndef _sf_fzero_h
#define _sf_fzero_h


#include "_bool.h"


float sf_zero (float (*func)(float) /* function f(x) */, 
	       float a, float b     /* interval */, 
	       float fa, float fb   /* f(a) and f(b) */,
	       float toler          /* tolerance */, 
	       bool verb            /* verbosity flag */);
/*< Return c such that f(c)=0 (within tolerance). 
  fa and fb should have different signs. >*/

#endif
