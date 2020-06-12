/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

#include "IOperand.hpp"

class Double : public IOperand {
	public:
		Double();
		~Double();

        virtual  std::string  toString ()  const =0; // string  that  represents  the  instance
		virtual  eOperandType  getType ()  const =0; // returns  the  type of  instance
        virtual  IOperand* operator +( const  IOperand &rhs) const = 0; // sum
        virtual  IOperand* operator -( const  IOperand &rhs) const = 0; // diff
        virtual  IOperand* operator *( const  IOperand &rhs) const = 0; // mul
        virtual  IOperand* operator /( const  IOperand &rhs) const = 0; // div
        virtual  IOperand* operator %( const  IOperand &rhs) const = 0; // mod

	protected:
	private:
};

#endif /* !DOUBLE_HPP_ */
