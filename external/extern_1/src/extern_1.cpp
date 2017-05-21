#include <extern_1.hpp>
#include <iostream>

using namespace extern_1;

void Extern_1::dummy() const
{
    std::cout << "Hello from " << __FUNCTION__ << std::endl;
}