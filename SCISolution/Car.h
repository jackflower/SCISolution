#ifndef H_CAR
#define H_CAR

///
///Klasa reprezentuje pojazd
///
class Car
{
public:

	///
	///Konstruktor domy�lny (ctor)
	///
	Car();

	///
	///Destruktor (dtor)
	///
	~Car();

	///
	///Metoda nadaje pr�dko��
	///
	///@param speed - nadawana pr�dko��
	///
	void setSpeed(float speed);

	///
	///Metoda zwraca pr�dko��
	///
	const float getSpeed() const;

private:

	int m_engine;//ilo�� silnik�w
	float m_speed;//pr�dko��
};

#endif//H_CAR
