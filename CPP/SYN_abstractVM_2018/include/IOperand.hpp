/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

#include <string>

class IOperand {
	public:
        IOperand(){};
        enum eOperandType{ Int8,Int16,Int32,Float,Double,BigDecimal};
        virtual  std::string  toString ()  const =0; // string  that  represents  the  instance
        virtual  eOperandType  getType ()  const =0; // returns  the  type of  instance
        virtual  IOperand* operator +( const  IOperand &rhs) const = 0; // sum
        virtual  IOperand* operator -( const  IOperand &rhs) const = 0; // diff
        virtual  IOperand* operator *( const  IOperand &rhs) const = 0; // mul
        virtual  IOperand* operator /( const  IOperand &rhs) const = 0; // div
        virtual  IOperand* operator %( const  IOperand &rhs) const = 0; // mod
        virtual ~IOperand () {}

	protected:
	private:
};

#endif /* !IOPERAND_HPP_ */
