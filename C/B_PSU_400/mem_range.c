/*
** EPITECH PROJECT, 2020
** B_PSU_400
** File description:
** brk_sbrk
*/

#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

int main()
{
    void    *handle;
    int     *iptr, (*fptr)(int);

    handle = dlopen("libfunctions.so", RTLD_LOCAL | RTLD_LAZY);

    fptr = (int (*)(int))dlsym(handle, "my_putstr");
    iptr = (int *)dlsym(handle, "Hello World!!");

    int a = 0;

    printf("%p\n",&main);
    printf("%p\n", &iptr);
    printf("%p\n",&strlen);
    printf("%p\n",&a);
    printf("%p\n",&"toto");
}