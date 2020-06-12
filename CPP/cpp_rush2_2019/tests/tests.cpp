/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** tests
*/

#include "../Toy.hpp"
#include "../Teddy.hpp"
#include "../LittlePony.hpp"
#include "../Box.hpp"
#include "../GiftPaper.hpp"
#include "../Wrap.hpp"

Object  **MyUnitTests()
{
   Object   **arrayObject = new Object*[2];
   arrayObject[0] = new Teddy("cuddles");
   arrayObject[1] = new LittlePony("happy pony");
   //arrayObject[0]->isTaken();
   return arrayObject;
}

/* Object *MyUnitTests(Object **a)
{
    Teddy   *tedy;
    Box     *box;
    GiftPaper   *giftpaper;

    if (a == NULL)
        std::cerr << "Object is empty" << std::endl;
    try {
        //tedy = a[0]
        tedy = reinterpret_cast<Teddy*>(a[0]);
        box = reinterpret_cast<Box*>(a[1]);
        // giftpaper = reinterpret_cast<GiftPaper*>(a[2]);
        if (!(box)->wrapMeThat(tedy))
            std::cerr << "Box is not open" << std::endl;
        else
            if (!(giftpaper)->wrapMeThat(box))
                std::cerr << "Can't add paper to Box was open" << std::endl;
            else {
                std::cout << "Box is in gift paper" << std::endl;
                return giftpaper;
            }
    } catch (...) {
        std::cerr << "Error ocurred" << std::endl;
    }
    return NULL; */
//}   

Object *MyUnitTests(Object **a)
{
   
Teddy   *tedy;
    Box     *box;
GiftPaper   *giftpaper;
  std::string errormsg[3] = {
    "Wrong Toy provided! You bad person :(",
    "Wrong Box provided :'( You disgusting ...",
    "No GiftPaper provided! :("
  };

  if (!a)
    std::cerr << "You didn't provide a valid list of Objects" << std::endl;
  else if (!dynamic_cast<Teddy*>(a[0]))
    std::cerr << errormsg[0] << std::endl;
  else if (!dynamic_cast<Box*>(a[1]))
    std::cerr << errormsg[1] << std::endl;
  else if (!dynamic_cast<GiftPaper*>(a[2]))
    std::cerr << errormsg[2] << std::endl;
  else
    {
      if (!a[1]->isOpen())
        a[1]->openMe();
      a[1]->wrapMeThat(a[0]);
      a[2]->wrapMeThat(a[1]);
      return aObject *MyUnitTests(Object **a)
{
   
Teddy   *tedy;
    Box     *box;
GiftPaper   *giftpaper;
  std::string errormsg[3] = {
    "Wrong Toy provided! You bad person :(",
    "Wrong Box provided :'( You disgusting ...",
    "No GiftPaper provided! :("
  };

  if (!a)
    std::cerr << "You didn't provide a valid list of Objects" << std::endl;
  else if (!dynamic_cast<Teddy*>(a[0]))
    std::cerr << errormsg[0] << std::endl;
  else if (!dynamic_cast<Box*>(a[1]))
    std::cerr << errormsg[1] << std::endl;
  else if (!dynamic_cast<GiftPaper*>(a[2]))
    std::cerr << errormsg[2] << std::endl;
  else
    {
      if (!a[1]->isOpen())
        a[1]->openMe();
      a[1]->wrapMeThat(a[0]);
      a[2]->wrapMeThat(a[1]);
      return a[2];
    }
  return NULL;
}[2];
    }
  return NULL;
}

// void feedObject(void)
// {
//     Object   **arrayObject = new Object*[3];
//     arrayObject[0] = new Teddy("cuddles");
//     arrayObject[1] = new Box;
//     arrayObject[2] = new GiftPaper;
//     //(arrayObject[1])->wrapMeThat(arrayObject[0]);
//     MyUnitTests(arrayObject);
// }

// Test(toys, test00)
// {
//     feedObject();
// }

// Test(toys, test02)
// {
//     MyUnitTests();
// }