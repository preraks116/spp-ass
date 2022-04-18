#include <sys/time.h>

void tick(struct timeval *t);
double tock(struct timeval *t);
void RandomVectorFloat(int n, float *A);
void RandomVectorDouble(int n, double *A);
void RandomMatrixFloat(int m, int n, float *A);
void RandomMatrixDouble(int m, int n, double *A);
void PrintMatrixFloat(int m, int n, float *A);
void PrintMatrixDouble(int m, int n, double *A);
void MySaxpy(int n, float a, float *X, float *Y);
void PrintVectorFloat(int n, float *A);
void PrintVectorDouble(int n, double *A);