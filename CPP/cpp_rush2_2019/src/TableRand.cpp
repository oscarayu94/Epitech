/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** table tand
*/

#include "TableRand.hpp"
#include "Toy.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"

ITable *createTable(void)
{
    return (new PapaXmasTable);
}

int randomInt(int min, int max)
{
    return (min + (std::rand() % (max - min + 1)));
}

TableRand::TableRand(void)
{
    int numberOfObjects = randomInt(2, 10);
    Object *obj;
    int rd;

    for (int i = 0; i < numberOfObjects; i++) {
        rd = randomInt(0, 1);
        obj = rd == 0 ? dynamic_cast<Object *>(new LittlePony("happy pony")) : dynamic_cast<Object *>(new Teddy("cuddles"));
        _tableContent.push_back(obj);
    }
}
