#include <iostream>
#include "Functions.h"
#include "ELight.h"
#include "ERate.h"
#include "Brick.h"
#include "Car.h"

#include "Bicykle.h"

using namespace world;

int main()
{
	Bicykle rower;

	rower.setWeight(1236.234f);
	std::cout << rower.getWeight() << std::endl;


	getchar();
	return 0;

}








/*
int liczba = 12;
int tajna = 45;

int &ref_na_liczbe = liczba;

std::cout << ref_na_liczbe << std::endl;

liczba = 23;

std::cout << ref_na_liczbe << std::endl;
ref_na_liczbe = 43;

std::cout << ref_na_liczbe << std::endl;
std::cout << liczba << std::endl;

//
ref_na_liczbe = tajna;
std::cout << liczba << std::endl;
std::cout << tajna << std::endl;
std::cout << ref_na_liczbe << std::endl;

*/