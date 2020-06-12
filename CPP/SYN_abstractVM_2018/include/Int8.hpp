/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include "IOperand.hpp"

class Int8 : public IOperand {
	public:
		Int8();
		~Int8();
        std::string  toString ()  const; // string  that  represents  the  instance
        eOperandType  getType ()  const; // returns  the  type of  instance
        IOperand* operator +( const  IOperand &rhs) const; // sum
        IOperand* operator -( const  IOperand &rhs) const; // diff
        IOperand* operator *( const  IOperand &rhs) const; // mul
        IOperand* operator /( const  IOperand &rhs) const; // div
        IOperand* operator %( const  IOperand &rhs) const; // mod
        int getNb() const;
        void setNb(int number);
	protected:
	private:
        int nb;
};
#endif /* !INT8_HPP_ */