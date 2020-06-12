/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** IPizza
*/

#ifndef IPIZZA_HPP_
#define IPIZZA_HPP_

#include "../list.hpp"

namespace plazza {
    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };
    
    class IPizza {
    public:
        // IPizza();
        virtual ~IPizza() = default;
        // virtual bool    operator==(IPizza const &a) const = 0;
        virtual void    print_pizza_info() = 0;
        virtual int getType() = 0;
        virtual int getSize() = 0;
        virtual std::string   getTypeName() = 0;
        virtual std::string   getSizeName() = 0;

    protected:
    private:
    };
}

#endif /* !IPIZZA_HPP_ */
