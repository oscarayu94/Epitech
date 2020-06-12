/*
** EPITECH PROJECT, 2019
** reception
** File description:
** bu oriol
*/

#include "Reception.hpp"
#include "../list.hpp"

Reception::Reception()
{		
    //Parse_input *input = new Parse_input;
    _counter = 1;
}

Reception::~Reception()
{
}

std::string Reception::create_fifo(std::string folder, std::string size)
{
    std::string my_fifo = folder + size;

    if (strcmp(folder.c_str(), "fifos/read/") == 0)
        _fifos_read.push_back(my_fifo);
    else
        _fifos_write.push_back(my_fifo);
    mkfifo(my_fifo.c_str(), 0666); 
    return my_fifo;
}

void    Reception::createKitchen(void)
{
    //std::cout << "start creating kitchen\n";
    pid_t   pros;
    std::string my_fifo_read = create_fifo("fifos/read/", "myfifo" + std::to_string(_fifos_read.size()));
    std::string my_fifo_write = create_fifo("fifos/write/", "myfifo" + std::to_string(_fifos_write.size()));

    pros = fork();
    if (pros == 0) {
        Kitchen *kit = new Kitchen(_input->getCookingTime(), _input->getCookNum(), _input->getReplaceTime(), _counter);
        kit->infinity_loop(my_fifo_write, my_fifo_read);
    }
    _counter++;
}

void	Reception::set_input(Parse_input *input)
{
    _input = input;
}

bool     Reception::add_pizzas_to_existing_kitchen(std::string order)
{
    int count = 0;
    std::string str;
    Utils* s = Utils::getInstance();
    
    for (std::string fifo : _fifos_write) {
        try {
            //std::cout << "entering write order " << order << "\n";
            s->write_to_fd(fifo, order);
            //std::cout << "the cout :" << count << "fifo:" << _fifos_read[count] << "\n";
            str = s->read_from_fd(_fifos_read[count]);
            std::cout << "the answer from kitchen:"<< str << "\n";
            if (strcmp(str.c_str(), "Yes") == 0)
                return true;
            //else
            //    return false;
        } catch ( ... ){
            std::cout << "enter the catcher\n";
        }
        count++;
    }
    return false;
}

//Regina XXL x2; Fantasia M x3; Margarita S x1
//Regina XL x2 ;Fantasia M x3 
// Regina XL x2
bool    Reception::make_pizzas(void)
{
    while(_current_order.empty() == false) {
        for (std::string a: _current_order)
            std::cout << "a:" << a << "\n";
        if (add_pizzas_to_existing_kitchen(_current_order.front()) == true) {
                std::cout << "deleting element in current_oirder\n";
                _current_order.erase(_current_order.begin());
        }
        else
            createKitchen();
        
    }
    //std::cout <<" \n current_order is empty\n";
    return true;
}

bool Reception::infinity_loop()
{
    std::string info = "";
    for (bool val = true; val; ) {
        std::getline(std::cin, info);
        
        _current_order = _input->get_pizza_order(info);
        for (auto a : _current_order)
            std::cout << a << std::endl;
        if (_current_order.empty() == true)
            continue;
        make_pizzas();

    }
    return true;
}

