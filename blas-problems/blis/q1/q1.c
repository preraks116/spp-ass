#include <stdio.h>
#include "blis/blis.h"
// #include "../utils/helper.h"
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#define VEC_SIZE_1 20000000
#define VEC_SIZE_2 40000000
#define VEC_SIZE_3 60000000
#define VEC_SIZE_4 80000000
#define DEFAULT_VECTOR_LENGTH 100000000 // million
// #define DEFAULT_VECTOR_LENGTH 4 // million
#define DEFAULT_ALPHA 2.0

int main(int argc, char **argv)
{
    srand(time(0));

    // struct timeval t;
    double calctime;

    obj_t alpha, beta, gamma, delta;
    obj_t a, b, c, d;
    num_t dt, dt2;
    dim_t m, n;
    inc_t rs, cs;

    dt = BLIS_FLOAT;
    dt2 = BLIS_DOUBLE;

    // dimensions
    m = 1;

    if (argc > 1)
    {
        n = atoi(argv[1]);
        if (n == 1)
        {
            n = VEC_SIZE_1;
        }
        else if (n == 2)
        {
            n = VEC_SIZE_2;
        }
        else if (n == 3)
        {
            n = VEC_SIZE_3;
        }
        else if (n == 4)
        {
            n = VEC_SIZE_4;
        }
    }
    else
    {
        n = DEFAULT_VECTOR_LENGTH;
    }
    // print n
    printf("n = %ld\n", n);
    // i have no idea honestly
    rs = 0;
    cs = 0;

    // creating 1D vector objects
    bli_obj_create(dt, m, n, rs, cs, &a);
    bli_obj_create(dt, m, n, rs, cs, &c);

    bli_obj_create(dt2, m, n, rs, cs, &b);
    bli_obj_create(dt2, m, n, rs, cs, &d);

    // initialize alpha
    bli_obj_create_1x1(dt, &alpha);
    bli_obj_create_1x1(dt2, &beta);
    bli_obj_create_1x1(dt2, &gamma);
    bli_obj_create_1x1(dt2, &delta);

    bli_setsc(DEFAULT_ALPHA, 0.0, &alpha);
    bli_setsc(DEFAULT_ALPHA, 0.0, &beta);
    bli_setsc(DEFAULT_ALPHA, 0.0, &gamma);
    bli_setsc(DEFAULT_ALPHA, 0.0, &delta);

    // bli_printm( "alpha:", &alpha, "%4.1f", "" );

    // Set a to random values.
    bli_randv(&a);
    bli_randv(&b);
    bli_randv(&c);
    bli_randv(&d);

    // print vector before scaling

    printf("sSCAL\n");

    // bli_printm( "a before scaling", &a, "%4f", "" );

    // Scale a vector (destructive).
    // tick(&t);

    clock_t start = clock();

    bli_scalv(&alpha, &a);

    clock_t end = clock();

    calctime = (double)(end - start) / CLOCKS_PER_SEC;

    // calctime = tock(&t);

    printf("blis sscal time: %f ms\n", calctime * 1000);

    // bli_printm( "a := alpha * a", &a, "%4f", "" );

    printf("dSCAL\n");

    // bli_printm( "b before scaling", &b, "%4f", "" );
    // same thing for double

    // tick(&t);

    start = clock();

    bli_scalv(&beta, &b);

    end = clock();

    calctime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("blis dscal time: %f ms\n", calctime * 1000);

    start = clock();

    bli_dotv( &a, &c, &gamma );

    end = clock();

    calctime = (double)(end - start) / CLOCKS_PER_SEC;

    // calctime = tock(&t);

    printf("blis sdot time: %f ms\n", calctime * 1000);

    start = clock();

    bli_dotv( &b, &d, &delta );

    end = clock();

    calctime = (double)(end - start) / CLOCKS_PER_SEC;

    // calctime = tock(&t);

    printf("blis ddot time: %f ms\n", calctime * 1000);

    // bli_printm( "b := beta * b", &b, "%4f", "" );

    printf("sAXPY\n");

    // bli_printm( "c before scaling", &c, "%4f", "" );

    // tick(&t);

    start = clock();

    bli_axpyv(&alpha, &a, &c);

    end = clock();

    calctime = (double)(end - start) / CLOCKS_PER_SEC;

    // calctime = tock(&t);

    printf("blis saxpy time: %f ms\n", calctime * 1000);

    // bli_printm( "c := alpha * a + c", &c, "%4f", "" );

    printf("dAXPY\n");

    // bli_printm( "d before scaling", &d, "%4f", "" );

    // tick(&t);

    start = clock();

    bli_axpyv(&beta, &d, &b);

    end = clock();

    calctime = (double)(end - start) / CLOCKS_PER_SEC;

    // calctime = tock(&t);

    printf("blis daxpy time: %f ms\n", calctime * 1000);

    // bli_printm( "b := beta * d + b", &b, "%4f", "" );

    // Free the objects.
    bli_obj_free(&alpha);
    bli_obj_free(&beta);
    bli_obj_free(&a);
    bli_obj_free(&b);
    bli_obj_free(&c);
    bli_obj_free(&d);

    return 0;
}