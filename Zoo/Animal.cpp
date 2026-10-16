#include <iostream>
#include "Animal.h"

Animal::Animal() = default;
Animal::~Animal() = default;
Animal::Animal(const Animal& other) = default;
Animal::Animal(Animal&& other) = default;
Animal& Animal::operator=(const Animal& other) = default;
Animal& Animal::operator=(Animal&& other) = default;

void Animal::Sound()
{
    std::cout << "Nothing doesn't make a sound. . ." << std::endl;
}

void Animal::Movement()
{
    std::cout << "Nothing is not moving. . ." << std::endl;
}

void Animal::Food()
{
    std::cout << "Nothing doesn't ask for food. . ." << std::endl;
}

// cat
TomTheCat::TomTheCat() = default;
TomTheCat::~TomTheCat() = default;
TomTheCat::TomTheCat(const TomTheCat& cat) = default;
TomTheCat::TomTheCat(TomTheCat&& cat) = default;
TomTheCat& TomTheCat::operator=(const TomTheCat& cat) = default;
TomTheCat& TomTheCat::operator=(TomTheCat&& cat) = default;

void TomTheCat::Sound()
{
    std::cout << "Meow~" << std::endl;
}

void TomTheCat::Movement()
{
    std::cout << "Silently walking on fours (searching for friend)" << std::endl;
}

void TomTheCat::Food()
{
    std::cout << "Would like to eat a steak" << std::endl;
}

//mouse
JerryTheMouse::JerryTheMouse() = default;
JerryTheMouse::~JerryTheMouse() = default;
JerryTheMouse::JerryTheMouse(const JerryTheMouse& mouse) = default;
JerryTheMouse::JerryTheMouse(JerryTheMouse&& mouse) = default;
JerryTheMouse& JerryTheMouse::operator=(const JerryTheMouse& mouse) = default;
JerryTheMouse& JerryTheMouse::operator=(JerryTheMouse&& mouse) = default;

void JerryTheMouse::Sound()
{
    std::cout << "Squeek!" << std::endl;
}

void JerryTheMouse::Movement()
{
    std::cout << "Running on fours (from Tom)" << std::endl;
}

void JerryTheMouse::Food()
{
    std::cout << "Loves eating cheese" << std::endl;
}

//amo
Amogus::Amogus() = default;
Amogus::~Amogus() = default;
Amogus::Amogus(const Amogus& amo) = default;
Amogus::Amogus(Amogus&& amo) = default;
Amogus& Amogus::operator=(const Amogus& amo) = default;
Amogus& Amogus::operator=(Amogus&& amo) = default;

void Amogus::Sound()
{
    std::cout << ". . ." << std::endl;
}

void Amogus::Movement()
{
    std::cout << "Running, just a running sausage with legs" << std::endl;
}

void Amogus::Food()
{
    std::cout << "Another Amoguses" << std::endl;
}

//elephant
OrangeElephant::OrangeElephant() = default;
OrangeElephant::~OrangeElephant() = default;
OrangeElephant::OrangeElephant(const OrangeElephant& elephant) = default;
OrangeElephant::OrangeElephant(OrangeElephant&& elephant) = default;
OrangeElephant& OrangeElephant::operator=(const OrangeElephant& elephant) = default;
OrangeElephant& OrangeElephant::operator=(OrangeElephant&& elephant) = default;

void OrangeElephant::Sound()
{
    std::cout << "TRUMPeting" << std::endl;
}

void OrangeElephant::Movement()
{
    std::cout << "Stomping on fours" << std::endl;
}

void OrangeElephant::Food()
{
    std::cout << "Eating leaves and fruits with alcohol in them" << std::endl;
}

//dino
TRex::TRex() = default;
TRex::~TRex() = default;
TRex::TRex(const TRex& dino) = default;
TRex::TRex(TRex&& dino) = default;
TRex& TRex::operator=(const TRex& dino) = default;
TRex& TRex::operator=(TRex&& dino) = default;

void TRex::Sound()
{
    std::cout << "ROA-A-AR" << std::endl;
}

void TRex::Movement()
{
    std::cout << "8 tons of silently running giant lizard" << std::endl;
}

void TRex::Food()
{
    std::cout << "Any kind of meat" << std::endl;
}