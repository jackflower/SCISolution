#ifndef H_BICYCKLE
#define H_BICYCKLE

#include <vector>
#include "Car.h"

//Standard Template Library

namespace world
{
	///
	///Klasa reprezentuje rower
	///
	class Bicykle
	{
	public:

		///
		///Konstruktor domyślny
		///
		Bicykle();

		///
		///Konstruktor parametryczny
		///
		///@param gift - szyszka na zachętę...
		///
		Bicykle(short gift);

		///
		///Destruktor
		///
		~Bicykle();

		///
		///Metoda zwraca wagę roweru
		///
		const int getWeight() const;

		///
		///Metoda ustawia wagę roweru
		///
		///@param weight - waga
		///
		void setWeight(float weight);

		///
		///Metod dodaje do kontenera w tej klasie elementy
		///
		///@param - cone (wartość liczbowa szyszki)
		///
		void addCone(short cone);

	private:

		float m_weight;//notacja węgierska
		float m_tire;//opony

		std::vector<short> m_cone;// kontener na szyszki
		std::vector<Car> m_cars;// kontener na autka

		const float m_frame;

	
	protected:
	};

#endif//H_BICYCKLE
}