//  ____________________________________
// | Point2D.cpp - class implementation |
// | SCI - April 2020                   |
// |____________________________________|
//

#include "Point2D.h"
#include <utility>

//Konstruktor domyślny
Point2D::Point2D()
	: x_coordinate{ 0.0f }, y_coordinate{ 0.0f }
{
}

//Konstruktor parametryczny
Point2D::Point2D(float x, float y)
	: x_coordinate{ x }, y_coordinate{ y }
{
}

//Konstruktor kopiujący
Point2D::Point2D(const Point2D & copy)
	: x_coordinate{ copy.x_coordinate }, y_coordinate{ copy.y_coordinate }
{
}

//Konstruktor przenoszący
Point2D::Point2D(Point2D && other)
	//: x_coordinate{ other.x_coordinate }, y_coordinate{ other.y_coordinate }
	: x_coordinate{ std::move(other.x_coordinate) }, y_coordinate{ std::move(other.x_coordinate) }
{
}

Point2D::~Point2D()
{
	x_coordinate = 0.0f;
	y_coordinate = 0.0f;
}

//Metoda zwraca współrzędną punktu dla osi x
const float Point2D::getCoordinate_X() const
{
	return x_coordinate;
}

//Metoda ustawia współrzędną osi x
void Point2D::setCoordinate_X(float x)
{
	x_coordinate = x;
}

//Metoda zwraca współrzędną punktu dla osi y
const float Point2D::getCoordinate_Y() const
{
	return y_coordinate;
}

//Metoda ustawia współrzędną punktu dla osi y
void Point2D::setCoordinate_Y(float y)
{
	y_coordinate = y;
}

//Metoda ustawia współrzędne punktu dla osi x i osi y
void Point2D::setCoordinates(float x, float y)
{
	x_coordinate = x;
	y_coordinate = y;
}

//Metoda ustawia współrzędne punktu dla osi x i osi y
void Point2D::setCoordinates(const Point2D & point)
{
	setCoordinates(point.x_coordinate, point.y_coordinate);
}
