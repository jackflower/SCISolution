#ifndef H_CAR
#define H_CAR

///
///Klasa reprezentuje pojazd
///
class Car
{
public:

	///
	///Konstruktor domyœlny (ctor)
	///
	Car();

	///
	///Destruktor (dtor)
	///
	~Car();

	///
	///Metoda nadaje prêdkoœæ
	///
	///@param speed - nadawana prêdkoœæ
	///
	void setSpeed(float speed);

	///
	///Metoda zwraca prêdkoœæ
	///
	const float getSpeed() const;

private:

	int m_engine;//iloœæ silników
	float m_speed;//prêdkoœæ
};

#endif//H_CAR
