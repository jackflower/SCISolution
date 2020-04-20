//  ____________________________________
// | Point2D.h - class definition       |
// | SCI - April 2020                   |
// |____________________________________|
//

#ifndef H_POINT_SCI
#define H_POINT_SCI

///
///Klasa reprezentuje punkt w dwuwymiarowym układzie kartezjański
///
class Point2D
{
public:

	///
	///Konstruktor domyślny
	///
	Point2D();

	///
	///Konstruktor parametryczny
	///
	///@param x - wartość współrzędnej x
	///
	///@param y - wartość współrzędnej y
	///
	Point2D(float x, float y);

	///
	///Konstruktor kopiujący
	///
	///@param copy - stała referecja na obiekt klasy Point2D
	///
	Point2D(const Point2D & copy);

	///
	///Konstruktor przenoszący
	///
	///@param other - referencja do r-wartości
	///
	Point2D(Point2D && other);

	///
	///Destruktor
	///
	~Point2D();

	///
	///Metoda zwraca współrzędną punktu dla osi x
	///
	const float getCoordinate_X() const;

	///
	///Metoda ustawia współrzędną punktu dla osi x
	///
	///@param x - wartość współrzędnej x
	///
	void setCoordinate_X(float x);

	///
	///Metoda zwraca współrzędną punktu dla osi y
	///
	const float getCoordinate_Y() const;

	///
	///Metoda ustawia współrzędną punktu dla osi y
	///
	///@param y - wartość współrzędnej y
	///
	void setCoordinate_Y(float y);

	///
	///Metoda ustawia współrzędne punktu dla osi x i osi y
	///
	///@param x - wartość współrzędnej x
	///
	///@param y - wartość współrzędnej y
	///
	void setCoordinates(float x, float y);

	///
	///Metoda ustawia współrzędne punktu dla osi x i osi y
	///
	///@param point - stała referencja na obiekt klasy Point2D
	///
	void setCoordinates(const Point2D & point);

private:

	float x_coordinate;//współrzędna osi x
	float y_coordinate;//współrzędna osi y
};

#endif//H_POINT_SCI
