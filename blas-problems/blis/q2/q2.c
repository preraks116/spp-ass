#include <stdio.h>
#include "blis/blis.h"
// #include "../utils/helper.h"
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#define DIM_SIZE_1 2000
#define DIM_SIZE_2 4000
#define DIM_SIZE_3 6000
#define DIM_SIZE_4 8000
#define DIM_SIZE_5 10000
#define DIM_SIZE_6 12000
#define DEFAULT_ALPHA 1.0
#define DEFAULT_BETA 1.0

int main(int argc, char **argv)
{
    srand(time(0));

    // struct timeval t;
    double calctime;

    obj_t* alpha;
    obj_t* beta;
    obj_t a, X, Y;
    num_t dt;
    dim_t m, n;
    inc_t rs, cs;

    // dt = BLIS_FLOAT;
    dt = BLIS_DOUBLE;

    // dimensions
    m = 4;
    n = 5;

    if (argc > 1)
    {
        n = atoi(argv[1]);
        if (n == 1)
        {
            m = DIM_SIZE_1;
            n = DIM_SIZE_2;
        }
        else if (n == 2)
        {
            m = DIM_SIZE_2;
            n = DIM_SIZE_3;
        }
        else if (n == 3)
        {
            m = DIM_SIZE_3;
            n = DIM_SIZE_4;
        }
        else if (n == 4)
        {
            m = DIM_SIZE_4;
            n = DIM_SIZE_5;
        }
        else if (n == 5)
        {
            m = DIM_SIZE_5;
            n = DIM_SIZE_6;
        }
    }
    else
    {
        m = 4;
        n = 5;
    }
    // print n
    
    // i have no idea honestly
    rs = 0;
    cs = 0;

    alpha = &BLIS_ONE;
	beta  = &BLIS_ONE;

    // creating 1D vector objects
    dt = BLIS_FLOAT;
	bli_obj_create( dt, m, n, rs, cs, &a );
	bli_obj_create( dt, 1, n, rs, cs, &X );
	bli_obj_create( dt, 1, m, rs, cs, &Y );

	// Notice that we created vectors 'x' and 'y' as row vectors, even though
	// we often think of them as column vectors so that the overall problem
	// dimensions remain conformal. Note that this flexibility only comes
	// from the fact that the operation requires those operands to be vectors.
	// If we were instead looking at an operation where the operands were of
	// general shape (such as with the gemm operation), then typically the
	// dimensions matter, and column vectors would not be interchangeable with
	// row vectors and vice versa.

	// Set the scalars to use.

	// Initialize vectors 'x' and 'y'.
	bli_setv( &BLIS_ONE,  &X );
	bli_setv( &BLIS_ONE, &Y );

	// Randomize 'a'.
	bli_randm( &a );
    // print values of alpha and beta
    // bli_printm( "alpha:", alpha, "%4.1f", "" );
    // bli_printm( "beta:", beta, "%4.1f", "" );
	// bli_printm( "a: randomized", &a, "%4.1f", "" );
	// bli_printm( "x: set to 1.0", &X, "%4.1f", "" );
	// bli_printm( "y: initial value", &Y, "%4.1f", "" );

	// y := beta * y + alpha * a * x, where 'a' is general.
    clock_t start = clock();

	bli_gemv( alpha, &a, &X, beta, &Y );

    clock_t end = clock();

    calctime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("blis sGEMV time: %f ms\n", calctime*1000);

	// bli_printm( "y: after gemv", &Y, "%4.1f", "" );

	// Free the objects.
	bli_obj_free( &a );
	bli_obj_free( &X );
	bli_obj_free( &Y );

    return 0;
}