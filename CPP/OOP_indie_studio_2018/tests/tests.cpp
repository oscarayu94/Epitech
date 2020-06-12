/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <vector>
#include <string>
#include "../include/Display.hpp"
#include "../include/MapGenerator.hpp"
#include "../include/Sfx.hpp"

// si encuentra la musica

Test(utils, mapExists)
{
    std::vector<std::string> map = MapGenerator::generateMap(20);
    cr_assert_not_null(&map);
}

//soundbuffer devuelve un bool falso si no encuentra nada

Test(utils, musicFound)
{
    std::string name = "menu_intro";
    // Sfx *hail = new Sfx(name, true);
    cr_assert_any_throw(new Sfx(name, true));
}