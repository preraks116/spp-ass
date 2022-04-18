#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to benchmark a function
double benchmark(void (*func)(void), const char *name);