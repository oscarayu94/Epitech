export LD_PRELOAD=/home/omartinez/delivery/clone4/PSU_2019_malloc/lib/libmy_malloc.so
gcc -L /home/omartinez/delivery/clone4/PSU_2019_malloc/libmy_malloc.so test test.c -lmy_malloc

#include <unistd.h>
int brk(void *addr);
void *sbrk(intptr_t increment); 

expected output: 

hola
0030
0123456789
0123456789

malloc needs to be compiled dinamically because it need to be able to be used no matter how the compilation is done.

