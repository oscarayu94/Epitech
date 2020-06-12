
#include <string.h>
#include <iostream>

int main (int ac, char **av)
{
    std::string test("Hello");
    int show = strlen(test);
    std::cout << show << std::endl;
}
