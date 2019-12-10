#ifndef H_CAR
#define H_CAR

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

private:

	int m_engine;//ilość silników
	float m_speed;//prędkość
};

#endif//H_CAR
