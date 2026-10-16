#include <iostream>
#include "Animal.h"

int main()
{
    Animal Zoo;
    TomTheCat cat;
    JerryTheMouse mouse;
    Amogus amogus;
    OrangeElephant elephant;
    TRex dino;
    std::cout << "What animal would you like to know about?" << std::endl;
    std::cout << "(What sound it makes, how it move and what it eats)" << std::endl;
    std::cout << "1. Tom the Cat\n" "2. Jerry the Mouse\n" "3. Amogus\n" "4. Orange Elephant\n" "5. T-Rex\n";
    std::cout << "Enter the choosen option(number): " << std::endl;
    int input;
    std::cin >> input;

    switch (input)
    {
    case 1 :
        cat.Sound();
        cat.Movement();
        cat.Food();
        break;
    case 2 :
        mouse.Sound();
        mouse.Movement();
        mouse.Food();
        break;
    case 3 :
        amogus.Sound();
        amogus.Movement();
        amogus.Food();
        break;
    case 4 :
        elephant.Sound();
        elephant.Movement();
        elephant.Food();
        break;
    case 5 :
        dino.Sound();
        dino.Movement();
        dino.Food();
        break;
    }
}
