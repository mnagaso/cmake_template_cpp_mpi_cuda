#include <iostream>
#include "class_template.h"


int main()
{
    std::cout << "Hello, World!" << std::endl;

#ifdef USE_CUDA
    std::cout << "Using CUDA." << std::endl;
#else
    // example class
    Class_template c;
#endif

    return 0;
}