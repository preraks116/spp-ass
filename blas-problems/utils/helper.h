#include <sys/time.h>

void tick(struct timeval *t);
double tock(struct timeval *t);
void RandomVectorFloat(int n, float *A);
void RandomVectorDouble(int n, double *A);
void RandomMatrixFloat(int m, int n, float *A);
void RandomMatrixDouble(int m, int n, double *A);
void PrintMatrix(int m, int n, float *A);
void MySaxpy(int n, float a, float *X, float *Y);
void printVector(int n, float *A);