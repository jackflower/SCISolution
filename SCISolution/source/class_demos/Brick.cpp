#include "Brick.h"
#include <iostream>


//Konstrukor (ctor)
Brick::Brick()
{
	// "krzyczący" konstruktor - testy
	std::cout << "Urodzilem sie....:) " << std::endl;
}

//Destruktor (dtor)
Brick::~Brick()
{
	// "krzyczący" destruktor - testy
	std::cout << "Ide do nieba :( zgon... " << std::endl;
}
