/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** test
*/

#include <criterion/criterion.h>
#include <iostream>
#include <string>
#include <dlfcn.h>
#include "../IDisplayModule.hpp"
#include <string.h>

Test(dlopen, dlopen_return_value)
{
    void    *handle = dlopen("../lib/lib_arcade_ncurses.so", RTLD_LAZY);

    cr_expect_not_null(handle);
}

Test(dlsym, dlopen_return_value)
{
    void    *handle = dlopen("../lib/lib_arcade_ncurses.so", RTLD_LAZY);
    init_t  *init_lib = (init_t*)dlsym(handle, "init");

    cr_expect_not_null(handle);
}

