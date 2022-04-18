#include <stdio.h>
#include "blis/blis.h"
// #include "../utils/helper.h"
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

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

int main(int argc, char **argv)
{
    srand(time(0));

    // struct timeval t;
    double calctime;

    obj_t* alpha;
    obj_t* beta;
    obj_t a, b, c;
    num_t dt;
    dim_t m, n, k;
    inc_t rs, cs;

    dt = BLIS_FLOAT;
    // dt = BLIS_DOUBLE;

    // dimensions
    m = 4;
    k = 3;
    n = 5;

    if (argc > 1)
    {
        n = atoi(argv[1]);
        if (n == 1)
        {
            m = DIM_SIZE_1;
            k = DIM_SIZE_2;
            n = DIM_SIZE_3;
        }
        else if (n == 2)
        {
            m = DIM_SIZE_3;
            k = DIM_SIZE_4;
            n = DIM_SIZE_5;
        }
        else if (n == 3)
        {
            m = DIM_SIZE_5;
            k = DIM_SIZE_6;
            n = DIM_SIZE_7;
        }
        else if (n == 4)
        {
            m = DIM_SIZE_7;
            k = DIM_SIZE_8;
            n = DIM_SIZE_9;
        }
        else if (n == 5)
        {
            m = DIM_SIZE_10;
            k = DIM_SIZE_11;
            n = DIM_SIZE_12;
        }
    }
    // print n
    
    // i have no idea honestly
    rs = 0;
    cs = 0;

    alpha = &BLIS_ONE;
	beta  = &BLIS_ONE;

	bli_obj_create( dt, m, n, rs, cs, &c );
	bli_obj_create( dt, m, k, rs, cs, &a );
	bli_obj_create( dt, k, n, rs, cs, &b );

	// Set the scalars to use.
	alpha = &BLIS_ONE;
	beta  = &BLIS_ONE;

	// Initialize the matrix operands.
	bli_randm( &a );
    bli_randm( &b );
    bli_randm( &c );
    // bli_setm( &BLIS_ONE, &a);
	// bli_setm( &BLIS_ONE, &b );
	// bli_setm( &BLIS_ONE, &c );

	// bli_printm( "a: randomized", &a, "%4.1f", "" );
	// bli_printm( "b: set to 1.0", &b, "%4.1f", "" );
	// bli_printm( "c: initial value", &c, "%4.1f", "" );

	// c := beta * c + alpha * a * b, where 'a', 'b', and 'c' are general. X, Y, 
	clock_t start = clock();

    bli_gemm( alpha, &a, &b, beta, &c );

    clock_t end = clock();

    calctime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("blis sGEMM time: %f ms\n", calctime*1000);
    
	// bli_printm( "c: after gemm", &c, "%4.1f", "" );

	// Free the objects.
	bli_obj_free( &a );
	bli_obj_free( &b );
	bli_obj_free( &c );
    
    

	// // bli_printm( "y: after gemv", &Y, "%4.1f", "" );

    return 0;
}