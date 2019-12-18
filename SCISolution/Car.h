#ifndef H_CAR
#define H_CAR

#include <vector>

///
///Klasa reprezentuje pojazd
///
class Car
{
public:

	///
	///Konstruktor domyślny (ctor)
	///
	Car();

	///
	///Konstruktor parametryczny
	///
	///@param speed  -nadana prędkość
	///
	Car(float speed);

	///
	///Konstruktor parametryczny alfa
	///
	///@param speed  -nadana prędkość
	///
	///@param unique ID
	///
	Car(float speed, int unique_id);

	///
	///Destruktor (dtor)
	///
	~Car();

	///
	///Metoda nadaje prędkość
	///
	///@param speed - nadawana prędkość
	///
	void setSpeed(float speed);

	///
	///Metoda zwraca prędkość
	///
	const float getSpeed() const;

	///
	///Metoda dodaje do bagażnika bagaż
	///
	///@param any - coś całkowitego
	///
	void addBag(int any);

private:

	int m_engine;//ilość silników
	float m_speed;//prędkość
	const int id_noname;//unikalna wartość
	std::vector<int> m_bag;

};

#endif//H_CAR
