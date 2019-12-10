#include "Car.h"

//Konstruktor domyślny (ctor)
Car::Car():
	m_engine{ 0 },
	m_speed{ 0.0f }
{
}

//Destruktor (dtor)
Car::~Car()
{
}

//Metoda nadaje prędkość
void Car::setSpeed(float speed)
{
	m_speed = speed;
}

//Metoda zwraca prędkość
const float Car::getSpeed() const
{
	return m_speed;
}