/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Regina
*/

#ifndef REGINA_HPP_
#define REGINA_HPP_

#include "../IPizza.hpp"
#include "../APizza.hpp"

class Regina : public APizza {
public:
    Regina(plazza::PizzaType type, plazza::PizzaSize size);
    ~Regina();
    // bool    operator==(plazza::IPizza const &a) const;
    void    print_pizza_info();

protected:
private:
};

#endif /* !REGINA_HPP_ */
