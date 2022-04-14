#include "benchmark.h"

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

void func1(){
    // perform floating point instructions
    double x = 1.5;
    double y = 2.5;
    for (int i = 0; i < 1000000000; i++) {
        x = x + y;
        y = x * y;
    }
}

int main()
{
    // benchmark function 1
    double time = benchmark(func1, "func1");
    double flops = 2000000000 / time;
    printf("FLOPS: %f GFLOPS\n", flops/1000000000);
    return 0;
}