#include "Car.h"

//Konstruktor domy�lny (ctor)
Car::Car():
	m_engine{ 0 },
	m_speed{ 0.0f }
{
}

//Destruktor (dtor)
Car::~Car()
{
}

//Metoda nadaje pr�dko��
void Car::setSpeed(float speed)
{
	m_speed = speed;
}

//Metoda zwraca pr�dko��
const float Car::getSpeed() const
{
	return m_speed;
}