#include <stdio.h>
#include <malloc.h>
#include "../../utils/cblas.h"
#include "../../utils/helper.h"
#include <time.h>
#include <stdlib.h>

#define rowA(i) &A[(i)*lda]
#define colB(j) &B[(j)]
#define phiC(i,j) C[(i)*ldc + (j)]

#define DIM_SIZE_1 200
#define DIM_SIZE_2 400
#define DIM_SIZE_3 600
#define DIM_SIZE_4 800
#define DIM_SIZE_5 1000
#define DIM_SIZE_6 1200
#define DIM_SIZE_7 1400
#define DIM_SIZE_8 1600
#define DIM_SIZE_9 1800
#define DIM_SIZE_10 2000
#define DIM_SIZE_11 2200
#define DIM_SIZE_12 2400

#define DEFAULT_ALPHA 1.0
#define DEFAULT_BETA 1.0

float cblas_sdot(const int N, const float  *A, const int incX, const float  *W, const int incY)
{
    float sum = 0.0;
    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < N; i++)
    {
        sum += A[i*incX] * W[i*incY];
    }
    return sum;
}

void cblas_sgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
    #pragma omp parallel for
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            phiC(i,j) += cblas_sdot(K, rowA(i), 1, colB(j), ldb);
            phiC(i,j) *= alpha;
        }
    }
}


int main(int argc, char *argv[])
{
    // dimensions of C - M x N
    // dimensions of A - M x K
    // dimensions of B - K x N
    int M = 1; // row
    int K = 4; // col
    int N = 2; // col

    struct timeval t;
    double *calctime = (double *)malloc(sizeof(double));
    float *C;
    float *A;
    float *B;

    float alpha = DEFAULT_ALPHA;
    float beta = DEFAULT_BETA;

    if (argc > 1)
    {
        M = atoi(argv[1]);
        if (M == 1)
        {
            M = DIM_SIZE_1;
            K = DIM_SIZE_2;
            N = DIM_SIZE_3;
        }
        else if (M == 2)
        {
            M = DIM_SIZE_3;
            K = DIM_SIZE_4;
            N = DIM_SIZE_5;
        }
        else if (M == 3)
        {
            M = DIM_SIZE_5;
            K = DIM_SIZE_6;
            N = DIM_SIZE_7;
        }
        else if (M == 4)
        {
            M = DIM_SIZE_7;
            K = DIM_SIZE_8;
            N = DIM_SIZE_9;
        }
        else if (M == 5)
        {
            M = DIM_SIZE_10;
            K = DIM_SIZE_11;
            N = DIM_SIZE_12;
        }
    }
    else
    {
        // M = DIM_SIZE_10;
        // K = DIM_SIZE_11;
        // N = DIM_SIZE_12;
    }

    // CblasRowMajor -> N > M
    // CblasColMajor -> M > N

    C = (float *)malloc(M * N * sizeof(float));
    A = (float *)malloc(M * K * sizeof(float));
    B = (float *)malloc(K * N * sizeof(float));

    // V = (double *)malloc(M * sizeof(double));
    // W = (double *)malloc(N * sizeof(double));
    // B = (double *)malloc(M * sizeof(double));

    RandomMatrixFloat(M, N, C);
    // for (int i = 0; i < M; ++i)
    // {
    //     for (int j = 0; j < N; ++j)
    //     {
    //         C[i * N + j] = 1.0;
    //     }
    // }
    RandomMatrixFloat(M, K, A);
    // for (int i = 0; i < M; ++i)
    // {
    //     for (int j = 0; j < K; ++j)
    //     {
    //         A[i * K + j] = 1.0;
    //     }
    // }
    RandomMatrixFloat(K, N, B);
    // for (int i = 0; i < K; ++i)
    // {
    //     for (int j = 0; j < N; ++j)
    //     {
    //         B[i * N + j] = 1.0;
    //     }
    // }

    // printf("C: %d x %d\n", M, N);
    // PrintMatrixFloat(M, N, C);
    // printf("A: %d x %d\n", M, K);
    // PrintMatrixFloat(M, K, A);
    // printf("B: %d x %d\n", K, N);
    // PrintMatrixFloat(K, N, B);
    // printf("Alpha: %f\n", alpha);
    // printf("Beta: %f\n", beta);

    tick(&t);
    // cblas_sgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,const enum CBLAS_TRANSPOSE TransB, const int M, const int N,const int K, const float alpha, const float *A,const int lda, const float *B, const int ldb,const float beta, float *C, const int ldc);

    // cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, alpha, A, K, B, N, beta, C, N);
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, alpha, A, K, B, N, beta, C, N);
    // matrix_multiplication(A, B, C, M, K, N);

    *calctime = tock(&t);

    // printf("C: %d x %d\n", M, N);
    // PrintMatrixFloat(M, N, C);

    // free all the memory
    free(C);
    free(A);
    free(B);

    printf("Time: %f\n", *calctime * 1000);
    printf("GFlops: %f\n", (float)(M*N*(3*K+1)*1e-9) / (*calctime));
}