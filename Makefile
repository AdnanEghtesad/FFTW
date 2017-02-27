
CC = pgcc
CFLAGS = -tp=p7  -fast -Mlarge_arrays

LOADLIBES = -lfftw3 -lrt


    #### FOR 1D #####

#all: FFTW_git FFT_fourn

#FFT_fourn: FFT_fourn.o fourn.o

#FFT_fourn.o: FFT_fourn.c fftw_test.c

#FFTW_git.o: FFTW_git.c fftw_test.c

#clean:
#	rm -f FFTW_git FFT_fourn *.o

   
    #### FOR 3D #####

all: FFTW_git_3d FFT_fourn_3d FFT_fourn FFTW_git FFT_cufft

FFT_fourn: FFT_fourn.o fourn.o

FFTW_git: FFTW_git.o fourn.o

FFT_cufft: FFT_cufft.o fourn.o
	pgcc -acc -fast -tp=p7  -Minfo=accel -Mcudalib=cufft -ta=tesla  -ta=tesla -lrt $^ -o $@

FFT_fourn_3d: FFT_fourn_3d.o fourn.o

FFT_fourn.o: FFT_fourn.c fftw_test.c

FFTW_git.o: FFTW_git.c fftw_test.c

FFT_cufft.o: FFT_cufft.c fftw_test.c
	pgcc -acc -fast -tp=p7  -Minfo=accel -Mcudalib=cufft -ta=tesla  -ta=tesla -lrt -c $<

FFT_fourn_3d.o: FFT_fourn_3d.c fftw_test.c

FFTW_git_3d.o: FFTW_git_3d.c fftw_test.c

clean:
	rm -f FFTW_git_3d FFT_fourn_3d *.o