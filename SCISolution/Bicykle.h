#ifndef H_BICYCKLE
#define H_BICYCKLE


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
		///Destruktor
		///
		~Bicykle();

		int alfa();//metoda


	private:

		float m_weight;//notacja węgierska
		float m_tire;

	};

#endif//H_BICYCKLE
}