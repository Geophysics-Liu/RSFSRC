/*        Generated by TAPENADE     (INRIA, Tropics team)
    Tapenade 3.7 (r4786) - 21 Feb 2013 15:53
*/
#include "cstd.h"

extern void pushinteger4(int x);
extern void popinteger4(int *x);

/*
  Differentiation of acdpml_2d_2_d in reverse (adjoint) mode:
   gradient     of useful results: **ucd **phi0d **upd **uc **phi0
                **up **phi1d **phi1
   with respect to varying inputs: **ucd **phi0d **upd **csq **uc
                **phi0 **up **phi1d **phi1
   RW status of diff variables: **ucd:incr **phi0d:in-out **upd:in-out
                **csq:out **uc:incr **phi0:in-out **up:in-out
                **phi1d:in-out **phi1:in-out
   Plus diff mem management of: ucd:in *ucd:in phi0d:in *phi0d:in
                upd:in *upd:in csq:in *csq:in uc:in *uc:in phi0:in
                *phi0:in up:in *up:in phi1d:in *phi1d:in phi1:in
                *phi1:in


  Differentiation of acdpml_2d_2 in forward (tangent) mode:
   variations   of useful results: **phi0 **up **phi1
   with respect to varying inputs: **csq **uc **phi0 **up **phi1
   RW status of diff variables: **csq:in **uc:in **phi0:in-out
                **up:in-out **phi1:in-out
   Plus diff mem management of: csq:in *csq:in uc:in *uc:in phi0:in
                *phi0:in up:in *up:in phi1:in *phi1:in
*/
void acdpml_2d_2_d_b(float **uc, float **ucb, float **ucd, float **ucdb, float
        **up, float **upb, float **upd, float **updb, float **csq, float **
        csqb, float **csqd, float **phi1, float **phi1b, float **phi1d, float 
        **phi1db, float **phi0, float **phi0b, float **phi0d, float **phi0db, 
        float *dp1, float *dp0, float *di, float dt, int *s, int *e, float c0,
        float *c1, int *lbc, int *rbc) {
    /* current field
    // previous field
    // csq
    // phi1
    // phi0
    // damping profile zeta_x
    // damping profile zeta_x
    // start index
    // end index  */
    int i1, i0;
    float temp3;
    float temp2;
    float temp1;
    float temp0;
    float temp13b;
    float temp7b;
    float temp21b;
    float temp9b1;
    float temp22;
    float temp20b0;
    float temp9b0;
    float temp21;
    float temp20;
    float temp18b0;
    float temp16b;
    float tempb9;
    float tempb8;
    float temp4b0;
    float tempb7;
    float temp13b1;
    float tempb6;
    float temp13b0;
    float tempb5;
    float tempb4;
    float temp19b;
    float tempb3;
    float tempb2;
    float tempb1;
    float tempb0;
    float temp0b;
    float tempb11;
    float tempb10;
    float temp3b;
    float temp7b1;
    float temp7b0;
    float temp19;
    float temp18;
    float temp16b0;
    float temp17;
    float temp2b1;
    float temp12b;
    float temp16;
    float temp2b0;
    float temp6b;
    float temp15;
    float temp20b;
    float temp14;
    float temp11b1;
    float temp13;
    float temp11b0;
    float temp12;
    float temp11;
    float temp10;
    float temp15b;
    float temp9b;
    float temp21b1;
    float temp21b0;
    float temp18b;
    float temp19b1;
    float temp19b0;
    float temp5b1;
    float temp5b0;
    float tempb;
    float temp14b0;
    float temp0b1;
    float temp0b0;
    float temp2b;
    float temp11b;
    float temp5b;
    float temp8b0;
    float temp17b1;
    float temp17b0;
    float temp14b;
    float temp3b1;
    float temp8b;
    float temp22b;
    float temp3b0;
    float temp12b0;
    float temp17b;
    float temp22b0;
    float temp1b;
    float temp;
    float temp6b0;
    float temp15b1;
    float temp15b0;
    float temp1b2;
    float temp9;
    float temp1b1;
    float temp8;
    float temp1b0;
    float temp7;
    float temp10b;
    float temp6;
    float temp4b;
    float temp5;
    float temp10b0;
    float temp4;
    /* fprintf(stderr, "dp0[%d] = %f\n",e[0], dp0[e[0]]);
    // PML
    //fprintf(stderr, " after computing Du_x Du_z acdpml_2d_2!!!\n");
    // \phi separate loops along boundary !!!!!!!!!!!!!!!! csq and damp profile
    // compute interior of the domain
    // update wavefield up */
    for (i1 = s[1]; i1 < e[1]+1; ++i1)
        for (i0 = s[0]; i0 < e[0]+1; ++i0) {
            float lap = c0*uc[i1][i0] + c1[0]*(uc[i1][i0+1]+uc[i1][i0-1]) + c1
            [1]*(uc[i1+1][i0]+uc[i1-1][i0]);
            float lapd = c0*ucd[i1][i0] + c1[0]*(ucd[i1][i0+1]+ucd[i1][i0-1])
            + c1[1]*(ucd[i1+1][i0]+ucd[i1-1][i0]);
            float cff = 1.0/(1.0+(dp1[i1]+dp0[i0])*dt/2.0);
            float cffuc = (2.0-dp1[i1]*dp0[i0]*dt*dt)*cff;
            float cffup = ((dp1[i1]+dp0[i0])/2.0*dt-1.0)*cff;
            float cff1 = dt*dt/2.0/di[1]*cff;
            float cff0 = dt*dt/2.0/di[0]*cff;
            upd[i1][i0] = cffuc*ucd[i1][i0] + cffup*upd[i1][i0] +
                cff*(csqd[i1][i0]*lap+csq[i1][i0]*lapd) +
                cff1*(phi1d[i1][i0-1]+phi1d[i1][i0]-phi1d[i1-1][i0-1]-phi1d[i1-1][i0]) +
                cff0*(phi0d[i1-1][i0]+phi0d[i1][i0]-phi0d[i1-1][i0-1]-phi0d[i1][i0-1]);
            up[i1][i0] = cffuc*uc[i1][i0] + cffup*up[i1][i0] +
                cff*csq[i1][i0]*lap +
                cff1*(phi1[i1][i0-1]+phi1[i1][i0]-phi1[i1-1][i0-1]-phi1[i1-1][i0]) +
                cff0*(phi0[i1-1][i0]+phi0[i1][i0]-phi0[i1-1][i0-1]-phi0[i1][i0-1]);
        }
    pushinteger4(i0);
    pushinteger4(i1);
    pushinteger4(i0);
    /* compute i0=e[0] */
    i0 = e[0];
    pushinteger4(i1);
    /*  **csqb = 0.0; */
    for (i1 = e[1]-1; i1 > s[1]-1; --i1) {
        temp22 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp22b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
        temp22b0 = csq[i1][i0]*temp22b/temp22;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp22b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp22b0;
        ucb[i1][i0] = ucb[i1][i0] - temp22b0;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp22b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp22b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp22b0;
        upb[i1][i0] = upb[i1][i0] - temp22b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp22b0;
        csqb[i1][i0] = csqb[i1][i0] + (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-
            uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])*
            temp22b/temp22;
        phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
        temp21 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp21b = (dp1[i1]-dp0[i0])*dt*2.0*phi0db[i1][i0];
        temp21b0 = csq[i1][i0]*temp21b/temp21;
        temp21b1 = (dp1[i1]-dp0[i0])*dt*2.0*csqd[i1][i0]*phi0db[i1][i0]/(4.0*
            di[0]*(dt*dp0[i0]+2.0));
        ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] + temp21b0;
        ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp21b0;
        ucdb[i1][i0] = ucdb[i1][i0] - temp21b0;
        ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] - temp21b0;
        updb[i1][i0 + 1] = updb[i1][i0 + 1] + temp21b0;
        updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp21b0;
        updb[i1][i0] = updb[i1][i0] - temp21b0;
        updb[i1 + 1][i0] = updb[i1 + 1][i0] - temp21b0;
        csqb[i1][i0] = csqb[i1][i0] + (ucd[i1][i0+1]+ucd[i1+1][i0+1]-ucd[i1][
            i0]-ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1
            +1][i0])*temp21b/temp21;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp21b1;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp21b1;
        ucb[i1][i0] = ucb[i1][i0] - temp21b1;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp21b1;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp21b1;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp21b1;
        upb[i1][i0] = upb[i1][i0] - temp21b1;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp21b1;
        phi0db[i1][i0] = (2.0-dt*dp0[i0])*phi0db[i1][i0]/(dt*dp0[i0]+2.0);
        temp20 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp20b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
        temp20b0 = csq[i1][i0]*temp20b/temp20;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp20b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp20b0;
        ucb[i1][i0] = ucb[i1][i0] - temp20b0;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp20b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp20b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp20b0;
        upb[i1][i0] = upb[i1][i0] - temp20b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp20b0;
        csqb[i1][i0] = csqb[i1][i0] + (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-
            uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])*
            temp20b/temp20;
        phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
        temp19 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp19b = (dp0[i0]-dp1[i1])*dt*2.0*phi1db[i1][i0];
        temp19b0 = csq[i1][i0]*temp19b/temp19;
        temp19b1 = (dp0[i0]-dp1[i1])*dt*2.0*csqd[i1][i0]*phi1db[i1][i0]/(4.0*
            di[1]*(dt*dp1[i1]+2.0));
        ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] + temp19b0;
        ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp19b0;
        ucdb[i1][i0] = ucdb[i1][i0] - temp19b0;
        ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] - temp19b0;
        updb[i1 + 1][i0] = updb[i1 + 1][i0] + temp19b0;
        updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp19b0;
        updb[i1][i0] = updb[i1][i0] - temp19b0;
        updb[i1][i0 + 1] = updb[i1][i0 + 1] - temp19b0;
        csqb[i1][i0] = csqb[i1][i0] + (ucd[i1+1][i0]+ucd[i1+1][i0+1]-ucd[i1][
            i0]-ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1
            ][i0+1])*temp19b/temp19;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp19b1;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp19b1;
        ucb[i1][i0] = ucb[i1][i0] - temp19b1;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp19b1;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp19b1;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp19b1;
        upb[i1][i0] = upb[i1][i0] - temp19b1;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp19b1;
        phi1db[i1][i0] = (2.0-dt*dp1[i1])*phi1db[i1][i0]/(dt*dp1[i1]+2.0);
    }
    popinteger4(&i1);
    i1 = e[1];
    for (i0 = e[0]; i0 > s[0]-1; --i0) {
        temp18 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp18b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
        temp18b0 = csq[i1][i0]*temp18b/temp18;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp18b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp18b0;
        ucb[i1][i0] = ucb[i1][i0] - temp18b0;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp18b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp18b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp18b0;
        upb[i1][i0] = upb[i1][i0] - temp18b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp18b0;
        csqb[i1][i0] = csqb[i1][i0] + (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-
            uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])*
            temp18b/temp18;
        phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
        temp17 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp17b = (dp1[i1]-dp0[i0])*dt*2.0*phi0db[i1][i0];
        temp17b0 = csq[i1][i0]*temp17b/temp17;
        temp17b1 = (dp1[i1]-dp0[i0])*dt*2.0*csqd[i1][i0]*phi0db[i1][i0]/(4.0*
            di[0]*(dt*dp0[i0]+2.0));
        ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] + temp17b0;
        ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp17b0;
        ucdb[i1][i0] = ucdb[i1][i0] - temp17b0;
        ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] - temp17b0;
        updb[i1][i0 + 1] = updb[i1][i0 + 1] + temp17b0;
        updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp17b0;
        updb[i1][i0] = updb[i1][i0] - temp17b0;
        updb[i1 + 1][i0] = updb[i1 + 1][i0] - temp17b0;
        csqb[i1][i0] = csqb[i1][i0] + (ucd[i1][i0+1]+ucd[i1+1][i0+1]-ucd[i1][
            i0]-ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1
            +1][i0])*temp17b/temp17;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp17b1;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp17b1;
        ucb[i1][i0] = ucb[i1][i0] - temp17b1;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp17b1;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp17b1;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp17b1;
        upb[i1][i0] = upb[i1][i0] - temp17b1;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp17b1;
        phi0db[i1][i0] = (2.0-dt*dp0[i0])*phi0db[i1][i0]/(dt*dp0[i0]+2.0);
        temp16 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp16b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
        temp16b0 = csq[i1][i0]*temp16b/temp16;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp16b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp16b0;
        ucb[i1][i0] = ucb[i1][i0] - temp16b0;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp16b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp16b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp16b0;
        upb[i1][i0] = upb[i1][i0] - temp16b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp16b0;
        csqb[i1][i0] = csqb[i1][i0] + (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-
            uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])*
            temp16b/temp16;
        phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
        temp15 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp15b = (dp0[i0]-dp1[i1])*dt*2.0*phi1db[i1][i0];
        temp15b0 = csq[i1][i0]*temp15b/temp15;
        temp15b1 = (dp0[i0]-dp1[i1])*dt*2.0*csqd[i1][i0]*phi1db[i1][i0]/(4.0*
            di[1]*(dt*dp1[i1]+2.0));
        ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] + temp15b0;
        ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp15b0;
        ucdb[i1][i0] = ucdb[i1][i0] - temp15b0;
        ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] - temp15b0;
        updb[i1 + 1][i0] = updb[i1 + 1][i0] + temp15b0;
        updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp15b0;
        updb[i1][i0] = updb[i1][i0] - temp15b0;
        updb[i1][i0 + 1] = updb[i1][i0 + 1] - temp15b0;
        csqb[i1][i0] = csqb[i1][i0] + (ucd[i1+1][i0]+ucd[i1+1][i0+1]-ucd[i1][
            i0]-ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1
            ][i0+1])*temp15b/temp15;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp15b1;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp15b1;
        ucb[i1][i0] = ucb[i1][i0] - temp15b1;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp15b1;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp15b1;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp15b1;
        upb[i1][i0] = upb[i1][i0] - temp15b1;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp15b1;
        phi1db[i1][i0] = (2.0-dt*dp1[i1])*phi1db[i1][i0]/(dt*dp1[i1]+2.0);
    }
    popinteger4(&i0);
    i0 = s[0] - 1;
    for (i1 = e[1]; i1 > s[1]-1; --i1) {
        temp14 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp14b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
        temp14b0 = csq[i1][i0+1]*temp14b/temp14;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp14b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp14b0;
        ucb[i1][i0] = ucb[i1][i0] - temp14b0;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp14b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp14b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp14b0;
        upb[i1][i0] = upb[i1][i0] - temp14b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp14b0;
        csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[
            i1][i0]-uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+
            1][i0])*temp14b/temp14;
        phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
        temp13 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp13b = (dp1[i1]-dp0[i0])*dt*2.0*phi0db[i1][i0];
        temp13b0 = csq[i1][i0+1]*temp13b/temp13;
        temp13b1 = (dp1[i1]-dp0[i0])*dt*2.0*csqd[i1][i0+1]*phi0db[i1][i0]/(4.0
            *di[0]*(dt*dp0[i0]+2.0));
        ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] + temp13b0;
        ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp13b0;
        ucdb[i1][i0] = ucdb[i1][i0] - temp13b0;
        ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] - temp13b0;
        updb[i1][i0 + 1] = updb[i1][i0 + 1] + temp13b0;
        updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp13b0;
        updb[i1][i0] = updb[i1][i0] - temp13b0;
        updb[i1 + 1][i0] = updb[i1 + 1][i0] - temp13b0;
        csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + (ucd[i1][i0+1]+ucd[i1+1][i0+1]-
            ucd[i1][i0]-ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0
            ]-upd[i1+1][i0])*temp13b/temp13;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp13b1;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp13b1;
        ucb[i1][i0] = ucb[i1][i0] - temp13b1;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp13b1;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp13b1;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp13b1;
        upb[i1][i0] = upb[i1][i0] - temp13b1;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp13b1;
        phi0db[i1][i0] = (2.0-dt*dp0[i0])*phi0db[i1][i0]/(dt*dp0[i0]+2.0);
        temp12 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp12b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
        temp12b0 = csq[i1][i0+1]*temp12b/temp12;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp12b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp12b0;
        ucb[i1][i0] = ucb[i1][i0] - temp12b0;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp12b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp12b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp12b0;
        upb[i1][i0] = upb[i1][i0] - temp12b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp12b0;
        csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[
            i1][i0]-uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1]
            [i0+1])*temp12b/temp12;
        phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
        temp11 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp11b = (dp0[i0]-dp1[i1])*dt*2.0*phi1db[i1][i0];
        temp11b0 = csq[i1][i0+1]*temp11b/temp11;
        temp11b1 = (dp0[i0]-dp1[i1])*dt*2.0*csqd[i1][i0+1]*phi1db[i1][i0]/(4.0
            *di[1]*(dt*dp1[i1]+2.0));
        ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] + temp11b0;
        ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp11b0;
        ucdb[i1][i0] = ucdb[i1][i0] - temp11b0;
        ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] - temp11b0;
        updb[i1 + 1][i0] = updb[i1 + 1][i0] + temp11b0;
        updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp11b0;
        updb[i1][i0] = updb[i1][i0] - temp11b0;
        updb[i1][i0 + 1] = updb[i1][i0 + 1] - temp11b0;
        csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + (ucd[i1+1][i0]+ucd[i1+1][i0+1]-
            ucd[i1][i0]-ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0
            ]-upd[i1][i0+1])*temp11b/temp11;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp11b1;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp11b1;
        ucb[i1][i0] = ucb[i1][i0] - temp11b1;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp11b1;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp11b1;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp11b1;
        upb[i1][i0] = upb[i1][i0] - temp11b1;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp11b1;
        phi1db[i1][i0] = (2.0-dt*dp1[i1])*phi1db[i1][i0]/(dt*dp1[i1]+2.0);
    }
    popinteger4(&i1);
    i1 = s[1] - 1;
    for (i0 = e[0]; i0 > s[0]-1; --i0) {
        temp10 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp10b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
        temp10b0 = csq[i1+1][i0]*temp10b/temp10;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp10b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp10b0;
        ucb[i1][i0] = ucb[i1][i0] - temp10b0;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp10b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp10b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp10b0;
        upb[i1][i0] = upb[i1][i0] - temp10b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp10b0;
        csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[
            i1][i0]-uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+
            1][i0])*temp10b/temp10;
        phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
        temp9 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp9b = (dp1[i1]-dp0[i0])*dt*2.0*phi0db[i1][i0];
        temp9b0 = csq[i1+1][i0]*temp9b/temp9;
        temp9b1 = (dp1[i1]-dp0[i0])*dt*2.0*csqd[i1+1][i0]*phi0db[i1][i0]/(4.0*
            di[0]*(dt*dp0[i0]+2.0));
        ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] + temp9b0;
        ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp9b0;
        ucdb[i1][i0] = ucdb[i1][i0] - temp9b0;
        ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] - temp9b0;
        updb[i1][i0 + 1] = updb[i1][i0 + 1] + temp9b0;
        updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp9b0;
        updb[i1][i0] = updb[i1][i0] - temp9b0;
        updb[i1 + 1][i0] = updb[i1 + 1][i0] - temp9b0;
        csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + (ucd[i1][i0+1]+ucd[i1+1][i0+1]-
            ucd[i1][i0]-ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0
            ]-upd[i1+1][i0])*temp9b/temp9;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp9b1;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp9b1;
        ucb[i1][i0] = ucb[i1][i0] - temp9b1;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp9b1;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp9b1;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp9b1;
        upb[i1][i0] = upb[i1][i0] - temp9b1;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp9b1;
        phi0db[i1][i0] = (2.0-dt*dp0[i0])*phi0db[i1][i0]/(dt*dp0[i0]+2.0);
        temp8 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp8b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
        temp8b0 = csq[i1+1][i0]*temp8b/temp8;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp8b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp8b0;
        ucb[i1][i0] = ucb[i1][i0] - temp8b0;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp8b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp8b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp8b0;
        upb[i1][i0] = upb[i1][i0] - temp8b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp8b0;
        csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[
            i1][i0]-uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1]
            [i0+1])*temp8b/temp8;
        phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
        temp7 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp7b = (dp0[i0]-dp1[i1])*dt*2.0*phi1db[i1][i0];
        temp7b0 = csq[i1+1][i0]*temp7b/temp7;
        temp7b1 = (dp0[i0]-dp1[i1])*dt*2.0*csqd[i1+1][i0]*phi1db[i1][i0]/(4.0*
            di[1]*(dt*dp1[i1]+2.0));
        ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] + temp7b0;
        ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp7b0;
        ucdb[i1][i0] = ucdb[i1][i0] - temp7b0;
        ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] - temp7b0;
        updb[i1 + 1][i0] = updb[i1 + 1][i0] + temp7b0;
        updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp7b0;
        updb[i1][i0] = updb[i1][i0] - temp7b0;
        updb[i1][i0 + 1] = updb[i1][i0 + 1] - temp7b0;
        csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + (ucd[i1+1][i0]+ucd[i1+1][i0+1]-
            ucd[i1][i0]-ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0
            ]-upd[i1][i0+1])*temp7b/temp7;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp7b1;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp7b1;
        ucb[i1][i0] = ucb[i1][i0] - temp7b1;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp7b1;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp7b1;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp7b1;
        upb[i1][i0] = upb[i1][i0] - temp7b1;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp7b1;
        phi1db[i1][i0] = (2.0-dt*dp1[i1])*phi1db[i1][i0]/(dt*dp1[i1]+2.0);
    }
    popinteger4(&i0);
    i0 = s[0] - 1;
    i1 = s[1] - 1;
    temp6 = 4.0*di[0]*(dt*dp0[i0]+2.0);
    temp6b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
    temp6b0 = csq[i1+1][i0+1]*temp6b/temp6;
    ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp6b0;
    ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp6b0;
    ucb[i1][i0] = ucb[i1][i0] - temp6b0;
    ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp6b0;
    upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp6b0;
    upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp6b0;
    upb[i1][i0] = upb[i1][i0] - temp6b0;
    upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp6b0;
    csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + (uc[i1][i0+1]+uc[i1+1][i0+1]
        -uc[i1][i0]-uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+
        1][i0])*temp6b/temp6;
    phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
    temp5 = 4.0*di[0]*(dt*dp0[i0]+2.0);
    temp5b = (dp1[i1]-dp0[i0])*dt*2.0*phi0db[i1][i0];
    temp5b0 = csq[i1+1][i0+1]*temp5b/temp5;
    temp5b1 = (dp1[i1]-dp0[i0])*dt*2.0*csqd[i1+1][i0+1]*phi0db[i1][i0]/(4.0*di
        [0]*(dt*dp0[i0]+2.0));
    ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] + temp5b0;
    ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp5b0;
    ucdb[i1][i0] = ucdb[i1][i0] - temp5b0;
    ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] - temp5b0;
    updb[i1][i0 + 1] = updb[i1][i0 + 1] + temp5b0;
    updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp5b0;
    updb[i1][i0] = updb[i1][i0] - temp5b0;
    updb[i1 + 1][i0] = updb[i1 + 1][i0] - temp5b0;
    csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + (ucd[i1][i0+1]+ucd[i1+1][i0+
        1]-ucd[i1][i0]-ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0]
        -upd[i1+1][i0])*temp5b/temp5;
    ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp5b1;
    ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp5b1;
    ucb[i1][i0] = ucb[i1][i0] - temp5b1;
    ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp5b1;
    upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp5b1;
    upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp5b1;
    upb[i1][i0] = upb[i1][i0] - temp5b1;
    upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp5b1;
    phi0db[i1][i0] = (2.0-dt*dp0[i0])*phi0db[i1][i0]/(dt*dp0[i0]+2.0);
    temp4 = 4.0*di[1]*(dt*dp1[i1]+2.0);
    temp4b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
    temp4b0 = csq[i1+1][i0+1]*temp4b/temp4;
    ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp4b0;
    ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp4b0;
    ucb[i1][i0] = ucb[i1][i0] - temp4b0;
    ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp4b0;
    upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp4b0;
    upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp4b0;
    upb[i1][i0] = upb[i1][i0] - temp4b0;
    upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp4b0;
    csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + (uc[i1+1][i0]+uc[i1+1][i0+1]
        -uc[i1][i0]-uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1]
        [i0+1])*temp4b/temp4;
    phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
    temp3 = 4.0*di[1]*(dt*dp1[i1]+2.0);
    temp3b = (dp0[i0]-dp1[i1])*dt*2.0*phi1db[i1][i0];
    temp3b0 = csq[i1+1][i0+1]*temp3b/temp3;
    temp3b1 = (dp0[i0]-dp1[i1])*dt*2.0*csqd[i1+1][i0+1]*phi1db[i1][i0]/(4.0*di
        [1]*(dt*dp1[i1]+2.0));
    ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] + temp3b0;
    ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp3b0;
    ucdb[i1][i0] = ucdb[i1][i0] - temp3b0;
    ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] - temp3b0;
    updb[i1 + 1][i0] = updb[i1 + 1][i0] + temp3b0;
    updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp3b0;
    updb[i1][i0] = updb[i1][i0] - temp3b0;
    updb[i1][i0 + 1] = updb[i1][i0 + 1] - temp3b0;
    csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + (ucd[i1+1][i0]+ucd[i1+1][i0+
        1]-ucd[i1][i0]-ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0]
        -upd[i1][i0+1])*temp3b/temp3;
    ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp3b1;
    ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp3b1;
    ucb[i1][i0] = ucb[i1][i0] - temp3b1;
    ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp3b1;
    upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp3b1;
    upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp3b1;
    upb[i1][i0] = upb[i1][i0] - temp3b1;
    upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp3b1;
    phi1db[i1][i0] = (2.0-dt*dp1[i1])*phi1db[i1][i0]/(dt*dp1[i1]+2.0);
    for (i1 = e[1]-1; i1 > s[1]-1; --i1)
        for (i0 = e[0]-1; i0 > s[0]-1; --i0) {
            temp2 = 4.0*4.0*di[0]*(dt*dp0[i0]+2.0);
            temp2b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
            temp2b0 = (csq[i1][i0]+csq[i1+1][i0]+csq[i1][i0+1]+csq[i1+1][i0+1]
                )*temp2b/temp2;
            temp2b1 = (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1+1][i0]+up[
                i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])*temp2b/temp2
            ;
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp2b0;
            ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp2b0;
            ucb[i1][i0] = ucb[i1][i0] - temp2b0;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp2b0;
            upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp2b0;
            upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp2b0;
            upb[i1][i0] = upb[i1][i0] - temp2b0;
            upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp2b0;
            csqb[i1][i0] = csqb[i1][i0] + temp2b1;
            csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + temp2b1;
            csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + temp2b1;
            csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + temp2b1;
            phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
            temp1 = 4.0*di[0]*(dt*dp0[i0]+2.0);
            temp1b = (dp1[i1]-dp0[i0])*dt*2.0*phi0db[i1][i0]/4.0;
            temp1b0 = (csq[i1][i0]+csq[i1+1][i0]+csq[i1][i0+1]+csq[i1+1][i0+1]
                )*temp1b/temp1;
            temp1b1 = (ucd[i1][i0+1]+ucd[i1+1][i0+1]-ucd[i1][i0]-ucd[i1+1][i0]
                +upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1+1][i0])*
                temp1b/temp1;
            temp1b2 = (dp1[i1]-dp0[i0])*dt*2.0*(csqd[i1][i0]+csqd[i1+1][i0]+
                csqd[i1][i0+1]+csqd[i1+1][i0+1])*phi0db[i1][i0]/(4.0*4.0*di[0]
                *(dt*dp0[i0]+2.0));
            ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] + temp1b0;
            ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + temp1b0;
            ucdb[i1][i0] = ucdb[i1][i0] - temp1b0;
            ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] - temp1b0;
            updb[i1][i0 + 1] = updb[i1][i0 + 1] + temp1b0;
            updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + temp1b0;
            updb[i1][i0] = updb[i1][i0] - temp1b0;
            updb[i1 + 1][i0] = updb[i1 + 1][i0] - temp1b0;
            csqb[i1][i0] = csqb[i1][i0] + temp1b1;
            csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + temp1b1;
            csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + temp1b1;
            csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + temp1b1;
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp1b2;
            ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp1b2;
            ucb[i1][i0] = ucb[i1][i0] - temp1b2;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp1b2;
            upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp1b2;
            upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp1b2;
            upb[i1][i0] = upb[i1][i0] - temp1b2;
            upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp1b2;
            phi0db[i1][i0] = (2.0-dt*dp0[i0])*phi0db[i1][i0]/(dt*dp0[i0]+2.0);
            temp0 = 4.0*4.0*di[1]*(dt*dp1[i1]+2.0);
            temp0b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
            temp0b0 = (csq[i1][i0]+csq[i1+1][i0]+csq[i1][i0+1]+csq[i1+1][i0+1]
                )*temp0b/temp0;
            temp0b1 = (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1][i0+1]+up[
                i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])*temp0b/temp0
            ;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp0b0;
            ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp0b0;
            ucb[i1][i0] = ucb[i1][i0] - temp0b0;
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp0b0;
            upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp0b0;
            upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp0b0;
            upb[i1][i0] = upb[i1][i0] - temp0b0;
            upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp0b0;
            csqb[i1][i0] = csqb[i1][i0] + temp0b1;
            csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + temp0b1;
            csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + temp0b1;
            csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + temp0b1;
            phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
            temp = 4.0*di[1]*(dt*dp1[i1]+2.0);
            tempb8 = (dp0[i0]-dp1[i1])*dt*2.0*phi1db[i1][i0]/4.0;
            tempb9 = (csq[i1][i0]+csq[i1+1][i0]+csq[i1][i0+1]+csq[i1+1][i0+1])
                *tempb8/temp;
            tempb10 = (ucd[i1+1][i0]+ucd[i1+1][i0+1]-ucd[i1][i0]-ucd[i1][i0+1]
                +upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1][i0+1])*
                tempb8/temp;
            tempb11 = (dp0[i0]-dp1[i1])*dt*2.0*(csqd[i1][i0]+csqd[i1+1][i0]+
                csqd[i1][i0+1]+csqd[i1+1][i0+1])*phi1db[i1][i0]/(4.0*4.0*di[1]
                *(dt*dp1[i1]+2.0));
            ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] + tempb9;
            ucdb[i1 + 1][i0 + 1] = ucdb[i1 + 1][i0 + 1] + tempb9;
            ucdb[i1][i0] = ucdb[i1][i0] - tempb9;
            ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] - tempb9;
            updb[i1 + 1][i0] = updb[i1 + 1][i0] + tempb9;
            updb[i1 + 1][i0 + 1] = updb[i1 + 1][i0 + 1] + tempb9;
            updb[i1][i0] = updb[i1][i0] - tempb9;
            updb[i1][i0 + 1] = updb[i1][i0 + 1] - tempb9;
            csqb[i1][i0] = csqb[i1][i0] + tempb10;
            csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + tempb10;
            csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + tempb10;
            csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + tempb10;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + tempb11;
            ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + tempb11;
            ucb[i1][i0] = ucb[i1][i0] - tempb11;
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - tempb11;
            upb[i1 + 1][i0] = upb[i1 + 1][i0] + tempb11;
            upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + tempb11;
            upb[i1][i0] = upb[i1][i0] - tempb11;
            upb[i1][i0 + 1] = upb[i1][i0 + 1] - tempb11;
            phi1db[i1][i0] = (2.0-dt*dp1[i1])*phi1db[i1][i0]/(dt*dp1[i1]+2.0);
        }
    for (i1 = e[1]; i1 > s[1]-1; --i1)
        for (i0 = e[0]; i0 > s[0]-1; --i0) {
            tempb = upb[i1][i0]/((dp1[i1]+dp0[i0])*(dt/2.0)+1.0);
            tempb0 = csq[i1][i0]*tempb;
            tempb1 = dt*dt*tempb/(2.0*di[1]);
            tempb2 = dt*dt*tempb/(2.0*di[0]);
            ucb[i1][i0] = ucb[i1][i0] + c0*tempb0 + (2.0-dp1[i1]*dp0[i0]*(dt*
                dt))*tempb;
            csqb[i1][i0] = csqb[i1][i0] + (c0*uc[i1][i0]+c1[0]*(uc[i1][i0+1]+
                uc[i1][i0-1])+c1[1]*(uc[i1+1][i0]+uc[i1-1][i0]))*tempb;
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + c1[0]*tempb0;
            ucb[i1][i0 - 1] = ucb[i1][i0 - 1] + c1[0]*tempb0;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + c1[1]*tempb0;
            ucb[i1 - 1][i0] = ucb[i1 - 1][i0] + c1[1]*tempb0;
            phi1b[i1][i0 - 1] = phi1b[i1][i0 - 1] + tempb1;
            phi1b[i1][i0] = phi1b[i1][i0] + tempb1;
            phi1b[i1 - 1][i0 - 1] = phi1b[i1 - 1][i0 - 1] - tempb1;
            phi1b[i1 - 1][i0] = phi1b[i1 - 1][i0] - tempb1;
            phi0b[i1 - 1][i0] = phi0b[i1 - 1][i0] + tempb2;
            phi0b[i1][i0] = phi0b[i1][i0] + tempb2;
            phi0b[i1 - 1][i0 - 1] = phi0b[i1 - 1][i0 - 1] - tempb2;
            phi0b[i1][i0 - 1] = phi0b[i1][i0 - 1] - tempb2;
            upb[i1][i0] = ((dp1[i1]+dp0[i0])*(dt/2.0)-1.0)*tempb;
            tempb3 = updb[i1][i0]/((dp1[i1]+dp0[i0])*(dt/2.0)+1.0);
            tempb4 = csqd[i1][i0]*tempb3;
            tempb5 = csq[i1][i0]*tempb3;
            tempb6 = dt*dt*tempb3/(2.0*di[1]);
            tempb7 = dt*dt*tempb3/(2.0*di[0]);
            ucdb[i1][i0] = ucdb[i1][i0] + c0*tempb5 + (2.0-dp1[i1]*dp0[i0]*(dt
                *dt))*tempb3;
            ucb[i1][i0] = ucb[i1][i0] + c0*tempb4;
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + c1[0]*tempb4;
            ucb[i1][i0 - 1] = ucb[i1][i0 - 1] + c1[0]*tempb4;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + c1[1]*tempb4;
            ucb[i1 - 1][i0] = ucb[i1 - 1][i0] + c1[1]*tempb4;
            csqb[i1][i0] = csqb[i1][i0] + (c0*ucd[i1][i0]+c1[0]*(ucd[i1][i0+1]
                +ucd[i1][i0-1])+c1[1]*(ucd[i1+1][i0]+ucd[i1-1][i0]))*tempb3;
            ucdb[i1][i0 + 1] = ucdb[i1][i0 + 1] + c1[0]*tempb5;
            ucdb[i1][i0 - 1] = ucdb[i1][i0 - 1] + c1[0]*tempb5;
            ucdb[i1 + 1][i0] = ucdb[i1 + 1][i0] + c1[1]*tempb5;
            ucdb[i1 - 1][i0] = ucdb[i1 - 1][i0] + c1[1]*tempb5;
            phi1db[i1][i0 - 1] = phi1db[i1][i0 - 1] + tempb6;
            phi1db[i1][i0] = phi1db[i1][i0] + tempb6;
            phi1db[i1 - 1][i0 - 1] = phi1db[i1 - 1][i0 - 1] - tempb6;
            phi1db[i1 - 1][i0] = phi1db[i1 - 1][i0] - tempb6;
            phi0db[i1 - 1][i0] = phi0db[i1 - 1][i0] + tempb7;
            phi0db[i1][i0] = phi0db[i1][i0] + tempb7;
            phi0db[i1 - 1][i0 - 1] = phi0db[i1 - 1][i0 - 1] - tempb7;
            phi0db[i1][i0 - 1] = phi0db[i1][i0 - 1] - tempb7;
            updb[i1][i0] = ((dp1[i1]+dp0[i0])*(dt/2.0)-1.0)*tempb3;
        }
}
