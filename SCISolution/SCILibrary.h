//  __________________________________
// | SCILibrary.h -  definition       |
// | SCI - September 2015             |
// |__________________________________|

//wi�cej:
	
//porawna strona (raczej dla naluch�w)
//http://www.algorytm.org/algorytmy/

//doskona�a strona - m�j ogromny szacunek
//https://eduinf.waw.pl/
	
	
#ifndef H_SCI_LIBRARY
#define H_SCI_LIBRARY

#include <iostream>
#include <string>

using namespace std;

///
///Funkcja zamienia liczb� z systemu dziesi�tnego na system dw�jkowy
///
///@param decimal - liczba w systemie dziesi�tnym
///
std::string DecToBin(int decimal);

///
///Funkcja zamienia liczb� z systemu dw�jkowego na system dziesi�tny
///
///@param &binary - referencja na �a�cuch reprezentuj�cy liczb� dw�jkow�
///
int BinToDec(std::string & binary);

///
///Funkcja zamienia liczb� z systemu �semkowego na system dziesi�tny
///
///@param &octal - referencja na �a�cuch reprezentuj�cy liczb� �semkow�
///
int OctalToDecimal(std::string & octal);

///
///Funkcja zamienia liczb� z dowolnego systemu na system dziesi�tny
///
///@param &number_in_any_system - referencja na �a�cuch reprezentuj�cy liczb� zapisan� w rozpatrywanym systemie
///
///@param system - system liczbowy
///
int AnyToDec(std::string & number_in_any_system, int system = 2);

///
///Funkcja sprawdza, czy w tablicy znajduje si� szukana warto��
///
///@param tab[] - tablica typu int zawieraj�ca uporz�dkowane dane (warunek konieczny!)
///
///@param tab_size - rozmiar tablicy
///
///@param value_searched - warto��, kt�rej szukamy
///
bool BinarySearch(int tab[], int tab_size, int value_searched);

///
///Funkcja sprawdza, czy w tablicy znajduje si� szukana warto��
///
///@param tab[] - tablica typu int
///
///@param tab_size - rozmiar tablicy
///
///@param value_searched - warto��, kt�rej szukamy
///
bool LineSearch(int tab[], int tab_size, int value_searched);

///
///Funkcja losuje liczb� z przedzia�u obustronnie domkni�tego
///
///@param min - dolna warto�� zakresu
///
///@param max - g�rna warto�� zakresu
///
int Rand(int min, int max);

///
///Funkcja zwraca flag�, czy rok jest przest�pny
///
///@param year - rok
///
bool checkYear(int year);

///
///Funkcja konwerstuje typ int na std::string
///
///@param value - liczba typu int
///
std::string IntToString(int value);

///
///Funkcja zamienia warto�ci z a na b i b na a
///
///@param & a - referencja na a
///
///@param & b - referencja na b
///
void Swap(int & a, int & b);

///
///Funkcja zwraca ilo�� cyfr podanej liczby
///
///@param liczba - liczba dla kt�rej wyliczamy z ilu sk�ada si� czyfr
///
short CounterDigit(int liczba);

///
///Funkcja sortuje zbi�r (tablic�) metod� b�belkow�
///
///@param - tab[] - zbi�r (tablica)
///
///@param size - rozmiar tablicy
///
void BubbleSort(int tab[], int size);

///
///Funkcja sortuje zbi�r (tablic�) metod� b�belkow�
///
///@param - tab[] - zbi�r (tablica)
///
///@param size - rozmiar tablicy
///
void BubbleSortEasy(int tab[], int size);

///
///Funkcja sortuje zbi�r (tablic�) metod� przez wstawianie A
///
///@param - tab[] - zbi�r (tablica)
///
///@param size - rozmiar tablicy
///
void InsertSortA(int tab[], int size);

///
///Funkcja sortuje zbi�r (tablic�) metod� przez wstawianie B
///
///@param - tab[] - zbi�r (tablica)
///
///@param size - rozmiar tablicy
///
void InsertSortB(int tab[], int size);

///
///Funkcja zwraca flag�, czy �a�cch jest palindromem
///
///@param & word - sta�a refrencja na obiekt klasy std::string
///
bool Palindrome(const std::string & word);

///
///Funkcja zwraca flag�, czy �a�cuch jest palindromem
///
///@param & word - sta�a refrencja na obiekt klasy std::string
///
bool Palindrom(const std::string & napis);

///
///Funkcja zwraca sum� cyfr liczy ca�kowitej
///
///@param value - liczba
///
int SumDigit(int value);

///
///Funkcja zwraca najwi�kszy wsp�lny dzielnik dw�ch liczb
///
///@param a - pierwsza liczba
///
///@param b - druga liczba
///
int NWD(int a, int b);

///
///Funkcja zwraca najwi�kszy wsp�lny dzielnik dw�ch liczb - wersj� zoptymalizowana
///
///@param a - pierwsza liczba
///
///@param b - druga liczba
///
int NWDZOptimized(int a, int b);

///
///Funkcja sprawdza, czy liczba jest liczb� pierwsz�
///
///@param candidate - liczba do sprawdzenia
///
bool PrimeNumber(int candidate);

///
///Funkcja sprawdza, czy liczba jest liczb� pierwsz� - inne wersja
///
///@param candidate - liczba do sprawdzenia
///
bool Pierwsza(int candidate);

///
///Funkcja generuje liczby pierwsze z podanego zakresu: zbioru (tablicy)
///
///@param tab[] - wska�nik na tablic�
///
///@param n - rozmiar tablicy
///
void sitoEratostenesa(bool tab[], unsigned int n);

///
///Wyliczenie relacji dw�ch liczb
///
enum EComparisons
{
	A_WIEKSZA_B = 0,
	A_MNIEJSZA_B = 1,
	A_ROWNA_B = 2
};

///
///Funkcja zwraca wynik por�wnania dw�ch �a�cuch�w
///
///@param &a - sta�a referencja na pierwszy �a�cuch do por�wnania
///
///@param &b - sta�a referencja na drugi �a�cuch do por�wnania
///
EComparisons Compare(const std::string & a, const std::string & b);

///
///Funckja zwraca pozycj�, od kt�rej wzorzec znajduje si� w tek�cie lub -1, gdy nie ma wzorca
///
///@param &text - sta�a referencja na obiekt klasy std::string - tekst
///
///@param &v - sta�a referencja na obiekt klasy std::string - wzorzec
///
int bruteforce(const std::string & text, const std::string & pattern);

///
///Funkcj� odwraca kolejno�� element�w tablicy - iteracyjnie
///
///@param *tab - wska�nik na tablic�
///
///@param left - lewy skrajny element tablicy
///
///@param right - prawy skrajny element tablicy
///
void odwrocIteration(int *tab, int left, int right);

///
///Funkcj� odwraca kolejno�� element�w tablicy - rekuracyjnie
///
///@param *tab - wska�nik na tablic�
///
///@param left - lewy skrajny element tablicy
///
///@param right - prawy skrajny element tablicy
///
void odwrocRecursion(int *tab, int left, int right);

///
///Funkcja rekurencyjna przeszukujaca tablic� celem znalezienia szukanej warto�ci
///
///@param tab[] - tablica
///
///@param left - lewa warto�� przedzia�u przeszukiwania
///
///@param right - prawa warto�� przedzia�u przeszukiwania
///
///@param x - x warto�� szukana
///
void szukajRekurencyjnie(int tab[], int left, int right, int x);

///
///Funkcja rejurencyjna oblicz�j�ca silni�
///
///@param x - parametr
///
unsigned long int silnia(int x);

///
///Funkcja iteracyjna oblicz�j�ca kolejny element ci�gu Fibonacciego
///
///@param x - parametr
///
unsigned long int FibonacciIteration(int x);

///
///Funkcja rekurencyjna oblicz�j�ca kolejny element ci�gu Fibonacciego
///
///@param x - parametr
///
unsigned long int FibonacciRecursion(int x);

///
///Funkcja rejurencyjna MacCarthy'ego
///
///@param x - parametr
///
unsigned long int MacCarthy(int x);

///
///Funkcja niebezpieczna
///
///@param n
///
///@param p
///
int Danger(int n, int p);

///
///Funkcja sprawdza, czy w tablicy znajduje si� szukana warto��
///
///@param *tab - wska�nik na uporz�dkowan� tablic� typu int (warunek konieczny)
///
///@param x - warto�� szukana
///
///@param left - lewa warto�� przedzia�u zbioru
///
///@param right - prawa warto�� przedzia�u zbioru
///
bool BinarySearchRecursion(int *tab, int x, int left, int right);

///
///Funkcja Ackermanna
///
///@param n
///
///@param p
///
int Ackermann(int n, int p);

///
///Funkcja oblicza warto�� wielomianu - schemat Hornera - iteracyjnie
///
///@param wsp[] - tablica wsp�czynnik�w
///
///@param st - stopie� wielomianu
///
///@param x - warto�� x, dla kt�rego liczymy warto�� wielomianu
///
int Horner_Iteration(int wsp[], int st, int x);

///
///Funkcja oblicza warto�� wielomianu - schemat Hornera - rekurencyjnie
///
///@param wsp[] - tablica wsp�czynnik�w
///
///@param st - stopie� wielomianu
///
///@param x - warto�� x, dla kt�rego liczymy warto�� wielomianu
///
int Horner_Recursion(int wsp[], int st, int x);

///
///Funkcja zwraca element najcz�ciej wyst�puj�cy w tablicy (zbiorze) - dominant
///
///@param tab[] - tablica (wektor)
///
///@param size - rozmiar tablicy
///
int dominant(int tab[], int size);

///
///Funkcja zwraca wska�nik, pod kt�rym znajduje si�
///dominant - element najcz�ciej wyst�puj�cy w tablicy (zbiorze)
///oraz ilo�� jego wyst�pienia
///
///@param tab[] - tablica (wektor)
///
///@param size - rozmiar tablicy
///
int *Dominant(int tab[], int size);

///
///Rekurencyjna funkcja sortowania - quicksort
///http://miroslawzelent.pl/wyklady/sortowanie-szybkie-quicksort-dziel-zwyciezaj.pdf
///
///@param *tablica - wska�nik na tablic�
///
///@param lewy - indeks dla warto�ci skrajnej z lewej strony
///
///@param prawy - indeks dla warto�ci skrajnej z lewej strony
///
void quicksort(int *tablica, int lewy, int prawy);

///
///Rekurencyjna funkcja sortowania - QuickSort
///
///@param *tab - wska�nik na tablic�
///
///@param lewy - indeks dla warto�ci skrajnej z lewej strony
///
///@param prawy - indeks dla warto�ci skrajnej z lewej strony
///
void QuickSort(int *tab, int lewy, int prawy);

///
///Rekurencyjna funkcja sortowania - QuickSortAlpha
///
///@param *tab - wska�nik na tablic�
///
///@param lewy - indeks dla warto�ci skrajnej z lewej strony
///
///@param prawy - indeks dla warto�ci skrajnej z lewej strony
///
void QuickSortAlpha(int *tablica, int lewy, int prawy);

///
///Rekurencyjna funkcja sortowania - Qsort
///
///@param *tab - wska�nik na tablic�
///
///@param lewy - indeks dla warto�ci skrajnej z lewej strony
///
///@param prawy - indeks dla warto�ci skrajnej z lewej strony
///
void Qsort(int *tab, int left, int right);

///
///Funkcja zwraca median� zbioru
///
///@param *tab - wska�nik na tablic�
///
///@param lewy - indeks dla warto�ci skrajnej z lewej strony
///
///@param prawy - indeks dla warto�ci skrajnej z lewej strony
///
int Mediana(int *tab, int left, int right);

///
///Funkcja realizuje problem dodawanie bardzo du�ych liczb
///Prezentuj�c jedno z wielu rozwi�za�, realizowane na przyk�adzie
///dodatnich liczb ca�kowitych - przechowywanych w obiektach std::string
///
///Funkcja zwraca �a�cuch znak�w reprezentuj�cy sum� liczba
///
///@param & number_1 - pierwszy sk�adnik - reprezentowany jako referencja na obiekt klasy std::string
///
///@param & number_2 - drugi sk�adnik - reprezentowany jako referencja na obiekt klasy std::string
///
std::string BigSum(std::string & number_1, std::string & number_2);

///
///Funkcja - wydawanie reszty
///
///@param reszta - reszta do wydania
///
void WydawanieReszty(int reszta);

///
///Funkcja zwraca jednocze�nie minimum i maximum tablicy
///
///@param Tab[] - tablica
///
///@param size - rozmiar tablicy
///
void MiniMax(int Tab[], int size);

///
///Szyfrowanie - Funkcja zwraca zaszyfrowany obiekt std::string wed�ug klucza - Cezar
///
///@param slowo - obiekt std::string zawieraj�cy tre�� jawn�
///
///@param klucz - klucz
///
std::string Szyfrowanie(std::string slowo, int klucz);

///
///Deszyfrowanie - Funkcja zwraca rozszyfrowany obiekt std::string wed�ug klucza - Cezar
///
///@param slowo - obiekt std::string zawieraj�cy tre�� zaszyfrowan�
///
///@param klucz - klucz
///
std::string Deszyfrowanie(std::string slowo, int klucz);

///
///Funkcja sprawdza, czy dwa napisy (w jednej linii jawny i tajny, s� zakodowane
///takim samym kluczem (znak po znaku - ten sam klucz)
///
///@param slowo - napis jawny
///
///@param szyfr - napis zaszyfrowany
///
bool TestujSzyfr(std::string slowo, std::string szyfr);

///
///Funkcja sprawdza, czy indeks tablicy dwuwymiarowej jest poprawny
///
///@param i - wiersz
///
///@param j - kolumna
///
///@param size_i - ilo�� wierszy
///
///@param size_j - ilo�� kolumn
///
bool correct_index(int i, int j, int size_i, int size_j);

//Kierunki wzgl�dem punktu tablicy (geografia - r�a wiatr�w)
//opakowanie do zadania "Szachownica z monetami"
struct Directions
{
	//zgodnie z ruchem wskaz�wek zegara
	int NORTH = 0;
	int NORTH_EAST = 0;
	int EAST = 0;
	int SOUTH_EAST = 0;
	int SOUTH = 0;
	int SOUTH_WEST = 0;
	int WEST = 0;
	int NORTH_WEST = 0;
};

//Rekurencja - alpha
void test(int n);

//Rekurencja - beta
void Odliczanie(int i);

//Rekurencja - gamma
long long suma(int n);

//Rekurencja - delta
void zamien(int n);


bool czy_anagram_One(char *a, char *b);
void sortuj(string &napis);
bool czy_anagramy_Two(string napis1, string napis2);


#endif//H_SCI_LIBRARY


/*
//Ucinanie miej�� po przecinku (zastosowa� uniform)
//double n = 12.325252;   //twoja liczba
//int c, u;
//c = (int)n;                       //cz�� ca�kowita
//u = n * 100;                     //cz�� u�amkowa
//u %= 100;
//cout << c << "." << u;
*/

/*
void decimal_to_ternary(int liczba)
{
int reszta = liczba % 3;
if (liczba > 1) decimal_to_ternary(liczba / 3);
std::cout << reszta;
return;
}
*/

/*
Liczby rzymskie...
#include <iostream>
#include <string.h>

using namespace std;
const int N = 13;

int main()
{
string rom[N] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int dec[N] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
int x;
string lr = "";

cout << "Podaj dowolna liczbe: " << endl;
cin >> x;

for (int i = 0; i < N; i++)
while (dec[i] <= x)
{
lr += rom[i];
x -= dec[i];
}

cout << "W notacji rzymskiej to: " << lr << endl;
return 0;
}

*/
