#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include "include/libmy_malloc.h" //What?

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
    }
    return (i);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

void test_calloc(void)
{
    int i;
    int * pointer = (int *) calloc(10, sizeof(int));

    for ( i = 0; i < 10; i++ ) {
        pointer[i] = i;
    }
    for (i = 0; i<10; i++ ) {
        my_put_nbr(pointer[i] );
    }
    my_putstr( "\n" );
    free( pointer );
}

int test_malloc_realloc_free(void)
{
    int *ptr = (int *)malloc(sizeof(int)*2);
    int i;
    int *ptr_new;

    *ptr = 10;
    *(ptr + 1) = 20;

    ptr_new = (int *)realloc(ptr, sizeof(int)*3);
    *(ptr_new + 2) = 30;
    for (i = 0; i < 3; i++)
        my_put_nbr(*(ptr_new + i));
    free(ptr_new);
    my_putstr("\n");
    return 0;
}

void test_malloc_free(void)
{
    int i = 0;
    char *str = "hola";
    char *test = malloc(sizeof(char) * my_strlen(str) + 1);
    for (i = 0; str[i]; i++)
        test[i] = str[i];
    test[i] = '\0';
    my_putstr(test);
    my_putstr("\n");
    free(test);
}

void *test_reallocarray(void)
{
    int *arr = NULL;

    arr = reallocarray(NULL, 10, sizeof(int));
    for (int i = 0; i < 10; i++)
        arr[i] = i;
    for (int i = 0; i < 10; i++)
        my_put_nbr(arr[i]);
    my_putstr("\n");
    free(arr);
}

int main(void)
{
    test_malloc_free();
    test_malloc_realloc_free();
    test_calloc();
    test_reallocarray();
    return (0);
}