/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IOperand.hpp"

class Factory {
	public:
		Factory();
		~Factory();
		enum eOperandType {Int8,Int16,Int32,Float, Double, BigDecimal};
        static IOperand* createOperand(eOperandType type, const std::string& value);

	protected:
	private:
		IOperand* createInt8(const  std:: string& value);
		IOperand* createInt16(const  std:: string& value);
		IOperand* createInt32(const  std:: string& value);
		IOperand* createFloat(const  std:: string& value);
		IOperand* createDouble(const  std:: string& value);
		IOperand* createBigDecimal(const  std:: string& value);
};

#endif /* !FACTORY_HPP_ */
