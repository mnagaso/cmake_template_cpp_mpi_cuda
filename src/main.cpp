#include <iostream>
#include "class_template.h"


int main()
{
    std::cout << "Hello, World!" << std::endl;

#ifdef USE_CUDA
    std::cout << "Using CUDA." << std::endl;
#endif
    // example class
    Class_template c;

    return 0;
}