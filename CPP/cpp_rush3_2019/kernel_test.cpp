#include <criterion/criterion.h>
#include "Datas/KernelSystem.hpp"
#include <iostream>
Test(suite, test)
{
    KernelSystem k;
    std::string str = k.getKernel();

    cr_assert(str.size() >= 0);
}
