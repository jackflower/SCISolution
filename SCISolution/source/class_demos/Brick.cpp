#include "Brick.h"
#include <iostream>


//Konstrukor (ctor)
Brick::Brick()
{
	// "krzycz�cy" konstruktor - testy
	std::cout << "Urodzilem sie....:) " << std::endl;
}

//Destruktor (dtor)
Brick::~Brick()
{
	// "krzycz�cy" destruktor - testy
	std::cout << "Ide do nieba :( zgon... " << std::endl;
}
