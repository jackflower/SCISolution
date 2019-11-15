#include "Functions.h"

//Funckja podwaja wartość parametru
void doubling(int & value)
{
	value = value * 2;
}

//Funkcja zwraca sumę dwóch liczb całkowitych
int sum(int a, int b)
{
	return (a + b);
}

//Funkcja zamienia wartości paramatrów
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Funkcja zwraca większą liczbę w dwóch liczb całkowitych
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

//Funkcja zwraca większą liczbę w trzech liczb całkowitych
int max(int a, int b, int c)
{
	int max = a;//zakłdamy, że max to a
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}

//Mateusz
int max3(int a, int b, int c)
{
	if (b > a)
		a = b;
	if (c > a)
		return c;
	return a;
}

//Funckja zwraca maksymalną wartość ze zbioru (tablica)
float maximum(float tab[], int tab_size)
{
	float candidate_max = tab[0];

	for (int i = 0; i < tab_size; i++)
		if (tab[i] > candidate_max)
			candidate_max = tab[i];

	return candidate_max;
}

//Funkcja zwraca średnią arytmetyczną
float average(int a, int b)
{
	//lepiej mnożyć przez ułamek 0.f5, niż dzielić przez 2
	return ((a + b) * 0.5f);
}

//Funkcja zwraca wartość bezwzględną podanej liczby całkowitej
int abs(int a)
{
	if (a < 0)
		return -a;
	return a;
	//sposób - zapis stosowany w jezyku C
	//return (a < 0 ? -a : a);
}


//Funkcja red - realizuje zliczanie kulek w pudełku
int red(const int kulki[], int rozmiar, int to_count)
{
	int czerwone = 0;
	for (int i = 0; i < rozmiar; i++)
		if (kulki[i] == to_count)
			czerwone++;
	return czerwone;
}

//Funkcja zwraca część dziesiętną
float decimalPart(float value)
{
	return (value - (int)value);
}

//Funkcja sprawdza, czy liczba jest parzysta
bool isEven(int value)
{
	if (value % 2 == 0)
		return true;
	return false;

	//lepszy sposób
	//return !(value % 2);
}

//Funkcja zwraca flagę, czy rok jest przestępny
bool leapYear(int year)
{
	//operatory logiczne - poczytać...
	//&& operator AND	- koniunkcja
	//|| operator OR	- alternatywa

	//rok jest przestępny wtedy i tylko wtedy gdy:
	//dzieli się przez 4 i nie dzieli się przez 100,
	//za wyjątkiem lat podzielnych przez 400
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
