/*
** EPITECH PROJECT, 2020
** B_PSU_400
** File description:
** hello
*/

#include <dlfcn.h>

int main()
{
    void *handle;
    void (*function)(char *);

    handle = dlopen("libfunctions.so", RTLD_LAZY);
    function = dlsym(handle, "my_putstr");
    function("Hello world!!!\n");

    dlclose(handle);
    return (0);
}
