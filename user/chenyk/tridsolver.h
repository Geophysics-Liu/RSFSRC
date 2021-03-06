/* This file is automatically generated. DO NOT EDIT! */

#ifndef _tridsolver_h
#define _tridsolver_h


void trid_init(int N/* matrix size */,
		       float *A/*input matrix*/);
/*< initialize >*/


void trid_solve( float *d /* in - right-hand side */, 
			   float *x /* out - solution */);
/*< invert the matrix >*/


void trid_close(void);
/*< free allocated memory >*/

#endif
