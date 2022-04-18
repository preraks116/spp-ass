#ifndef STENCIL_H
#define STENCIL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "helper.h"

enum ImageType{HD, UHD};
void stencil(float *X, enum ImageType typ, int k, float *S, float *Y);

#endif  