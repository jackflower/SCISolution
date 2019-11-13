//  __________________________________
// | SCILibrary.h -  definition       |
// | SCI - September 2015             |
// |__________________________________|

//wiêcej:
	
//porawna strona (raczej dla naluchów)
//http://www.algorytm.org/algorytmy/

//doskona³a strona - mój ogromny szacunek
//https://eduinf.waw.pl/
	
	
#ifndef H_SCI_LIBRARY
#define H_SCI_LIBRARY

#include <iostream>
#include <string>

using namespace std;

///
///Funkcja zamienia liczbê z systemu dziesiêtnego na system dwójkowy
///
///@param decimal - liczba w systemie dziesiêtnym
///
std::string DecToBin(int decimal);

///
///Funkcja zamienia liczbê z systemu dwójkowego na system dziesiêtny
///
///@param &binary - referencja na ³añcuch reprezentuj¹cy liczbê dwójkow¹
///
int BinToDec(std::string & binary);

///
///Funkcja zamienia liczbê z systemu ósemkowego na system dziesiêtny
///
///@param &octal - referencja na ³añcuch reprezentuj¹cy liczbê ósemkow¹
///
int OctalToDecimal(std::string & octal);

///
///Funkcja zamienia liczbê z dowolnego systemu na system dziesiêtny
///
///@param &number_in_any_system - referencja na ³añcuch reprezentuj¹cy liczbê zapisan¹ w rozpatrywanym systemie
///
///@param system - system liczbowy
///
int AnyToDec(std::string & number_in_any_system, int system = 2);

///
///Funkcja sprawdza, czy w tablicy znajduje siê szukana wartoœæ
///
///@param tab[] - tablica typu int zawieraj¹ca uporz¹dkowane dane (warunek konieczny!)
///
///@param tab_size - rozmiar tablicy
///
///@param value_searched - wartoœæ, której szukamy
///
bool BinarySearch(int tab[], int tab_size, int value_searched);

///
///Funkcja sprawdza, czy w tablicy znajduje siê szukana wartoœæ
///
///@param tab[] - tablica typu int
///
///@param tab_size - rozmiar tablicy
///
///@param value_searched - wartoœæ, której szukamy
///
bool LineSearch(int tab[], int tab_size, int value_searched);

///
///Funkcja losuje liczbê z przedzia³u obustronnie domkniêtego
///
///@param min - dolna wartoœæ zakresu
///
///@param max - górna wartoœæ zakresu
///
int Rand(int min, int max);

///
///Funkcja zwraca flagê, czy rok jest przestêpny
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
///Funkcja zamienia wartoœci z a na b i b na a
///
///@param & a - referencja na a
///
///@param & b - referencja na b
///
void Swap(int & a, int & b);

///
///Funkcja zwraca iloœæ cyfr podanej liczby
///
///@param liczba - liczba dla której wyliczamy z ilu sk³ada siê czyfr
///
short CounterDigit(int liczba);

///
///Funkcja sortuje zbiór (tablicê) metod¹ b¹belkow¹
///
///@param - tab[] - zbiór (tablica)
///
///@param size - rozmiar tablicy
///
void BubbleSort(int tab[], int size);

///
///Funkcja sortuje zbiór (tablicê) metod¹ b¹belkow¹
///
///@param - tab[] - zbiór (tablica)
///
///@param size - rozmiar tablicy
///
void BubbleSortEasy(int tab[], int size);

///
///Funkcja sortuje zbiór (tablicê) metod¹ przez wstawianie A
///
///@param - tab[] - zbiór (tablica)
///
///@param size - rozmiar tablicy
///
void InsertSortA(int tab[], int size);

///
///Funkcja sortuje zbiór (tablicê) metod¹ przez wstawianie B
///
///@param - tab[] - zbiór (tablica)
///
///@param size - rozmiar tablicy
///
void InsertSortB(int tab[], int size);

///
///Funkcja zwraca flagê, czy ³añcch jest palindromem
///
///@param & word - sta³a refrencja na obiekt klasy std::string
///
bool Palindrome(const std::string & word);

///
///Funkcja zwraca flagê, czy ³añcuch jest palindromem
///
///@param & word - sta³a refrencja na obiekt klasy std::string
///
bool Palindrom(const std::string & napis);

///
///Funkcja zwraca sumê cyfr liczy ca³kowitej
///
///@param value - liczba
///
int SumDigit(int value);

///
///Funkcja zwraca najwiêkszy wspólny dzielnik dwóch liczb
///
///@param a - pierwsza liczba
///
///@param b - druga liczba
///
int NWD(int a, int b);

///
///Funkcja zwraca najwiêkszy wspólny dzielnik dwóch liczb - wersj¹ zoptymalizowana
///
///@param a - pierwsza liczba
///
///@param b - druga liczba
///
int NWDZOptimized(int a, int b);

///
///Funkcja sprawdza, czy liczba jest liczb¹ pierwsz¹
///
///@param candidate - liczba do sprawdzenia
///
bool PrimeNumber(int candidate);

///
///Funkcja sprawdza, czy liczba jest liczb¹ pierwsz¹ - inne wersja
///
///@param candidate - liczba do sprawdzenia
///
bool Pierwsza(int candidate);

///
///Funkcja generuje liczby pierwsze z podanego zakresu: zbioru (tablicy)
///
///@param tab[] - wskaŸnik na tablicê
///
///@param n - rozmiar tablicy
///
void sitoEratostenesa(bool tab[], unsigned int n);

///
///Wyliczenie relacji dwóch liczb
///
enum EComparisons
{
	A_WIEKSZA_B = 0,
	A_MNIEJSZA_B = 1,
	A_ROWNA_B = 2
};

///
///Funkcja zwraca wynik porównania dwóch ³añcuchów
///
///@param &a - sta³a referencja na pierwszy ³añcuch do porównania
///
///@param &b - sta³a referencja na drugi ³añcuch do porównania
///
EComparisons Compare(const std::string & a, const std::string & b);

///
///Funckja zwraca pozycjê, od której wzorzec znajduje siê w tekœcie lub -1, gdy nie ma wzorca
///
///@param &text - sta³a referencja na obiekt klasy std::string - tekst
///
///@param &v - sta³a referencja na obiekt klasy std::string - wzorzec
///
int bruteforce(const std::string & text, const std::string & pattern);

///
///Funkcjê odwraca kolejnoœæ elementów tablicy - iteracyjnie
///
///@param *tab - wskaŸnik na tablicê
///
///@param left - lewy skrajny element tablicy
///
///@param right - prawy skrajny element tablicy
///
void odwrocIteration(int *tab, int left, int right);

///
///Funkcjê odwraca kolejnoœæ elementów tablicy - rekuracyjnie
///
///@param *tab - wskaŸnik na tablicê
///
///@param left - lewy skrajny element tablicy
///
///@param right - prawy skrajny element tablicy
///
void odwrocRecursion(int *tab, int left, int right);

///
///Funkcja rekurencyjna przeszukujaca tablicê celem znalezienia szukanej wartoœci
///
///@param tab[] - tablica
///
///@param left - lewa wartoœæ przedzia³u przeszukiwania
///
///@param right - prawa wartoœæ przedzia³u przeszukiwania
///
///@param x - x wartoœæ szukana
///
void szukajRekurencyjnie(int tab[], int left, int right, int x);

///
///Funkcja rejurencyjna oblicz¹j¹ca silniê
///
///@param x - parametr
///
unsigned long int silnia(int x);

///
///Funkcja iteracyjna oblicz¹j¹ca kolejny element ci¹gu Fibonacciego
///
///@param x - parametr
///
unsigned long int FibonacciIteration(int x);

///
///Funkcja rekurencyjna oblicz¹j¹ca kolejny element ci¹gu Fibonacciego
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
///Funkcja sprawdza, czy w tablicy znajduje siê szukana wartoœæ
///
///@param *tab - wskaŸnik na uporz¹dkowan¹ tablicê typu int (warunek konieczny)
///
///@param x - wartoœæ szukana
///
///@param left - lewa wartoœæ przedzia³u zbioru
///
///@param right - prawa wartoœæ przedzia³u zbioru
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
///Funkcja oblicza wartoœæ wielomianu - schemat Hornera - iteracyjnie
///
///@param wsp[] - tablica wspó³czynników
///
///@param st - stopieñ wielomianu
///
///@param x - wartoœæ x, dla którego liczymy wartoœæ wielomianu
///
int Horner_Iteration(int wsp[], int st, int x);

///
///Funkcja oblicza wartoœæ wielomianu - schemat Hornera - rekurencyjnie
///
///@param wsp[] - tablica wspó³czynników
///
///@param st - stopieñ wielomianu
///
///@param x - wartoœæ x, dla którego liczymy wartoœæ wielomianu
///
int Horner_Recursion(int wsp[], int st, int x);

///
///Funkcja zwraca element najczêœciej wystêpuj¹cy w tablicy (zbiorze) - dominant
///
///@param tab[] - tablica (wektor)
///
///@param size - rozmiar tablicy
///
int dominant(int tab[], int size);

///
///Funkcja zwraca wskaŸnik, pod którym znajduje siê
///dominant - element najczêœciej wystêpuj¹cy w tablicy (zbiorze)
///oraz iloœæ jego wyst¹pienia
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
///@param *tablica - wskaŸnik na tablicê
///
///@param lewy - indeks dla wartoœci skrajnej z lewej strony
///
///@param prawy - indeks dla wartoœci skrajnej z lewej strony
///
void quicksort(int *tablica, int lewy, int prawy);

///
///Rekurencyjna funkcja sortowania - QuickSort
///
///@param *tab - wskaŸnik na tablicê
///
///@param lewy - indeks dla wartoœci skrajnej z lewej strony
///
///@param prawy - indeks dla wartoœci skrajnej z lewej strony
///
void QuickSort(int *tab, int lewy, int prawy);

///
///Rekurencyjna funkcja sortowania - QuickSortAlpha
///
///@param *tab - wskaŸnik na tablicê
///
///@param lewy - indeks dla wartoœci skrajnej z lewej strony
///
///@param prawy - indeks dla wartoœci skrajnej z lewej strony
///
void QuickSortAlpha(int *tablica, int lewy, int prawy);

///
///Rekurencyjna funkcja sortowania - Qsort
///
///@param *tab - wskaŸnik na tablicê
///
///@param lewy - indeks dla wartoœci skrajnej z lewej strony
///
///@param prawy - indeks dla wartoœci skrajnej z lewej strony
///
void Qsort(int *tab, int left, int right);

///
///Funkcja zwraca medianê zbioru
///
///@param *tab - wskaŸnik na tablicê
///
///@param lewy - indeks dla wartoœci skrajnej z lewej strony
///
///@param prawy - indeks dla wartoœci skrajnej z lewej strony
///
int Mediana(int *tab, int left, int right);

///
///Funkcja realizuje problem dodawanie bardzo du¿ych liczb
///Prezentuj¹c jedno z wielu rozwi¹zañ, realizowane na przyk³adzie
///dodatnich liczb ca³kowitych - przechowywanych w obiektach std::string
///
///Funkcja zwraca ³añcuch znaków reprezentuj¹cy sumê liczba
///
///@param & number_1 - pierwszy sk³adnik - reprezentowany jako referencja na obiekt klasy std::string
///
///@param & number_2 - drugi sk³adnik - reprezentowany jako referencja na obiekt klasy std::string
///
std::string BigSum(std::string & number_1, std::string & number_2);

///
///Funkcja - wydawanie reszty
///
///@param reszta - reszta do wydania
///
void WydawanieReszty(int reszta);

///
///Funkcja zwraca jednoczeœnie minimum i maximum tablicy
///
///@param Tab[] - tablica
///
///@param size - rozmiar tablicy
///
void MiniMax(int Tab[], int size);

///
///Szyfrowanie - Funkcja zwraca zaszyfrowany obiekt std::string wed³ug klucza - Cezar
///
///@param slowo - obiekt std::string zawieraj¹cy treœæ jawn¹
///
///@param klucz - klucz
///
std::string Szyfrowanie(std::string slowo, int klucz);

///
///Deszyfrowanie - Funkcja zwraca rozszyfrowany obiekt std::string wed³ug klucza - Cezar
///
///@param slowo - obiekt std::string zawieraj¹cy treœæ zaszyfrowan¹
///
///@param klucz - klucz
///
std::string Deszyfrowanie(std::string slowo, int klucz);

///
///Funkcja sprawdza, czy dwa napisy (w jednej linii jawny i tajny, s¹ zakodowane
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
///@param size_i - iloœæ wierszy
///
///@param size_j - iloœæ kolumn
///
bool correct_index(int i, int j, int size_i, int size_j);

//Kierunki wzglêdem punktu tablicy (geografia - ró¿a wiatrów)
//opakowanie do zadania "Szachownica z monetami"
struct Directions
{
	//zgodnie z ruchem wskazówek zegara
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
//Ucinanie miejœæ po przecinku (zastosowaæ uniform)
//double n = 12.325252;   //twoja liczba
//int c, u;
//c = (int)n;                       //czêœæ ca³kowita
//u = n * 100;                     //czêœæ u³amkowa
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
