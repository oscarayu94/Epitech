/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include "parse_input/Parse_input.hpp"
#include "../pizza/IPizza.hpp"
#include "../kitchen/Kitchen.hpp"
#include <sys/wait.h>
#include "../utils/Utils.hpp"

class Reception {
	public:
		Reception();
		~Reception();
        bool infinity_loop();
		void	set_input(Parse_input *);
		void	createKitchen(void);
		void	init(void);
		bool     add_pizzas_to_existing_kitchen(std::string);
		//std::string	read_from_fd(int fd);
		std::string create_fifo(std::string folder, std::string size);
		bool   	make_pizzas(void);
		bool    all_kitchen_are_full();


	private:
		float   cooking_time;
        std::vector<std::unique_ptr<plazza::IPizza>> _component_types;
		Parse_input *_input;
		
		std::vector<std::string> _fifos_read;
		std::vector<std::string> _fifos_write;
		int _counter;
		// std::vector<plazza::IPizza*>    _current_order;
		std::vector<std::string>    _current_order;
};

#endif /* !RECEPTION_HPP_ */
