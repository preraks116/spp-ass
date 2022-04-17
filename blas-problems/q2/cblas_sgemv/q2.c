#include <stdio.h>
#include <malloc.h>
#include "../../utils/cblas.h"
#include "../../utils/helper.h"
#include <time.h>
#include <stdlib.h>

// when i add an extra 0 to the dim sizes, i get the following error
/*
malloc(): corrupted top size
zsh: abort (core dumped)  ./q2
*/
#define DIM_SIZE_1 2000
#define DIM_SIZE_2 4000
#define DIM_SIZE_3 6000
#define DIM_SIZE_4 8000
#define DIM_SIZE_5 10000
#define DIM_SIZE_6 12000
#define DEFAULT_ALPHA 1.0
#define DEFAULT_BETA 1.0

void cblas_sgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N,const float alpha, const float *A, const int lda,const float *X, const int incX, const float beta,float *Y, const int incY)
{
    if(order == CblasRowMajor)
    {
        if(TransA == CblasNoTrans)
        {
            for(int i = 0; i < M; i++)
            {
                Y[i*incY] = beta * Y[i*incY];
                for(int j = 0; j < N; j++)
                {
                    Y[i*incY] += alpha * A[i*lda+j] * X[j*incX];
                }
            }
        }
        else if(TransA == CblasTrans)
        {
            for(int i = 0; i < M; i++)
            {
                Y[i*incY] = beta * Y[i*incY];
                for(int j = 0; j < N; j++)
                {
                    Y[i*incY] += alpha * A[j*lda+i] * X[j*incX];
                }
            }
        }
        else if(TransA == CblasConjTrans)
        {
            for(int i = 0; i < M; i++)
            {
                Y[i*incY] = beta * Y[i*incY];
                for(int j = 0; j < N; j++)
                {
                    Y[i*incY] += alpha * A[j*lda+i] * X[j*incX];
                }
            }
        }
    }
    else if(order == CblasColMajor)
    {
        if(TransA == CblasNoTrans)
        {
            for(int j = 0; j < M; j++)
            {
                Y[j*incY] = beta * Y[j*incY];
                for(int i = 0; i < N; i++)
                {
                    Y[j*incY] += alpha * A[i*lda+j] * X[i*incX];
                }
            }
        }
        else if(TransA == CblasTrans)
        {
            for(int j = 0; j < M; j++)
            {
                Y[j*incY] = beta * Y[j*incY];
                for(int i = 0; i < N; i++)
                {
                    Y[j*incY] += alpha * A[j*lda+i] * X[i*incX];
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int M = 2; //row
    int N = 3; //col

    struct timeval t;
    double* calctime = (double *)malloc(sizeof(double));
    float *X;
    float *Y;
    float *A;

    float alpha = DEFAULT_ALPHA;
    float beta = DEFAULT_BETA;

    if (argc > 1)
    {
        M = atoi(argv[1]);
        if(M == 1)
        {
            M = DIM_SIZE_1;
            N = DIM_SIZE_2;
        }
        else if(M == 2)
        {
            M = DIM_SIZE_2;
            N = DIM_SIZE_3;
        }
        else if(M == 3)
        {
            M = DIM_SIZE_3;
            N = DIM_SIZE_4;
        }
        else if(M == 4)
        {
            M = DIM_SIZE_4;
            N = DIM_SIZE_5;
        }
        else if(M == 5)
        {
            M = DIM_SIZE_5;
            N = DIM_SIZE_6;
        }
    }
    else
    {
        M = DIM_SIZE_5;
        N = DIM_SIZE_6;
    }
    

    // CblasRowMajor -> N > M
    // CblasColMajor -> M > N 

    X = (float *)malloc(N * sizeof(float));
    Y = (float *)malloc(M * sizeof(float));
    A = (float *)malloc(M * N * sizeof(float));

    // V = (double *)malloc(M * sizeof(double));
    // W = (double *)malloc(N * sizeof(double));
    // B = (double *)malloc(M * sizeof(double));

    RandomVectorFloat(N, X);
    RandomVectorFloat(M, Y);

    // RandomVectorDouble(M, V);
    // RandomVectorDouble(N, W);

    // for(int i=0; i < N; ++i) {
    //     X[i] = 1.0;
    // }
    // for(int i=0; i < M; ++i) {
    //     Y[i] = 1.0;
    // }


    RandomMatrixFloat(M, N, A);

    // RandomMatrixDouble(M, N, B);

    // for(int i=0; i < M; ++i) {
    //     for(int j=0; j < N; ++j) {
    //         A[i*N+j] = 1.0;
    //     }
    // }

        // print x and y
    // print dimensions
    
    // printf("X: ");
    // printVector(N, X);
    // printf("Y: ");
    // printVector(M, Y);
    // print alpha and beta
    // printf("alpha: %f\n", alpha);
    // printf("beta: %f\n", beta);
    // printf("A: \n");
    // PrintMatrix(M, N, A);

    tick(&t);

    cblas_sgemv(CblasRowMajor, CblasNoTrans, M, N, alpha, A, M, X, 1, beta, Y, 1);

    *calctime = tock(&t);

    free(X);
    printf("M: %d, N: %d\n", M, N);
    printf("Y: ");
    PrintVectorFloat(M, Y);
    free(Y);
    free(A);
    
    printf("Time: %f\n", *calctime * 1000);

    // tick(&t);

    // cblas_dgemv(CblasRowMajor, CblasNoTrans, M, N, alpha_d, B, M, V, 1, beta_d, W, 1);

    // *calctime += tock(&t);
    // printf("W: ");
    // PrintVectorDouble(N, W);
    // printf("Time: %f\n", *calctime * 1000);
    // // free 
    // free(V);
    // free(W);
    // free(B);

    // print y
    
    // printVector(M, Y);
    // free all the memory mallocd
    
}