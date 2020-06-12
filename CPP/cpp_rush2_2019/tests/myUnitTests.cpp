#include "../src/LittlePony.hpp"
#include "../src/Teddy.hpp"
#include "../src/Box.hpp"
#include "../src/GiftPaper.hpp"
#include "../src/Object.hpp"
#include "../src/Wrap.hpp"
#include <iostream>

Object  **MyUnitTests()
{
   Object **arrayObject = new Object*[2];
   arrayObject[0] = new Teddy("cuddles");
   arrayObject[1] = new LittlePony("happy pony");
   //arrayObject[0]->isTaken();
   return (arrayObject);
}

Object *MyUnitTests(Object **t)
{
    Teddy *Ted;
    Box *Vox;
    GiftPaper *Gift;

    if (!t)
        std::cerr << "You didn't provide a valid list of Objects" << std::endl;
    if (!(Ted = dynamic_cast<Teddy*>(t[0])))
      std::cerr << "No hands, no toy" << std::endl;
    if (!(Vox = dynamic_cast<Box*>(t[1])))
        std::cerr << "No trees, no box" << std::endl;
    if (!(Gift = dynamic_cast<GiftPaper*>(t[2])))
        std::cerr << "No money, no gift" << std::endl;
    if (!Vox->isOpen())
        Vox->openMe();
    Vox->wrapMeThat(t[0]);
    Gift->wrapMeThat(t[1]);
    return (t[2]);
}

int main(void)
{
    std::cout << "----- UNIT TEST 1 -----" << std::endl;
    Object **objTab = MyUnitTests();
    std::cout << objTab[0]->getTitle() << std::endl;
    std::cout << objTab[1]->getTitle() << std::endl;
    std::cout << "----- UNIT TEST 2 -----" << std::endl;
    Object *Ted = new Teddy("pepe");
    Object *Vox = new Box();
    Object *Gift = new GiftPaper();
    Object *tab[3];
    tab[0] = Ted;
    tab[1] = Vox;
    tab[2] = Gift;
    Object *unit = MyUnitTests(tab);
    Teddy *bear = dynamic_cast<Teddy*>(Ted);
    if (bear)
            std::cout << bear->getTitle() << std::endl; 
    delete Ted;
    delete Vox;
    delete Gift;
    return (0);
}
