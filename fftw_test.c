
#define REAL 0
#define IMAG 1

#if 0
#define NUM_POINTS1 256
#define NUM_POINTS2 256
#define NUM_POINTS3 256
#else
#define NUM_POINTS1 8
#define NUM_POINTS2 1
#define NUM_POINTS3 1
#endif
#define NUM_POINTS (NUM_POINTS1*NUM_POINTS2*NUM_POINTS3)
void acquire_from_somewhere(fftw_complex* signal) {
    /* Generate two sine waves of different frequencies and
 *      * amplitudes.
 *           */
    int i;
    for (i = 0; i < NUM_POINTS; ++i) {
      double theta = (double)i / (double)(NUM_POINTS1) * 2.*M_PI;

#if 0
        signal[i][REAL] = 1.0 * cos(10.0 * theta) +
                          0.5 * cos(25.0 * theta);

        signal[i][IMAG] = 1.0 * sin(10.0 * theta) +
                          0.5 * sin(25.0 * theta);
#else
	signal[i][REAL] = 1.0 * cos(theta);
	signal[i][IMAG] = 0.0;
#endif
    }
}

void do_something_with(fftw_complex* result)
{
  int i;
  for (i = 0; i < NUM_POINTS; ++i) {
    printf("[%d] %g %g\n", i, result[i][REAL], result[i][IMAG]);
  }
}


