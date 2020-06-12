/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include "IOperand.hpp"

class Int32 : public IOperand {
	public:
		Int32();
		~Int32();

		virtual std::string toString()  const =0;
		virtual  eOperandType  getType ()  const =0; // returns  the  type of  instance
        virtual  IOperand* operator +( const  IOperand &rhs) const = 0; // sum
        virtual  IOperand* operator -( const  IOperand &rhs) const = 0; // diff
        virtual  IOperand* operator *( const  IOperand &rhs) const = 0; // mul
        virtual  IOperand* operator /( const  IOperand &rhs) const = 0; // div
        virtual  IOperand* operator %( const  IOperand &rhs) const = 0; // mod
	

	protected:
	private:
};

#endif /* !INT32_HPP_ */
