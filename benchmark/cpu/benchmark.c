#include "benchmark.h"
#include "helper.h"

double benchmark(void (*func)(void), const char *name) {
    // start timer
    clock_t start = clock();

    // call function
    func();

    // stop timer
    clock_t end = clock();

    // calculate time

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("----------------------------------------\n");
    printf("%s\n", name);
    // print benchmark result
    printf("time: %f s\n", time);
    printf("----------------------------------------\n");

    return time;
}

double func1(){
    // perform floating point instructions
    double x = 1.1;
    double y = 1.2;
    #pragma omp parallel for
    for (int i = 0; i < 10000000; i++) {
        x = x + y;
        y = x * y;
    }
    return x;
}

double* func2()
{
    double* Y;
    double *X;
    double a = 1.1;
    // malloc memory for X
    X = (double*)malloc(8* sizeof(double));
    // malloc memory for Y
    Y = (double*)malloc(8* sizeof(double));

    RandomVectorDouble(8, X);
    RandomVectorDouble(8, Y);

    #pragma omp parallel for
    for (long i = 0; i < 10000000; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Y[j] = a * X[j] + Y[j];
        }
    }
    return Y;
}

int main()
{
    struct timeval t;
    double calctime;
    // benchmark function 1
    double* y; 
    // malloc
    y = (double*)malloc(8* sizeof(double));
    tick(&t);
    double x = func1();
    // y = func2();
    calctime = tock(&t);
    // print y
    printf("x: %f\n", x);
    // for(int i = 0; i < 8; i++)
    // {
    //     printf("%f\n", y[i]);
    // }
    printf("time: %f ms\n", calctime*1000);
    double flops = 20000000 / calctime;
    printf("FLOPS: %f GFLOPS\n", flops/1000000);
    return 0;
}