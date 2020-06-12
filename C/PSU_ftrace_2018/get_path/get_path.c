/*
** EPITECH PROJECT, 2019
** get
** File description:
** path
*/

#include "../ftrace.h"
#include "../list.h"

int is_real_path(char *path)
{
    if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
        return (1);
    return (0);
}

char *my_strcmp(char *av)
{
    char *result;

    if (av == NULL || av[0] == '\0')
        return NULL;
    result = malloc(sizeof(char) * (strlen(av) + 1));
    strcpy(result, av);
    return (result);
}

char *try_paths(char *initial_path, char *env_dir, size_t len)
{
    char *data = NULL;
    int g;

    while(env_dir != NULL && env_dir[0] != '\0') {
        data = my_strcmp(env_dir);
        for (g = 0; data != NULL &&
                 data[g] != '\0' && data[g] != ':'; g++);
        data[g] = '\0';
        data = strcat(strcat(data, "/"), initial_path);
        if (is_real_path(data) == 1)
            return (data);
        env_dir = &env_dir[g + 1];
    }
    return (NULL);
}

static char *get_env_dir(void)
{
    char *env_path;

    env_path = getenv("PATH");
    if (env_path == NULL)
        env_path = "/usr/local/bin:/usr/bin:/bin";
    return (env_path);
}

char *get_path(char *initial_path)
{
    if (initial_path == NULL || initial_path[0] == '\0')
        return (NULL);
    if (is_real_path(initial_path) == 1)
        return (initial_path);
    return (try_paths(initial_path, get_env_dir(), strlen(initial_path)));
}
