/*
** EPITECH PROJECT, 2019
** utilz
** File description:
** bu prop
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_
#include "../list.hpp"


class Utils {
	public:
		
		static int num_charact(std::string &string, char character);
		static std::string	read_from_fd(std::string fifo);
		static bool	write_to_fd(std::string fifo, std::string);
		static int	getCurrentSeconds(); 
		static Utils *getInstance();

	private:
		Utils();
		~Utils();
		static Utils *instance;
       //template <class myType>
        
};


#endif /* !UTILS_HPP_ */
