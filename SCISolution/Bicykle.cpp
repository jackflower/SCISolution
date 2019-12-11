#include "Bicykle.h"

namespace world
{
	//ctor
	Bicykle::Bicykle():
		m_weight{ 0.0f},
		m_tire{ 0.0f }
	{
	}

	//dtor
	Bicykle::~Bicykle()
	{
		m_weight = 0;
		m_tire = 0;
	}

	//Metoda zwraca wagę roweru
	const int Bicykle::getWeight() const
	{
		return m_weight;
	}

	//Metoda ustawia wagę roweru
	void Bicykle::setWeight(float weight)
	{
		m_weight = weight;
	}
}