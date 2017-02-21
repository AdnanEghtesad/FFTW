
#include "fourn1d.h"
#include "fourn.h"

#include<time.h>

/* Never mind this bit */

#include <stdio.h>
#include <math.h>
 
//  static double acc_time;
//  static int acc_n;
//  struct timespec now, tmstart;
//  clock_gettime(CLOCK_REALTIME, &tmstart);


typedef float fftw_complex[2];

#include "fftw_test.c"

int main()
{
    static double acc_time;
    static int acc_n;

    static fftw_complex signal[NUM_POINTS];
    int nn[4] = { NUM_POINTS1, NUM_POINTS1,NUM_POINTS2, NUM_POINTS3};
    
 //   static float data[2*NUM_POINTS];
    
    
    acquire_from_somewhere(signal);
    
 //   for(int i=0;i<NUM_POINTS;i++)
    
 //   {
 //     data[i]=signal[i][REAL];
       
    
 //   }  
    //printf("%g %g %g \n",signal[0][0],signal[1][0],signal[2][0]);

  //      do_something_with(signal);

    struct timespec now, tmstart;
    clock_gettime(CLOCK_REALTIME, &tmstart);

    for (int i = 0; i < 1; i++) {
      fourn(&signal[0][REAL] -1 , nn, 3,   -1);
   //     four1(&signal[0][REAL]-1 , NUM_POINTS, 1);
    }
    clock_gettime(CLOCK_REALTIME, &now);
    acc_time += (now.tv_sec+now.tv_nsec*1e-9) - (tmstart.tv_sec+tmstart.tv_nsec*1e-9);
    acc_n++;

        do_something_with(signal);

    printf("avg fourn  avg time: %g total time %g\n", acc_time / acc_n, acc_time);
    
    return 0;


}
