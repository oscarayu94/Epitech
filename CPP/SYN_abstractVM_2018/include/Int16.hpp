/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include "IOperand.hpp"

class Int16 : public IOperand{
	public:
		Int16();
		~Int16();

		virtual  std::string  toString ()  const =0; // string  that  represents  the  instance
        virtual  eOperandType  getType ()  const =0; // returns  the  type of  instance
        
	protected:
	private:
};

#endif /* !INT16_HPP_ */
