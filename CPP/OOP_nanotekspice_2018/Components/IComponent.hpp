/*
** EPITECH PROJECT, 2019
** IComponent
** File description:
** By Luis Angel Macias de la Cruz
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <vector>
#include <map>
#include <algorithm>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
	public:
		// IComponent();
		virtual ~IComponent() = default;

        virtual nts::Tristate   compute(std::size_t pin = 1) = 0;
        virtual void    setLink(std::size_t pin, nts::IComponent &other,
                                std::size_t otherPin) = 0;
        virtual void    dump() = 0;
        // virtual Component    *getComponent() = 0;
        // virtual std::unique_ptr<IComponent> create(const std::string &value) = 0;

	protected:
	private:
    };
}

#endif /* !ICOMPONENT_HPP_ */
