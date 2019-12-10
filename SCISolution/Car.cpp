#include "Car.h"
#include <iostream>

//Konstruktor domyœlny (ctor)
Car::Car()
{
	std::cout << "Urodzilem sie ! :) " << std::endl;
}

//Destruktor (dtor)
Car::~Car()
{
	std::cout << "Zegnam swiat - spadam to Hell :( " << std::endl;
}
