/*
** EPITECH PROJECT, 2020
** B_PSU_400
** File description:
** brk_sbrk
*/

#include <unistd.h>
#include <stdio.h>

int main()
{
  void *retorn;
  brk(retorn+100*100*100);
  retorn = sbrk(0);
  printf("%p\n",retorn);
  return (0);
}