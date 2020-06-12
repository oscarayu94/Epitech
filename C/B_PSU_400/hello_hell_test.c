/*
** EPITECH PROJECT, 2020
** B_PSU_400
** File description:
** hello_hell_test
*/

#include <dlfcn.h>

int main()
{
  void    *handle;
  int     *iptr, (*fptr)(int);

  /* open the needed object */
  handle = dlopen("libfunctions.so", RTLD_LOCAL | RTLD_LAZY);

  /* find the address of function and data objects */
  fptr = (int (*)(int))dlsym(handle, "my_putstr");
  iptr = (int *)dlsym(handle, "Hello World!!");

  /* invoke function, passing value of integer as a parameter */
  (*fptr)(*iptr);
  dlclose(handle);
}