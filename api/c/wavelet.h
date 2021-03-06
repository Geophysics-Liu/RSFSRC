/* This file is automatically generated. DO NOT EDIT! */

#ifndef _sf_wavelet_h
#define _sf_wavelet_h


void sf_wavelet_init(int n /* data size */, bool inv1, bool unit1, char type);
/*< allocate space >*/


void sf_wavelet_close(void);
/*< deallocate space >*/


void sf_wavelet_lop(bool adj, bool add, int nx, int ny, float *x, float *y);
/*< linear operator >*/

#endif
