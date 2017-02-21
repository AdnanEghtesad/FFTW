
CC = pgcc
CFLAGS = -tp=p7 -fast

LOADLIBES = -lfftw3 -lrt

all: FFTW_git FFT_fourn

FFT_fourn: FFT_fourn.o fourn.o

FFT_fourn.o: FFT_fourn.c fftw_test.c

FFTW_git.o: FFTW_git.c fftw_test.c

clean:
	rm -f FFTW_git FFT_fourn *.o



