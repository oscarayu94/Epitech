/*
** EPITECH PROJECT, 2019
** YEP
** File description:
** main
*/

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include "../include/Display.hpp"

int main()
{
    time_t  t;
    srand((unsigned) time(&t));
    Display *app = new Display();

    if (!app)
        return 84;
    app->run();
    return 0;
}