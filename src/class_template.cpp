#include "class_template.h"

Class_template::Class_template()
{
    std::cout << "Class initialized." << std::endl;
}

Class_template::~Class_template()
{
    std::cout << "Class destroyed." << std::endl;
}

void Class_template::print()
{
    std::cout << "Class printed." << std::endl;
}