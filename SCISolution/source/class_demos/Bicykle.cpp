#include "Bicykle.h"
#include <fstream>
#include <iostream>

namespace world
{
	//Konstruktor domyślny (ctor)
	Bicykle::Bicykle():
		m_weight{ 0.0f},
		m_tire{ 0.0f },
		m_cone{},
		m_frame{-34.54f}
	{
	}

	//Konstruktor parametryczny (ctor)
	Bicykle::Bicykle(short gift):
		m_weight{ 0.0f },
		m_tire{ 0.0f },
		m_frame{ -34.54f }
	{
		for (int i = 0; i < gift; i++)
			m_cone.push_back(gift);
	}

	//Destruktor (dtor)
	Bicykle::~Bicykle()
	{
		m_weight = 0;
		m_tire = 0;
		m_cone;

		//test działania destruktora, który zapisuje do pliku
		//przykładową wartość
		//zapisujemy do pliku coś.. m_frame{-34.54f}
		std::fstream plik;
		plik.open("rama.txt", std::ios::out);
		plik << m_frame;
		plik.close();
		std::cout << "Zapisano liczbę..." << std::endl;
	}

	//Metoda zwraca wagę roweru
	const float Bicykle::getWeight() const
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
	}
}//namespace world

