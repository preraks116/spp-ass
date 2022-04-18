#include "stencil.h"


void stencil(float *X, enum ImageType typ, int k, float *S, float *Y)
{
    int dimX = 1920;
    int dimY = 1080;

    if (typ == UHD)
    {
        dimX = 3840;
        dimY = 2160;
    }

// #pragma omp parallel for
    for (int i = 0; i < dimY; i++)
    {
        for (int j = 0; j < dimX; j++)
        {
            Y[i * dimX + j] = 0.0;
            for (int kx = 0; kx < k && i + kx < dimY; kx++)
            {
                float temp = 0.0;
                // #pragma omp parallel for reduction(+:temp)  
                for (int ky = 0; ky < k && j + ky < dimX; ky++)
                {
                    temp += X[(i + kx) * dimX + (j + ky)] * S[kx * k + ky];
                }
                Y[i * dimX + j] += temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    enum ImageType typ = HD;
    int n,X,Y;
    struct timeval t;
    double calctime;

    if(argc > 1)
    {
        n = atoi(argv[1]);
        if(n == 1)
        {
            typ = HD;
            X = 1920;
            Y = 1080;
        }
        else if(n == 2)
        {
            typ = UHD;
            X = 3840;
            Y = 2160;
        }
    }
    else
    {
        n = 1;
        typ = HD;
        X = 1920;
        Y = 1080;
    }

    // int k = 3;

    // malloc X, S, Y

    for (int k = 3; k < 100; k+= 20)
    {
        float *X_ = (float *)malloc(sizeof(float) * X * Y);
        float *S_ = (float *)malloc(sizeof(float) * k * k);
        float *Y_ = (float *)malloc(sizeof(float) * X * Y);

        tick(&t);

        // call function
        stencil(X_, typ, k, S_, Y_);

        calctime = tock(&t);
        // printf("Flops : %lf\n", (double)nx * ny * k * k * 2 / time/1e9);
        // printf("Bandwidth : %lf\n", (double)2 * nx * ny * sizeof(float) / time / 1e9);
        printf("k: %d Time,GFlops,Bandwidth: %f,%f, %f\n",k,  calctime*1000, (double)X * Y * k * k * 2 / calctime/1e9, (double)2 * X * Y * 4 / calctime / 1e9);
    }
}