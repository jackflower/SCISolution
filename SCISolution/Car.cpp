#include "Car.h"

//Konstruktor domyślny (ctor)
Car::Car():
	m_engine{ 0 },
	m_speed{ 0.0f },
	id_noname{ 1 }
{
}

//Konstruktor parametryczny
Car::Car(float speed):
	m_engine{ 0 },
	m_speed{ speed },
	id_noname{ 1 }
{
}

//Konstruktor parametryczny alfa
Car::Car(float speed, int unique_id) :
	m_engine{ 0 },
	m_speed{ speed },
	id_noname{ unique_id }
{
}

//Destruktor (dtor)
Car::~Car()
{
	m_engine = 0;
	m_speed = 0.0f;
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

//Metoda dodaje do bagażnika bagaż
void Car::addBag(int any)
{
	m_bag.push_back(any);
}