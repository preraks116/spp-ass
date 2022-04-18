#include <stdio.h>
#include <sys/time.h>
#include <malloc.h>
#include "helper.h"

int main()
{
    struct timeval t;
    double calctime;

    double *X = (double *)malloc(sizeof(double) * 10000000);
    double *Y = (double *)malloc(sizeof(double) * 10000000);
    
    RandomVectorDouble(10000000, X);
    RandomVectorDouble(10000000, Y);

    double sum = 0;
    tick(&t);
    #pragma omp parallel for
    for(int i = 0; i < 10000000; i++)
    {
        sum += X[i] - Y[i];
    }

    calctime = tock(&t);

    printf("time: %f ms\n", calctime*1000);
    printf("sum: %f\n", sum);
    printf("Memory Bandwidth: %f\n", (10000000 * 2 * sizeof(double)) / (calctime * 1000 * 1000 * 1000));

}