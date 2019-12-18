#include "Bicykle.h"

namespace world
{
	//ctor
	Bicykle::Bicykle():
		m_weight{ 0.0f},
		m_tire{ 0.0f },
		m_cone{},
		m_frame{-34.54f}
	{
	}

	//Konstruktor parametryczny
	Bicykle::Bicykle(short gift):
		m_weight{ 0.0f },
		m_tire{ 0.0f },
		m_frame{ -34.54f }
	{
		for (int i = 0; i < gift; i++)
			m_cone.push_back(gift);
	}

	//dtor
	Bicykle::~Bicykle()
	{
		m_weight = 0;
		m_tire = 0;
		m_cone;
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

	//Metod dodaje do kontenera w tej klasie elementy
	void Bicykle::addCone(short cone)
	{
		m_cone.push_back(cone);
		//moja większa twoja
		//moja lubić slonia
		//this->
		//Visual Basic
		//Me.
	}
}