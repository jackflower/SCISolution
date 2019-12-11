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

	private:

		float m_weight;//notacja węgierska
		float m_tire;

	};

#endif//H_BICYCKLE
}