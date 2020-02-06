#ifndef H_SUPER_BICYCKLE
#define H_SUPER_BICYCKLE

#include "Bicykle.h"

namespace world
{
	///
	///Klasa (pochodna) reprezentuje klasę pochodną rozszerzającą
	///funkcjonalność klasy (bazowej) Bicykle
	///
	class SuperBicykle : public Bicykle
	{
	public:

		///
		///Konstruktor domyślny
		///
		SuperBicykle();

		///
		///Destruktor wirtualny
		///
		virtual ~SuperBicykle();
	};
}//namespace world
#endif//H_SUPER_BICYCKLE