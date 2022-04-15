#define _XOPEN_SOURCE

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

void tick(struct timeval *t)
{
    gettimeofday(t, NULL);
}

double tock(struct timeval *t)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return(double) (now.tv_sec - t->tv_sec) + 
    ((double)(now.tv_usec - t->tv_usec)/1000000.);
}

void RandomVectorFloat(int n, float *A)
{
    for(int i=0; i < n; ++i) {
        A[i] = (float) rand()/RAND_MAX;
    }
}

void RandomVectorDouble(int n, double *A)
{
    for(int i=0; i < n; ++i) {
        A[i] = (double) (rand()/RAND_MAX);
    }
}

void printVector(int n, float *A)
{
    for(int i=0; i < n; ++i) {
        printf("%f ", A[i]);
    }
    printf("\n");
}