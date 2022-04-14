#include <stdio.h>
#include <malloc.h>
#include "../utils/cblas.h"
#include "../utils/helper.h"
#include <time.h>
#include <stdlib.h>

#define DEFAULT_VECTOR_LENGTH 100000000 // million
#define DEFAULT_ALPHA 1.0

void cblas_sscal(const int N, const float alpha, float *X, const int incX)
{
    for(int i = 0; i < N; i++)
    {
        X[i*incX] = X[i*incX] * alpha;
    }
}

int main(int argc, char *argv[])
{   
    srand(time(0));
    
    struct timeval t;
    double calctime;
    float *X, *Y;
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
    
    X = (float*)malloc(sizeof(float)*N);

    RandomVector(N, X);

    tick(&t);

    cblas_sscal(N, 2.0, X, 1);

    calctime = tock(&t);

    printf("time: %f ms\n", calctime*1000);

    // int N; 
    // float alpha;
    // printf("Enter size of vector X: ");
    // scanf("%d", &N);
    // float* X = malloc(sizeof(float)*N);
    // genX(N, X);
    // printf("X: ");
    // for(int i = 0; i < N; i++)
    // {
    //     printf("%f ", X[i]);
    // }
    // printf("\nEnter alpha: ");
    // scanf("%f",&alpha);
    // cblas_sscal(N, alpha, X, 1);
    // printf("After multiplication\n");
    // printf("X: ");
    // for(int i = 0; i < N; i++)
    // {
    //     printf("%f ", X[i]);
    // }
    // printf("\n");
}