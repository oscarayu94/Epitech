/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** table
*/


#ifndef TABLE_HPP
#define TABLE_HPP

#include "ITable.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"

class PapaXmasTable: public ITable {
public:
    PapaXmasTable(void);
    void put(Object *) override;
    Object *take(void) override;
    int getSize(void) const;
    std::string *look(void) const;
    std::vector<Object *> getTableContent(void) const;
};

std::ostream &operator<<(std::ostream &s, PapaXmasTable &table);
ITable *createTabe(void);
#endif
