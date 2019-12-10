#include "Car.h"

//Konstruktor domyœlny (ctor)
Car::Car():
	m_engine{ 0 },
	m_speed{ 0.0f }
{
}

//Destruktor (dtor)
Car::~Car()
{
}

//Metoda nadaje prêdkoœæ
void Car::setSpeed(float speed)
{
	m_speed = speed;
}

//Metoda zwraca prêdkoœæ
const float Car::getSpeed() const
{
	return m_speed;
}