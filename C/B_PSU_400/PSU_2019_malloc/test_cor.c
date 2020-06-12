//We have to dynamically load the library:

#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
    const char *error = NULL;
    void *module = NULL;
    int (*ptr)() = NULL;
    
    /* Load dynamically loaded library */
    module = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!module) {
        dprintf(2, "Couldn't open libmy_malloc.so: %s\n",
                dlerror());
        exit(1);
    }

    /* Get symbol */
    dlerror();
    ptr = dlsym(module, "malloc"); //insert here the needed function malloc
    if ((error = dlerror())) {
        dprintf(2, "Couldn't find malloc: %s\n", error);
        exit(1);
    }

    /* Now call the function in the DL library */
    int ret = (*ptr)();
    
    /* All done, close things cleanly */
    dlclose(module);

    return ret;
}