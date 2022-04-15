#include <stdio.h>
#include <malloc.h>
#include "../utils/cblas.h"
#include "../utils/helper.h"
#include <time.h>
#include <stdlib.h>

#define DEFAULT_VECTOR_LENGTH 100000000 // million
#define DEFAULT_ALPHA 1.0

void cblas_sscal(const int N, const float alpha, float *A, const int incX)
{
    for(int i = 0; i < N; i++)
    {
        A[i*incX] = A[i*incX] * alpha;
    }
}

void cblas_dscal(const int N, const double alpha, double *A, const int incX)
{
    for(int i = 0; i < N; i++)
    {
        A[i*incX] = A[i*incX] * alpha;
    }
}

float cblas_sdot(const int N, const float  *A, const int incX, const float  *W, const int incY)
{
    float sum = 0.0;
    for(int i = 0; i < N; i++)
    {
        sum += A[i*incX] * W[i*incY];
    }
    return sum;
}

double cblas_ddot(const int N, const double *A, const int incX, const double *W, const int incY)
{
    double sum = 0.0;
    for(int i = 0; i < N; i++)
    {
        sum += A[i*incX] * W[i*incY];
    }
    return sum;
}

void cblas_saxpy(const int N, const float alpha, const float *A, const int incX, float *W, const int incY)
{
    for(int i = 0; i < N; i++)
    {
        W[i*incY] += alpha * A[i*incX];
    }
}

void cblas_daxpy(const int N, const double alpha, const double *A, const int incX, double *W, const int incY)
{
    for(int i = 0; i < N; i++)
    {
        W[i*incY] += alpha * A[i*incX];
    }
}

int main(int argc, char *argv[])
{   
    srand(time(0));
    
    struct timeval t;
    double calctime;
    float *A;
    float *B;
    double *W;
    double *X;
    int N;
    float alpha;

    if (argc > 1)
        N = atoi(argv[1]);
    else
        N = DEFAULT_VECTOR_LENGTH;
    
    if (argc > 2)
        alpha = atof(argv[2]);
    else
        alpha = DEFAULT_ALPHA;
    
    A = (float*)malloc(sizeof(float)*N);
    B = (float*)malloc(sizeof(float)*N);

    W = (double*)malloc(sizeof(double)*N);
    X = (double*)malloc(sizeof(double)*N);

    RandomVectorFloat(N, A);
    RandomVectorDouble(N, W);
    printf("LEVEL 1\n");
    printf("Iterations: %d\n", N);
    printf("Alpha: %f\n", alpha);
    printf("-------------------------------------------------------\n");
    printf("xSCAL:\n");
    tick(&t);

    cblas_sscal(N, alpha, A, 1);

    calctime = tock(&t);

    printf("sscal time: %f ms\n", calctime*1000);

    tick(&t);

    cblas_dscal(N, alpha, W, 1);

    calctime = tock(&t);

    printf("dscal time: %f ms\n", calctime*1000);

    printf("-------------------------------------------------------\n");
    printf("xDOT:\n");

    tick(&t);

    float dot = cblas_sdot(N, A, 1, B, 1);
    printf("dot: %f\n", dot);

    calctime = tock(&t);

    printf("sdot time: %f ms\n", calctime*1000);

    tick(&t);

    double dot2 = cblas_ddot(N, W, 1, X, 1);
    printf("dot2: %f\n", dot2);

    calctime = tock(&t);

    printf("ddot time: %f ms\n", calctime*1000);

    printf("-------------------------------------------------------\n");

    printf("xAXPY:\n");

    tick(&t);

    cblas_saxpy(N, alpha, A, 1, B, 1);

    calctime = tock(&t);

    printf("saxpy time: %f ms\n", calctime*1000);

    tick(&t);

    cblas_daxpy(N, alpha, W, 1, X, 1);

    calctime = tock(&t);

    printf("daxpy time: %f ms\n", calctime*1000);

    printf("-------------------------------------------------------\n");
}