#ifndef H_SUPER_BICYCKLE
#define H_SUPER_BICYCKLE

#include "Bicykle.h"

namespace world
{
	///
	///Klasa (pochodna) reprezentuje klasê pochodn¹ rozszerzaj¹c¹
	///funkcjonalnoœæ klasy (bazowej) Bicykle
	///
	class SuperBicykle : public Bicykle
	{
	public:

		///
		///Konstruktor domyœlny
		///
		SuperBicykle();

		///
		///Destruktor wirtualny
		///
		virtual ~SuperBicykle();
	};
}//namespace world
#endif//H_SUPER_BICYCKLE