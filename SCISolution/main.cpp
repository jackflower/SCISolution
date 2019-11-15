#include <iostream>
#include "Functions.h"
#include "Tea.h"

int main()
{
	//tablica na 10 elementów typu int
	int tablica[10];

	//tablica na pięć elementów typu int
	//wraz z ich zainicjowaniem wartościami
	//podanymi w nawiasach klamrowych
	int tab[5] = { 1, 45, -6, 12, 78 };

	//deklaracja rozmiaru tablicy
	//musi być const
	const int rozmiar = 100;
	//tablica o takim rozmiarze
	//(zapis w nawiasach klamrowych
	//spowoduje, że wszystkie elementy tablicy
	//będą miały wartość 0
	int centurion[rozmiar] = { 0 };

	//elementowi ósmemu - pod indeksem siódmym
	//nadajemy wartość 123
	centurion[7] = 123;


	int liczba = 10;
	doubling(liczba);//wywołanie funckji z argumentem o wartości 10
	//po wykonaniu funkcji zmienna liczba będzie miała wartość 20
	


	getchar();
	return 0;
}

