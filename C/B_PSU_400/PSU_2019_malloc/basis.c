/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** basis
*/

#include <unistd.h>

void *malloc(size_t  size);
// void  free(void *ptr);
// void *calloc(size_t  nmemb , size_t  size);
// void *realloc(void *ptr , size_t  size);
// void *reallocarray(void *ptr , size_t  nmemb , size_t  size);

// cosa = malloc(sizeof(tipo));

//getpagesize

void *malloc(size_t  size)
{ 
  
  sbrk(size);
  //brk(size);

}

