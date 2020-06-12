/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** table
*/

#include "PapaXmasTable.hpp"


ITable *createTabe(void)
{
    ITable *table = new PapaXmasTable;

    table->put(new Teddy("cuddles"));
    table->put(new LittlePony("happy pony"));
    return (table);
}

PapaXmasTable::PapaXmasTable(void)
{
//    _tableContent.push_back(new );
}

int PapaXmasTable::getSize(void) const { return (_tableContent.size()); }
std::vector<Object *> PapaXmasTable::getTableContent(void) const { return (_tableContent); };

void PapaXmasTable::put(Object *object)
{
    if (getSize() + 1 > 10)
    {
        std::cerr << "Table Collapsed" << std::endl;
        return;
    }
    _tableContent.push_back(object);
}

Object *PapaXmasTable::take(void)
{
    // TODO put logic here
    int index = getSize() - 1;
    Object *toReturn = _tableContent[index];

    _tableContent.pop_back();
    return (toReturn);
}

std::ostream &operator<<(std::ostream &s, PapaXmasTable &table)
{
    int size = table.getSize();
    std::vector<Object *> tmp = table.getTableContent();

    std::cout << "PapaXmasTable contains: ";
    for (int i = 0; i < size; i++)
        std::cout << tmp[i] << " ";
    std::cout << "\n";
    return (s);
}

std::string *PapaXmasTable::look(void) const
{
    int size = getSize();
    std::string *array;
    int i;

    if (size == 0)
        return (nullptr);
    array = new std::string[size + 1];
    for (i = 0; i < size; i++)
        array[i] = std::string(_tableContent[i]->getTitle());
    return (array);
}
