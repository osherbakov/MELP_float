/*

2.4 kbps MELP Proposed Federal Standard speech coder

version 1.2

Copyright (c) 1996, Texas Instruments, Inc.

Texas Instruments has intellectual property rights on the MELP
algorithm.  The Texas Instruments contact for licensing issues for
commercial and non-government use is William Gordon, Director,
Government Contracts, Texas Instruments Incorporated, Semiconductor
Group (phone 972 480 7442).

*/

/*

  dsp_sub.h: include file

*/



/* External function definitions */
void autocorr(float input[], float r[], int order, int npts);
void envelope(float input[], float prev_in, float output[], int npts);
void interp_array(float prev[],float curr[],float out[],float ifact,int size);
float median(float input[], int npts);
float peakiness(float input[], int npts);
void quant_u(float *p_data, int *p_index, float qmin, float qmax, int nlev);
void quant_u_dec(int index, float *p_data,float qmin, float qmax, int nlev);
void rand_num(float output[],float amplitude, int npts);

void polflt(float input[], const float coeff[], float output[], int order,int npts);
void iirflt(float input[], const float coeff[], float output[], float delay[], int order,int npts);

void zerflt(float input[], const float coeff[], float output[], int order,int npts);
void firflt(float input[], const float coeff[], float output[], float delay[], int order,int npts);

void firflt_f32(float input[], const float coeff[], float output[], int order,int npts);
void iirflt_f32(float input[], const float coeff[], float output[], int order,int npts);

void  pack_code(int code,unsigned int **p_ch_beg,int *p_ch_bit,int numbits,int size);
int unpack_code(unsigned int **p_ch_beg,int *p_ch_bit,int *p_code,int numbits,int wsize,unsigned int erase_mask);

