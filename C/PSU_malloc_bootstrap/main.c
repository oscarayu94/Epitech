/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <dlfcn.h>
#include <stdio.h>

int main( int ac, char **av)
{
    void *handle;
    void (*func)(char *);

    handle = dlopen("/home/omartinez/delivery/clone3/PSU_malloc_bootstrap/lib_ex01.so", RTLD_LAZY);
    if (!handle){
        printf("Error: %s\n",dlerror());
//        return EXIT_FAILURE;
    }
    func = (void(*)(char *)) dlsym(handle, "my_putstr");
    func("HARO!\n");
    dlclose(handle);
}
