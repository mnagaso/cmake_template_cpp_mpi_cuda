#ifndef CLASS_TEMPLATE_H
#define CLASS_TEMPLATE_H

#include <iostream>

#ifdef USE_CUDA
#include "class_template_wrapper.h"
#endif

#define N 100

class Class_template {
public:
    Class_template();
    ~Class_template();
    void print();
    void memory_allocation();
    void memory_deallocation();
    void add_2_i();
    void add_2_d();

    int* arr_i;
    double* arr_d;
};

#endif // CLASS_TEMPLATE_H