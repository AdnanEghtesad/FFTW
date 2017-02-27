#include <cufft.h>
#include<time.h>
#include <sys/time.h> 

#include <stdio.h>
#include <math.h>

typedef float fftw_complex[2];

#include "fftw_test.c"

int main()
{
  static double acc_time;
  static int acc_n;
  
  static fftw_complex signal[NUM_POINTS];
  
  cufftHandle planc2c;
  cufftPlan1d(&planc2c, NUM_POINTS, CUFFT_C2C, 1);
  cufftSetCompatibilityMode(planc2c, CUFFT_COMPATIBILITY_NATIVE);

  acquire_from_somewhere(signal);
  //do_something_with(signal);

#pragma acc data copy(signal[0:NUM_POINTS][0:2])
  {
    struct timespec now, tmstart;
    clock_gettime(CLOCK_REALTIME, &tmstart);

#pragma acc host_data use_device(signal)
    {
      cufftExecC2C(planc2c, (cufftComplex *)signal, (cufftComplex *)signal, CUFFT_FORWARD);
    }

    clock_gettime(CLOCK_REALTIME, &now);
    acc_time += (now.tv_sec+now.tv_nsec*1e-9) - (tmstart.tv_sec+tmstart.tv_nsec*1e-9);
    acc_n++;
  }

  printf("avg CUFFT  avg time: %g total time %g\n", acc_time / acc_n, acc_time);
    
  do_something_with(signal);
  
  return 0;
}
