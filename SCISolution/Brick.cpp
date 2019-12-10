#include "Brick.h"
#include <iostream>


//Konstrukor (ctor)
Brick::Brick()
{
	std::cout << "Urodzi³\lem sie....:) " << std::endl;
}

//Destruktor (dtor)
Brick::~Brick()
{
	std::cout << "Ide do nieba :( zgon... " << std::endl;
}
