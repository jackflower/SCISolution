#ifndef H_SCI
#define H_SCI

///
///Funkcja podwaja wartość parametru
///
///@param value - referencja
///
void doubling(int & value);

///
///Funkcja zwraca sumę dwóch liczb całkowitych
///
///@param a - parametr - składnik
///
///@param b - parametr - składnik
int sum(int a, int b);

///
///Funkcja zamienia wartości paramatrów
///
///@param a - referencja - pierwsza wartość
///
///@param b - referencja - pierwsza wartość
///
void swap(int& a, int& b);


///
///Funkcja (przeciążona - overloading ) zwraca większą liczbę w dwóch liczb całkowitych
///
///@param a - pierwsza wartość
///
///@param b - druga wartość
///
int max(int a, int b);


///
///Funkcja  (przeciążona - overloading ) zwraca większą liczbę w trzech liczb całkowitych
///
///@param a - pierwsza wartość
///
///@param b - druga wartość
///
///@param c - trzecia wartość
///
int max(int a, int b, int c);


///
///Funkcja  (przeciążona - overloading ) zwraca większą liczbę w trzech liczb całkowitych
///
///@param a - pierwsza wartość
///
///@param b - druga wartość
///
///@param c - trzecia wartość
///
int max3(int a, int b, int c);


///
///Funckja zwraca maksymalną wartość ze zbioru (tablica)
///
///@param tab[] - tablica typu float
///
///@param tab_size - rozmiar tablicy
///
float maximum(float tab[], int tab_size);


///
///Funkcja zwraca średnią arytmetyczną
///
///@param a - liczba całkowita
///
///@param b - liczba całkowita
///
float average(int a, int b);


///
///Funkcja zwraca wartość bezwzględną podanej liczby całkowitej
///
///@param a - wartość całkowita
///
int abs(int a);


///
///Funkcja red - realizuje zliczanie kulek w pudełku
///
///@param kulki[] - tablica typu int
///
///@param rozmiar - rozmiar tablicy
///
///@param to_count - wartość z tablicy do zszumowania
///
int red(const int kulki[], int rozmiar, int to_count);


///
///Funkcja zwraca część dziesiętną
///
///@param value - liczba
///
float decimalPart(float value);


///
///Funkcja sprawdza, czy liczba jest parzysta
///
///@param value  -liczba
///
bool isEven(int value);

///
///Funkcja zwraca flagę, czy rok jest przestępny (and. leap year)
///
///@param year - rok
///
bool leapYear(int year);

///
///Funkcja mnoży każdy element tablicy przez dwa
///
///@param tab[] - tablica
///
///@param tab_size - rozmiar tablicy
///
void doublingTab(int tab[], int tab_size);

#endif//H_SCI
