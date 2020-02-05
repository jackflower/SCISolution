#ifndef H_SUPER_BICYCKLE
#define H_SUPER_BICYCKLE

#include "Bicykle.h"

namespace world
{
	///
	///Klasa (pochodna) reprezentuje klas� pochodn� rozszerzaj�c�
	///funkcjonalno�� klasy (bazowej) Bicykle
	///
	class SuperBicykle : public Bicykle
	{
	public:

		///
		///Konstruktor domy�lny
		///
		SuperBicykle();

		///
		///Destruktor wirtualny
		///
		virtual ~SuperBicykle();
	};
}//namespace world
#endif//H_SUPER_BICYCKLE