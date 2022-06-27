#ifndef CLASS_TEMPLATE_WRAPPER_H
#define CLASS_TEMPLATE_WRAPPER_H

#include <cuda.h>
#include <cuda_runtime.h>


typedef struct gpu_data {
    int* arr_i_device;
    double* arr_d_device;
} gpu_data;

#endif // CLASS_TEMPLATE_WRAPPER_H