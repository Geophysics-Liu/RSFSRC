/*        Generated by TAPENADE     (INRIA, Tropics team)
    Tapenade 3.7 (r4786) - 21 Feb 2013 15:53
*/
#include "cstd.h"

/*
  Differentiation of acd_2d_4_d in forward (tangent) mode:
   variations   of useful results: **upd **up
   with respect to varying inputs: **ucd **upd **csq **uc **up
   RW status of diff variables: **ucd:in **upd:in-out **csq:in
                **uc:in **up:in-out
   Plus diff mem management of: ucd:in *ucd:in upd:in *upd:in
                csq:in *csq:in uc:in *uc:in up:in *up:in


  Differentiation of acd_2d_4 in forward (tangent) mode:
   variations   of useful results: **up
   with respect to varying inputs: **csq **uc **up
   RW status of diff variables: **csq:in **uc:in **up:in-out
   Plus diff mem management of: csq:in *csq:in uc:in *uc:in up:in
                *up:in
*/
void acd_2d_4_d_d(float **uc, float **ucd0, float **ucd, float **ucdd, float *
        *up, float **upd0, float **upd, float **updd, float **csq, float **
        csqd0, float **csqd, int *s, int *e, float c0, float *c1, float *c2, 
        int *lbc, int *rbc) {
    int i0, i1;
    for (i1 = s[1]; i1 < e[1]+1; ++i1)
        for (i0 = s[0]; i0 < e[0]+1; ++i0) {
            float lap = c0*uc[i1][i0] + c1[0]*(uc[i1][i0+1]+uc[i1][i0-1]) + c1
            [1]*(uc[i1+1][i0]+uc[i1-1][i0]) + c2[0]*(uc[i1][i0+2]+uc[i1][i0-2]
            ) + c2[1]*(uc[i1+2][i0]+uc[i1-2][i0]);
            float lapd0 = c0*ucd0[i1][i0] + c1[0]*(ucd0[i1][i0+1]+ucd0[i1][i0-
            1]) + c1[1]*(ucd0[i1+1][i0]+ucd0[i1-1][i0]) + c2[0]*(ucd0[i1][i0+2
            ]+ucd0[i1][i0-2]) + c2[1]*(ucd0[i1+2][i0]+ucd0[i1-2][i0]);
            float lapd = c0*ucd[i1][i0] + c1[0]*(ucd[i1][i0+1]+ucd[i1][i0-1]) 
            + c1[1]*(ucd[i1+1][i0]+ucd[i1-1][i0]) + c2[0]*(ucd[i1][i0+2]+ucd[
            i1][i0-2]) + c2[1]*(ucd[i1+2][i0]+ucd[i1-2][i0]);
            float lapdd = c0*ucdd[i1][i0] + c1[0]*(ucdd[i1][i0+1]+ucdd[i1][i0-
            1]) + c1[1]*(ucdd[i1+1][i0]+ucdd[i1-1][i0]) + c2[0]*(ucdd[i1][i0+2
            ]+ucdd[i1][i0-2]) + c2[1]*(ucdd[i1+2][i0]+ucdd[i1-2][i0]);
            updd[i1][i0] = 2.0*ucdd[i1][i0] - updd[i1][i0] + csqd[i1][i0]*
                lapd0 + csqd0[i1][i0]*lapd + csq[i1][i0]*lapdd;
            upd[i1][i0] = 2.0*ucd[i1][i0] - upd[i1][i0] + csqd[i1][i0]*lap + 
                csq[i1][i0]*lapd;
            upd0[i1][i0] = 2.0*ucd0[i1][i0] - upd0[i1][i0] + csqd0[i1][i0]*lap
                + csq[i1][i0]*lapd0;
            up[i1][i0] = 2.0*uc[i1][i0] - up[i1][i0] + csq[i1][i0]*lap;
        }
    /* boundary conditions - note that uc[-1][i]=0 etc. */
    if (lbc[1])
        for (i0 = s[0]; i0 < e[0]+1; ++i0) {
            updd[s[1] - 2][i0] = -updd[s[1]][i0];
            upd[s[1] - 2][i0] = -upd[s[1]][i0];
            upd0[s[1] - 2][i0] = -upd0[s[1]][i0];
            up[s[1] - 2][i0] = -up[s[1]][i0];
        }
    if (rbc[1])
        for (i0 = s[0]; i0 < e[0]+1; ++i0) {
            updd[e[1] + 2][i0] = -updd[e[1]][i0];
            upd[e[1] + 2][i0] = -upd[e[1]][i0];
            upd0[e[1] + 2][i0] = -upd0[e[1]][i0];
            up[e[1] + 2][i0] = -up[e[1]][i0];
        }
    if (lbc[0])
        for (i1 = s[1]; i1 < e[1]+1; ++i1) {
            updd[i1][s[0] - 2] = -updd[i1][s[0]];
            upd[i1][s[0] - 2] = -upd[i1][s[0]];
            upd0[i1][s[0] - 2] = -upd0[i1][s[0]];
            up[i1][s[0] - 2] = -up[i1][s[0]];
        }
    if (rbc[0])
        for (i1 = s[1]; i1 < e[1]+1; ++i1) {
            updd[i1][e[0] + 2] = -updd[i1][e[0]];
            upd[i1][e[0] + 2] = -upd[i1][e[0]];
            upd0[i1][e[0] + 2] = -upd0[i1][e[0]];
            up[i1][e[0] + 2] = -up[i1][e[0]];
        }
}
