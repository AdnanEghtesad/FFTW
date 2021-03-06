#include <fftw3.h>
#include<time.h>
#include <sys/time.h> 

#include <stdio.h>
#include <math.h>

#include "fftw_test.c"


int main()
{
   double acc_time;
   int acc_n;
  
  
  fftw_complex signal[NUM_POINTS];
  fftw_complex result[NUM_POINTS];
  
  
  fftw_plan plan = fftw_plan_dft_3d(NUM_POINTS1,
				    NUM_POINTS2,
				    NUM_POINTS3,
				    signal,
				    result,
				    FFTW_FORWARD,
				    FFTW_ESTIMATE);
  
  acquire_from_somewhere(signal);
  //do_something_with(signal);
  struct timespec now, tmstart;
  clock_gettime(CLOCK_REALTIME, &tmstart);
  for (int i = 0; i < 1; i++) {
    fftw_execute(plan);
  }
  clock_gettime(CLOCK_REALTIME, &now);
  acc_time += (now.tv_sec+now.tv_nsec*1e-9) - (tmstart.tv_sec+tmstart.tv_nsec*1e-9);
  acc_n++;

  printf("avg FFTW  avg time: %g total time %g\n", acc_time / acc_n, acc_time);
  getchar();
    do_something_with(result);
  
  fftw_destroy_plan(plan);
  return 0;
}
