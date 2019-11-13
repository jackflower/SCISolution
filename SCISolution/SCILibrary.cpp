//  __________________________________
// | SCILibrary.cpp -  implementation |
// | SCI - September 2015             |
// |__________________________________|

#include "SCILibrary.h"
#include <sstream>

//Funkcja zamienia liczb� z systemu dziesi�tnego na system dw�jkowy
std::string DecToBin(int decimal)
{
	//zmienne pomocnicze lokalne
	int liczba = decimal;		//liczba, kt�r� zamieniamy - inicjujemy j� parametrem
	std::string binary = "";	//liczba binarna postaci ci�gu zer i jedynek,
								//kt�r� ta funkcja wygenruje - inicjujemy pustym
								//�a�cuchem

	//kosmetyka...
	if (liczba == 0)
		return "0";				//bo inaczej nie wejdziemy do p�tli while(...)

	//algorytm...

	while (liczba)						//dop�ki liczba jest r�na od zera
	{
		if (liczba % 2 == 0)			//je�li wyra�enie modulo zwraca 0
			binary = "0" + binary;		//do �a�cucha (tablica char) wstawiamy "0" - cyfr� zero
		else
			binary = "1" + binary;		//w przeciwnym wypadku  wstawiamy "1" - cyfr� zero
		liczba /= 2;					//dzielimy liczb� na dwa (system dw�jkowy)
	}
							
	return binary;
}

//Funkcja zamienia liczb� z systemu dw�jkowego na system dziesi�tny
int BinToDec(std::string & binary)
{
	//zmienne pomocnicze...
	int x;							//odczytany element �a�cucha zamieniony na zero lub jedenk�
	int power = 1;					//wyk�adnik pot�gowania
	int dlugosc = binary.length();	//wyliczamy d�ugo�� std::string binary
	int system = 2;					//operujemy na systemie dw�jkowym
	int result = 0;					//wyliczona liczba dziesi�tna, kt�r� zwraca ta fukcja

	//zaczynamy od ko�ca �a�cucha (tablicy)...
	for (int i = dlugosc - 1; i >= 0; i--)
	{
		if (binary[i] == '1') x = 1;
		if (binary[i] == '0') x = 0;
		result += x * power;		//do wyniku dodajemy otrzyman� warto��,
									//kt�r� mno�ymy przez podstaw� systemu do odpowiedniej pot�gi
		power *= system;			//ustawiamy power (wyk�adnik) na odpowiedni� poteg� systemu (2)
	}
	return result;
}

//Funkcja zamienia liczb� z systemu �semkowego na system dziesi�tny
int OctalToDecimal(std::string & octal)
{
	//zmienne pomocnicze...
	int x;							//odczytany element �a�cucha zamieniony na liczby <0..7> - tyle ich jest w systemie �semkowym
	int power = 1;					//wyk�adnik pot�gowania
	int dlugosc = octal.length();	//wyliczamy d�ugo�� std::string octal
	int system = 8;					//operujemy na systemie �semkowym
	int result = 0;					//wyliczona liczba dziesi�tna, kt�r� zwraca ta fukcja

	//zaczynamy od ko�ca �a�cucha (tablicy)...
	for (int i = dlugosc - 1; i >= 0; i--)
	{
		if (octal[i] == '0') x = 0;
		if (octal[i] == '1') x = 1;
		if (octal[i] == '2') x = 2;
		if (octal[i] == '4') x = 4;
		if (octal[i] == '3') x = 3;
		if (octal[i] == '5') x = 5;
		if (octal[i] == '6') x = 6;
		if (octal[i] == '7') x = 7;
		result += x * power;		//do wyniku dodajemy otrzyman� warto��,
									//kt�r� mno�ymy przez podstaw� systemu
									//do odpowiedniej pot�gi
		power *= system;			//ustawiamy power (wyk�adnik) na odpowiedni� poteg� systemu (2)
	}
	return result;
}


//Funkcja zamienia liczb� z dowolnego systemu na system dziesi�tny
int AnyToDec(std::string & number_in_any_system, int system)
{
	int x;							//odczytany element �a�cucha
	int wynik = 0;					//warto��, kt�r� zwraca ta funkcja
	int power = 1;					//pot�ga
	int dlugosc = number_in_any_system.length();//wyliczamy d�ugo�� std::string binary

	//zaczynamy od ko�ca tablicy...
	for (int i = dlugosc - 1; i >= 0; i--)
	{
		//je�eli odczytany element �a�cucha jest cyfr�...
		if (number_in_any_system[i] >= '0' && number_in_any_system[i] <= '9')
			//odejmujemy kod zera - zamieniamy kod cyfry na cyfr�
			x = number_in_any_system[i] - '0';
		else
			//je�eli jest to litera (musi byc du�a)
			x = number_in_any_system[i] - 55;//to odejmujemy 55 np. A(65) - 55 = 10

		//do wyniku dodajemy otrzyman� warto��
		//pomno�on� przez podstaw� systemu do odpowiedniej pot�gi
		wynik += x * power; 
		power *= system; // ustawiamy power(wyk�adnik) na odpowiedni� poteg� systemu
	}

	return wynik;
}

//Binary Search - implementacja
bool BinarySearch(int tab[], int tab_size, int value_searched)
{
	//zak�adamy, �e przeszukujemy tablic� w pe�nym zakresie
	//czyli ca�� tablic� od indeksu 0 do ostatniego elementu
	int l = 0;			//pocz�tek tablicy
	int r = tab_size;	//koniec tablicy
	int sr= (l + r)/2;	//indeks - wyliczany �rodek (miejsce) indeks
	bool result = false;//flaga okre�la, czy w tablicy znajduje si� szukana warto��
						//na pocz�tku zak�adamy, �e nie...

	std::cout << "Elementy tablicy:" << std::endl;

	for (int i = 0; i < tab_size; i++)
		std::cout << tab[i] << "  ";

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Szukamy w talicy wartosci: " << value_searched  << std::endl;


	while (l <= r)
	{
		sr = (l + r) / 2;//wyliczamy �rodek
		if (tab[sr] == value_searched)//je�li szukana jest w tablicy...
		{
			//mo�na o tym poinformowa�...
			std::cout << std::endl;
			std::cout << "znaleziono wartosc: "
				<< value_searched
				<< " pod indeksem: "
				<< sr
				<< std::endl
				<< std::endl;
			result = true;
		}
		if (tab[sr] > value_searched)
			r = sr - 1;
		else
			l = sr + 1;
	}

	if(!result)
		std::cout << "Nie znaleziono..." << std::endl;

	return result;
}

//Funkcja sprawdza, czy w tablicy znajduje si� szukana warto��
bool LineSearch(int tab[], int tab_size, int value_searched)
{
	for (int i = 0; i < tab_size; i++)
		if (tab[i] == value_searched)
			return true;
	return false;
}

//Funkcja losuje liczb� z przedzia�u obustronnie domkni�tego
int Rand(int min, int max)
{
	//P a m i � t a j !!! - ziarno
	//Zawsze ustawiaj tylko jeden raz
	//np: w main() - zaraz na pocz�tku kodu
	//poprawne wywo�anie funkcji:
	//	srand((unsigned)time(NULL));

	int pseudolosowa = ((rand() % (max - min + 1))) + (min);
	return pseudolosowa;//nasza cywilizacja potrafi za pomoc�
						//komputer�w generowa� tylko liczby
						//p s e u d o l o s o w e
}

//Funkcja zwraca flag�, czy rok jest przest�pny
bool checkYear(int year)
{
	//operatory logiczne - poczyta�...
	//&& operator AND	- koniunkcja
	//|| operator OR	- alternatywa

	//rok jest przest�pny wtedy i tylko wtedy gdy:
	//dzieli si� przez 4 i nie dzieli si� przez 100,
	//za wyj�tkiem lat podzielnych przez 400
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

//Funkcja konwerstuje typ int na std::string
std::string IntToString(int value)
{
	std::stringstream ssBufor;	//stringstream...bufor
	std::string sWynik;			//zwyk�y string - to zwraca funkcja
	ssBufor << value;			//wysy�amy liczb� int do bufora
	ssBufor >> sWynik;			//przepisujemy z bufora do zwyk�ego stringa,
								//z kt�rym mo�emy ju� sobie "poradzi�"...
	return sWynik;
}

//Funkcja zamienia warto�ci z a na b i b na a
void Swap(int & a, int & b)
{
	int pom = a;//zapami�tano a
	a = b;		//do a przekazuj� b
	b = pom;	//do b przekazuj� zapami�tane a
}

//Funkcja zwraca ilo�� cyfr podanej liczby
short CounterDigit(int liczba)
{
	short counter_digit = 0;//licznik cyfr
	if (liczba == 0) counter_digit = 1;
	while (liczba != 0)
	{
		counter_digit++;
		liczba /= 10;//jest to system dziesi�tny
	}
	return counter_digit;
}


//Funkcja sortuje zbi�r (tablic�) metod� b�belkow�
void BubbleSort(int tab[], int size)
{
	int temp;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++) //p�tla wewn�trzna
			if (tab[j] > tab[j + 1])
			{
				//zamiana miejscami je�li warunek jest spe�niony
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
}

//Funkcja sortuje zbi�r (tablic�) metod� b�belkow�
void BubbleSortEasy(int tab[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (tab[j] > tab[j + 1])
				Swap(tab[j], tab[j + 1]);//zamiana miejscami je�li warunek jest spe�niony
		}
	}
}

//Funkcja sortuje zbi�r (tablic�) metod� przez wstawianie A
void InsertSortA(int tab[], int size)
{
	int pom, j;
	for (int i = 1; i < size; i++)//zaczyna itreracj� od drugiego elementu
	{
		//wstawienie elementu w odpowiednie miejsce
		pom = tab[i];	//ten element b�dzie wstawiony w odpowiednie miejsce
		j = i - 1;		//element nast�pny wzgl�dem i

		//przesuwanie element�w wi�kszych od pom
		while (j >= 0 && tab[j] > pom)
		{
			tab[j + 1] = tab[j]; //przesuwanie element�w
			--j;
		}
		tab[j + 1] = pom; //wstawienie pom w odpowiednie miejsce
	}
}

//Funkcja sortuje zbi�r (tablic�) metod� przez wstawianie B
void InsertSortB(int tab[], int size)
{
	int temp, j;

	for (int i = 1; i < size; i++)
	{
		temp = tab[i];//element przesuwany
		for (j = i - 1; j >= 0 && tab[j] > temp; j--)
			tab[j + 1] = tab[j];
		tab[j + 1] = temp;
	}
}

//Funkcja zwraca flag�, czy �a�cch jest palindromem
bool Palindrome(const std::string & word)
{
	unsigned length = word.length();
	std::string napis_forward = word;	//s�owo czytane od lewej do prawej
	std::string napis_backwards;		//s�owo czytane od prawej do lewej
	//skracamy ilo�� iteracji poprzez wykorzystnie zasady,
	//�e wystarczy sprawdzi� po�ow� s�owa...
	int polowa = length / 2;

	for (int i = length - 1; i >= 0; i--)
		napis_backwards = napis_backwards + napis_forward[i];
	return (napis_backwards == napis_forward);
}

//Funkcja zwraca flag�, czy �a�cuch jest palindromem
bool Palindrom(const std::string & napis)
{
	int napis_length = napis.length();	//d�ugo�� napiasu
										//ustawiam liczniki "i" i "j" na pierwszy i ostatni znak wyrazu tab

	int i = 0;
	int j = napis_length - 1; //pami�tajmy, �e indeksujemy tablic� od 0

	while (i < j) //p�tla wykonuje si� do momentu spotkania licznik�w
	{
		if (napis[i] != napis[j]) //gdy znaki nie b�d� si� zgadza�, to wyraz nie jest palindromem
			return false;
		++i; //przejscie do nast�pnej litery id�c w praw� stron�
		--j; //przejscie do poprzedniej litry id�c w lew� stron�
	}
	return true; //wyraz jest palindromem
}

//Funkcja zwraca sum� cyfr liczy ca�kowitej
int SumDigit(int value)
{
	int suma_cyfr = 0;//zak�adamy, �e suma r�wna si� zero

	while (value != 0)
	{
		suma_cyfr += value % 10;	//akumulujemy sum� cyfr
		value /= 10;				//dzielimy liczb� przez 10 (system dziesi�tny)
	}
	return suma_cyfr;
}

//Funkcja zwraca najwi�kszy wsp�lny dzielnik dw�ch liczb
int NWD(int a, int b)
{
	//wybieramy wi�ksz� z dw�ch liczb
	//i zamieniamy j� na r�nic� wi�kszej i mniejszej,
	//powtarzaj�c t� czynno�� do momentu uzyskania dw�ch takich samych warto�ci.
	while (a != b)//powtarzamy dop�ki a jest r�ne od b
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a; // a lub b - obie zmienne przechowuj� wynik

	//Przyk�ad:
	//1989 � 867 = 1122
	//1122 � 867 = 255
	//867 � 255 = 612
	//612 � 255 = 357
	//357 � 255 = 102
	//255 - 102 = 153
	//153 - 102 = 51
	//102 -51 =51
}

//Funkcja zwraca najwi�kszy wsp�lny dzielnik dw�ch liczb - wersj� zoptymalizowana
int NWDZOptimized(int a, int b)
{
	int pom;
	while (b != 0)
	{
		pom = b;
		b = a % b;
		a = pom;
	}
	return a;
}

//Funkcja sprawdza, czy liczba jest liczb� pierwsz�
bool PrimeNumber(int candidate)
{
	//Aby okre�li�, czy dana liczba jest pierwsza
	//nale�y zbada� jej dzielniki.
	//Dla zadanej liczby n sprawdzamy kolejne liczby naturalne nale��ce do przedzia�u:
	//[2...pier(n)] (od 2 do pierwistka kwadratowego z n) - tak wynika z analizy
	//matematycznej (sito Erastotenesa)...
	
	if (candidate < 2)
		return false; //gdy liczba jest mniejsza ni� 2 to nie jest pierwsz�

	for (int i = 2; i*i <= candidate; i++)
		//dzielimy (modulo) liczb� (candidate) przez i...
		if (candidate % i == 0)	//je�li zosta� wyliczony jaki� dzielnik
			return false;		//to dana liczba nie jest pierwsza
	return true;
}

//Funkcja sprawdza, czy liczba jest liczb� pierwsz� - inne wersja
bool Pierwsza(int candidate)
{
	if (candidate < 2)
		return false; //gdy liczba jest mniejsza ni� 2 to nie jest pierwsz�

	for (int p = 2; p < candidate; p++)
		if (candidate % p == 0)//je�li zosta� wyliczony jaki� dzielnik - liczba nie jest pierwsza
			return false;
	return true;
}

//Funkcja generuje liczby pierwsze z podanego zakresu: zbioru (tablicy)
void sitoEratostenesa(bool tab[], unsigned int n)
{
	//szukamy kolejnych kandydat�w na liczby pierwsze
	//wystarczy sprawdzi� do pierwiastka z n
	// i <= sqrt(n) - podnosz�c do kwadratu mamy
	// zatem nasza nier�wno�� ma posta�: i * i <= n
	for (int i = 2; i*i <= n; i++)
	{              
		//sprawdzamy czy liczba jest pierwsza (ma wartosc 0/false/) - dlatego negacja
		if (!tab[i])
			for (int j = i*i; j <= n; j += i) //to wykre�lamy jej wielokrotnosci
				tab[j] = true;      //ustawiaj�c wartos� na 1
	}

	cout << "Kolejne liczby pierwsze z przedzia�u [2.." << n << "]: ";

	for (int i = 2; i <= n; i++)
		if (!tab[i])
			cout << i << " ";
}

//Funkcja zwraca wynik por�wnania dw�ch �a�cuch�w
EComparisons Compare(const std::string & a, const std::string & b)
{
	//wyliczamy d�ugo�ci napis�w
	unsigned a_length = a.length();	//d�ugo�� a
	unsigned b_length = b.length(); //d�ugo�� b

	if (a_length < b_length) return EComparisons::A_MNIEJSZA_B;
	else if (a_length > b_length) return EComparisons::A_WIEKSZA_B;

	//gdy d�ugo�ci s� r�wne, por�wnujemy element po elemencie
	else
	{
		for (unsigned i = 0; i < a.length(); i++)//bez znaczenia czy a, czy b (taka sama d�ugo��)
		{
			if (a[i] < b[i]) return EComparisons::A_MNIEJSZA_B;		//a < b
			else if (a[i] > b[i]) return EComparisons::A_WIEKSZA_B;	//a > b
		}
	}
	//gdy napisy maj� tak� sam� d�ugo�� i takie same elementy...
	return EComparisons::A_ROWNA_B;
}

//Funckja zwraca pozycj�, od kt�rej wzorzec znajduje si� w tek�cie lub -1, gdy nie ma wzorca
int bruteforce(const std::string & text, const std::string & pattern)
{
	int position = 0;				//indeks okre�laj�cy pocz�tek wzorca
	int dl_t = text.length();		//d�ugo�� tekstu
	int dl_w = pattern.length();	//d�ugo�� wzorca
	bool ok = false;				//flaga okre�laj�ca, czy znaleziono
	int result = 0;					//warto��, kt�r� zwraca funkcja
									//-1 gdy nie ma wzorca,
									//warto�� reprezentuj�ca pocz�tek wzorca w tek�cie

	for (int i = 0; i <= dl_t - dl_w; i++)
	{
		//je�li napotkamy pierwsz� liter� z wzorca w tekscie
		if (text[i] == pattern[0])
		{
			ok = true;		//ustawiamy flag� na true
			position = 1;	//zapami�tujemy pozycj�
							//szukamy, czy zgadzaj� si� pozosta�e znaki
			for (int j = i + 1; j < dl_w; j++)
				if (text[j] != pattern[++position]) //je�li si� nie zgadza
				{
					ok = false;		//ustawiamy flag� na fa�sz...
					break;			//przerywamy p�tl�...
				}
			//je�li wszystkie litery si� zgadzaj�...
			if (ok)
			{
				result = i + 1;
				//cout << "Wzorzec znaleziono. Poczatek na " << i + 1 << " pozycji" << std::endl;
				//cout << text << endl;

				//cout.fill(' ');
				//cout.width(i + dl_w);
				//cout << pattern << endl;
				break;
			}
		}
	}
	//if (!ok)
	//	cout << "Wzorca nie znaleziono!" << std::endl;

	if (!ok)
		return -1;
	else
		return result;
}

//Funkcj� odwraca kolejno�� element�w tablicy - iteracyjnie
void odwrocIteration(int *tab, int left, int right)
{
	while (left < right)
	{
		swap(tab[left], tab[right]);//zamiana element�w skrajnych
		left++;						//przesuwamy si� do �rodka od lewej strony
		right--;					//przesuwamy si� do �rodka od prawej strony
	}
}

//Funkcj� odwraca kolejno�� element�w tablicy - rekuracyjnie
void odwrocRecursion(int *tab, int left, int right)
{
	if (left < right)
	{
		Swap(tab[left], tab[right]);//zamiana element�w skrajnych
		odwrocRecursion(tab, left + 1, right - 1);//odwracany reszt�
	}
}

//Funkcja rekurencyjna przeszukujaca tablic� celem znalezienia szukanej warto�ci
void szukajRekurencyjnie(int tab[], int left, int right, int x)
{
	if (left > right)
		std::cout << "Element " << x << " nie zosta� znaleziony\n";
	else
		if (tab[left] == x)
			std::cout << "Element szukany " << x << " zosta� znaleziony\n";
		else
			szukajRekurencyjnie(tab, left + 1, right, x);
}

//Funkcja rejurencyjna oblicz�j�ca silni�
unsigned long int silnia(int x)
{
	if (x == 0)
		return 1;
	else
		return x * silnia(x - 1);
}

//Funkcja iteracyjna oblicz�j�ca kolejny element ci�gu Fibonacciego
unsigned long int FibonacciIteration(int x)
{
	int a, b, temp;
	if (x == 0) return 0;
	
		a = 0; b = 1;

		for (int i = 0; i < (x - 1); i++)
		{
			//Swap(a, b);
			temp = a;
			a = b;
			b = temp;
			b += a;
		}
		return b;
}

//Funkcja rejurencyjna oblicz�j�ca kolejny element ci�gu Fibonacciego
unsigned long int FibonacciRecursion(int x)
{
	if (x == 0) return 0;
	if (x == 1) return 1;
	return FibonacciRecursion(x - 1) + FibonacciRecursion(x - 2);
}

//Funkcja rejurencyjna MacCarthy'ego
unsigned long int MacCarthy(int x)
{
	if (x > 100)
		return (x - 10);
	else
	{
		//std::cout << "wywolanie" << std::endl;
		return MacCarthy(MacCarthy(x + 11));
	}
}

//Funkcja niebezpieczna
int Danger(int n, int p)
{
	if (n == 0)
		return 1;
	else
		return Danger(n - 1, Danger(n - p, p));
}

//Funkcja sprawdza, czy w tablicy znajduje si� szukana warto��
bool BinarySearchRecursion(int *tab, int x, int left, int right)
{
	if (left > right)
		return false;//nie znaleziono...
	else
	{
		int mid = (left + right) / 2;//wyznaczamy "�rodek" zbioru...
		if (tab[mid] == x)
			return mid;//znaleziono
		else
			if (x < tab[mid])
				return BinarySearchRecursion(tab, x, left, mid - 1);
			else
				return BinarySearchRecursion(tab, x, mid + 1, right);
	}
}

//Funkcja Ackermanna
int Ackermann(int n, int p)
{
	if (n == 0)
		return 1;
	if ((p == 0) && (n >= 1))
		if (n == 1)
			return 2;
		else
			return n + 2;
	if ((p >= 1) && (n >= 1))
		return Ackermann(Ackermann(n - 1, p), p - 1);
}

//Funkcja oblicza warto�� wielomianu - schemat Hornera
int Horner_Iteration(int wsp[], int st, int x)
{
	int wynik = wsp[0];//dlaczego tutaj musimy zainicjowa� warto��?

	for (int i = 1; i <= st; i++)
	{
		wynik = wynik * x + wsp[i];
		//std::cout << "x ";//tutaj dow�d, ile razy mno�ymy (Hofner ma racj�)
	}

	return wynik;
}

//Funkcja oblicza warto�� wielomianu - schemat Hornera - rekurencyjnie
int Horner_Recursion(int wsp[], int st, int x)
{
	if (st == 0)
		return wsp[0];

	return x * Horner_Recursion(wsp, st - 1, x) + wsp[st];
}

//Funkcja zwraca element najcz�ciej wyst�puj�cy w tablicy (zbiorze) - dominant
int dominant(int tab[], int size)
{
	//zmienne
	int dominant;				//dominant - element najcz�ciej wyst�puj�cy w tablicy
	int dominant_counter = 0;	//licznik jego wyst�pie� (wyzerowany)

	//Wyszukujemy dominanta
	for (int i = 0; i < size; i++)
	{
		int local_counter = 0;				//zerujemy lokalny licznik
											//iterujemy po elementach tablicy od pocz�tku
		for (int j = 0; j < size; j++)
			if (tab[j] == tab[i])			//je�li zosta� znaleziony element
				local_counter++;			//zwi�kszamy licznik wyst�pie�

		//sprawdzamy, czy licznik lokalny jest wi�kszy od globalnego
		if (local_counter > dominant_counter)
		{
			dominant_counter = local_counter;	//ten staje si� globalnym
			dominant = tab[i];					//wyznaczamy dominant
		}
	}
	return dominant;
}

//Funkcja zwraca wska�nik, pod kt�rym znajduje si� dominant
int *Dominant(int tab[], int size)
{
	//zmienne
	int dominant;				//dominant - element najcz�ciej wyst�puj�cy w tablicy
	int dominant_counter = 0;	//licznik jego wyst�pie� (wyzerowany)
	int tabPom[2];				//tablica pomocnicza
								//pod indeksem 0 - dominant
								//pod indeksem 1 - licznik wyst�pie� dominanta
	int *result;				//zwracany wska�nik z opakowaniem informacji

	//Wyszukujemy dominanta
	for (int i = 0; i < size; i++)
	{
		int local_counter = 0;				//zerujemy lokalny licznik
		
		//iterujemy po elementach tablicy od pocz�tku
		for (int j = 0; j < size; j++)
			if (tab[j] == tab[i])			//je�li zosta� znaleziony element
				local_counter++;			//zwi�kszamy licznik wyst�pie�

		//sprawdzamy, czy licznik lokalny jest wi�kszy od globalnego
		if (local_counter > dominant_counter)
		{
			dominant_counter = local_counter;	//ten staje si� globalnym
			dominant = tab[i];					//wyznaczamy dominant
		}

		//przepisujemy dane do tablicy pomocniczej
		tabPom[0] = dominant;
		tabPom[1] = dominant_counter;

		//Pami�tamy, �e nazwa tablicy jest adresem jej pocz�tku...
		//ustawiamy wska�nik na tablic� (czyli zwracamy jej adres)
		//spod kt�rego (odwo�uj�c si� indeksami), mo�emy odczyta�
		//dane (dominanta oraz ilo�� jego wyst�pienia w tablicy (zbiorze)
		result = tabPom;
	}
	return result;

	//usage (u�ycie, np. w funkcji main()
	//int *myWynik = new int[2];
	//myWynik = Dominant(Tabliczka, 5);
	//int wynik_dominant = myWynik[0];
	//int wynik_counter = myWynik[1];
	//int wartownik = 0;
}

//Rekurencyjna funkcja sortowania - quicksort
//http://miroslawzelent.pl/wyklady/sortowanie-szybkie-quicksort-dziel-zwyciezaj.pdf
void quicksort(int *tablica, int lewy, int prawy)
{
	int v = tablica[(lewy + prawy) / 2];
	int i, j, x;
	i = lewy;
	j = prawy;
	do
	{
		while (tablica[i]<v)
			i++;
		while (tablica[j]>v)
			j--;
		
		if(i <= j) 
		{
			x = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = x;
			i++; j--;
		}
	} while	(i <= j);

	if (j>lewy) quicksort(tablica, lewy, j);
	if (i<prawy) quicksort(tablica, i, prawy);
}

//Rekurencyjna funkcja sortowania - QuickSort
void QuickSort(int *tab, int lewy, int prawy)
{
	int i, j, piwot;

	i = (lewy + prawy) / 2;

	piwot = tab[i];
	tab[i] = tab[prawy];

	for (j = i = lewy; i < prawy; i++)
		if (tab[i] < piwot)
		{
			Swap(tab[i], tab[j]);
			j++;
		}
	tab[prawy] = tab[j];
	tab[j] = piwot;
	if (lewy < j - 1)  QuickSort(tab, lewy, j - 1);
	if (j + 1 < prawy) QuickSort(tab, j + 1, prawy);
}

//Rekurencyjna funkcja sortowania - QuickSortAlpha
void QuickSortAlpha(int *tablica, int lewy, int prawy)
{
	int v = tablica[(lewy + prawy) / 2];//v - piwot
	//*pivot (ang. sworze�, o�, d�wignia, sedno) u nas - element podzia�u...
	int p = lewy;
	int q = prawy;
	do
	{
		while (tablica[p]<v) p++; //wyszukujemy od Lewej strony tablicy element wiekszy od pivot'a               
		while (tablica[q]>v) q--; //wyszukujemy od prawej strony tablicy element mniejszy od pivot'a
		if (p <= q)
		{
			Swap(tablica[p], tablica[q]);
			//zamieniamy elementy tak aby wi�kszy od pivot'a przesun��
			//na praw� stron�, a mniejszy od pivot'a przesun�� na lew�
			p++;
			q--;
		}
	} while (p <= q);

	if (q>lewy) QuickSortAlpha(tablica, lewy, q);
	if (p<prawy) QuickSortAlpha(tablica, p, prawy);
}

//Rekurencyjna funkcja sortowania - Qsort
void Qsort(int *tab, int left, int right)
{
	if (left < right)
	{
		int m = left;
		for (int i = left + 1; i <= right; i++)
			if (tab[i]<tab[left])
				Swap(tab[++m],tab[i]);  //zamiana miejscami 
		
		Swap(tab[left], tab[m]);
		Qsort(tab, left, m - 1);
		Qsort(tab, m + 1, right);
	}
}

//Funkcja zwraca median� zbioru
int Mediana(int *tab, int left, int right)
{
	//Mediana to element zbioru, od kt�rego w tym zbiorze
	//jest tyle samo element�w wi�kszych
	//lub r�wnych co mniejszych lub r�wnych.

	//Analiza:
	//Sortujemy zbi�r rosn�co.
	//Mediana to element na pozycji n/2 (dla n nieparzystego � mediana, dla n parzystego � mediana dolna).

	//
	//Pami�tamy, �e nazwa tablicy jest adresem jej pocz�tku
	//Dlatego te�, kosztem pami�ci, w tej funkcji celowo utworz�
	//kopi� tej tablicy, do kt�rej przepisz� jej elementy, aby po zako�czeniu
	//funkcji, czyli wyliczeniu mediany, tablica wej�ciowa by�a nienaruszona.
	//
	//Pami�taj, �e takie rozwi�zanie ma t� wad�, �e funkcja na stosie musi
	//zarezerowa� tyle pamieci, aby pomie�ci� kopi� tablicy...
	//
	//Kopiujemy elementy tablicy oryginalnej (parametr funkcji)
	//do tablicy pomocniczej u�ywanej wewn�trz tej funkcji
	//
	int *temp_tab = tab;
	for (int i = left; i < right; i++)
		temp_tab[i] = tab[i];

	int mediana;

	//S o r t u j e m y  tablic� (zbi�r)
	//Poni�szy kod to sortowanie metod� b�belkow�. 
	//Mo�na by by�o wykorzysta� wywo�anie jednej z gotowych funkcji sortuj�cych,
	//kt�rych imoplementacje s� w tej lokalizacji, ale umieszczenie
	//kodu sortowania wewn�trz tej funckji, uniezale�nia jej dzia�anie
	//i wykorzystanie poza t� lokalizacj�.

	int temp;

	for (int i = left; i < right; i++)
		for (int j = left; j < right - i - 1; j++) //p�tla wewn�trzna
			if (temp_tab[j] > temp_tab[j + 1])
			{
				//zamiana miejscami je�li warunek jest spe�niony
				temp = temp_tab[j];
				temp_tab[j] = temp_tab[j + 1];
				temp_tab[j + 1] = temp;
			}

	mediana = temp_tab[(right - left)/2];
	return mediana;
}

//Funkcja zwraca �a�cuch znak�w reprezentuj�cy sum� liczba
std::string BigSum(std::string & number_1, std::string & number_2)
{
	//Przyk�ad zosta� om�wiony na stronie: http://eduinf.waw.pl
	
	
	//Rejestr pamieci, w kt�rej maszyna przechwuje zmienne, w naszym
	//przypadku liczby, ma swoj� pojemno��. Na komputerze 32-bitowym
	//mamy tylko tyle pami�ci, aby przechowa� w nim liczb� w postaci
	//binarnej.
	//
	//Rodzi si� problem, jak zatem wykonywa� obliczenia bazuj�ce na bardzo
	//du�ych liczbach, przez co rozumiemy np. liczb� 3 do pot�gi 1000?
	//
	//Rozwi�zanie poni�ej przedstawione jest najprostszym z mo�liwych
	//rozwi�za�, opierajace si� na spodobie dodawania, kt�y poznali�my
	//w szkole podstawowej.
	//Jest to zreszt� chyba jedyby spos�b wykonywania operacji arytmetychnych
	//bez pos�ugiwania si� maszynami jakimi s� kalkulatory, przez co rozumiemy
	//wszystkie maszyny wymy�lone przez cz�owieka u�atwiaj�ce zarzadzanie
	//liczbami reprezentuj�cycmi wielko�ci otaczaj�cego nas �wiata.
		
	//Przyk�ad:
	//                                       1	//przeniesienie
	//number_                 23432900765432345
	//number_2      + 4309561205471717171934675
	//                -------------------------
	//                                        0
	
	//
	//Uwagi, za�o�enia, wnioski
	// - zak�adamy, �e �a�cuch znak�w sk�ada si� tylko z cyfr,
	// - przyk�ad dotyczy dodawania liczb ca�kowitych dodatnich
	//   jakkolwiek mo�na tak dostosowa� algorytm, aby dziedzin�
	//   liczb powiekszy�,
	// - dodawanie jest przemienne, co nale�y uwzgl�dni� w algorytmie
	//   poniewa� wielko�ci (rz�dy wielko�ci) sk�adnik�w sumy mog� by�
	//   r�ne
	// - opracje bazuj�ce na �a�cuchach s� wprost ptporcjonalne do ich
	//   d�ugo�ci, dlatego te� wykonanie tej funkcji jest do�� kosztowne
	//
	//Za�o�nie:
	//
	//Pos�ugujemy si� rozwi�zaniem, kt�re jest standardem (tablica kod�w ASCII)
	//
	//  Cyfra 	Kod ASCII
	//	0 		48
	//	1 		49
	//	2 		50
	//	3		51
	//	4		52
	//	5		53
	//	6		54
	//	7		55
	//	8		56
	//	9		57
	
	//post�pujemy wed�ug nast�ujacego algorytmu:
	
	std::string s1;			//pierwszy sk�adnik sumy
	std::string s2;			//drugi sk�adnik sumy
	std::string suma;		//suma

	int przeniesienie;		//przeniesienie
	int w;					//zmienna przechowuje wynik dodawania w "s�upku"
	int length_number_1;	//d�ugo�� �a�cucha pierwszej liczby
	int length_number_2;	//d�ugo�� �a�cucha drugiej liczby
	int n;					//w tej zmiennej b�dzie przechowywany kr�tszy �a�cuch

	//odczytujemy liczby do dodawania z parametr�w funkcji
	s1 = number_1;
	s2 = number_2;

	//obliczamy d�ugo�ci ka�dego z �a�cuch�w
	length_number_1 = s1.length();
	length_number_2 = s2.length();

	//wyznaczamy d�ugo�� kr�tszego �a�cucha
	n = length_number_1;
	if (length_number_2 < length_number_1)
		n = length_number_2;

	przeniesienie = 0;	//zerujemy przeniesienie
	suma = "";			//zerujemy �a�cuch wynikowy

	//sumujemy kolejne od ko�ca cyfry obu �a�cuch�w
	for (int k = 1; k <= n; k++)
	{
		w = (int)(s1[--length_number_1]) + (int)(s2[--length_number_2]) + przeniesienie - 96;
		przeniesienie = w / 10;
		suma = (char)((w % 10) + 48) + suma;//konkatenacja
	}

	//je�li �a�cuch s1 ma jeszcze cyfry, to dodajemy do nich przeniesienia i umieszczamy w �a�cuchu wynikowym
	while (length_number_1)
	{
		w = s1[--length_number_1] + przeniesienie - 48;
		przeniesienie = w / 10;
		suma = (char)((w % 10) + 48) + suma;
	}

	// je�li �a�cuch s2 ma jeszcze cyfry, to dodajemy do nich
	//przeniesienia i umieszczamy w �a�cuchu wynikowym
	while (length_number_2)
	{
		w = s2[--length_number_2] + przeniesienie - 48;
		przeniesienie = w / 10;
		suma = (char)((w % 10) + 48) + suma;
	}

	//je�li pozosta�o przeniesienie, to do��czamy je do cyfr w �a�cuchu wynikowym
	if (przeniesienie)
		suma = (char)(przeniesienie + 48) + suma;

	//je�li w suma nie ma cyfr, to wpisujemy tam 0
	if (suma == "")
		suma = "0";

	//wy�wietlamy wynik
	std::cout << suma << std::endl;

	return suma;
}

//Funkcja - wydawanie reszty
void WydawanieReszty(int reszta)
{
	int liczba_monet;
	int i, nominal[] = { 20000,10000,5000,2000,1000,500,200,100,50,20,10,5,2,1 };

	i = 0;
	while (reszta > 0)
	{
		if (reszta >= nominal[i])
		{
			liczba_monet = reszta / nominal[i];
			reszta = reszta - (nominal[i] * liczba_monet);
			cout << liczba_monet << " x " << nominal[i] << " gr." << endl;
		}
		i++;
	}
}

//Funkcja zwraca jednocze�nie minimum i maximum tablicy
void MiniMax(int Tab[], int size)
{
	//P r e a m b u � a:
	//
	//Nasze post�powanie opiera si� na napisaniu takiego kodu,
	//kt�ry jest wydajny.
	//Analiza pr�dko�ci jego dzia�ania do ilo�ci zu�ytej pami�ci
	//oraz u�ycia czasu procesora - zawsze jest najtrudniejsze
	//
	//Zak�adamy, �e zbi�r danych (tablica),
	//kt�r� wcze�niej doprowadzimy do stanu aby mia�a parzyst�
	//ilo�� element�w - b�dzimy brali po dwa elementy (pary)
	//nie musz� dodawa�, �e to elementy nast�puj�ce po sobie
	//(tablica to ci��y obszar pamieci).
	//Nast�pnie wyznaczamy wst�pnie - inicjujemy zmienne
	//warto�� max i min - pocz�tkow� warto�� maksymaln� i minimaln�.
	//
	//W ka�dym kroku iteracji jednocze�nie pilnujemy wyznaczania
	//warto�ci min i max
	//
	//Za�o�enie wst�pne - logiczne:
	// - tablica powinna mie� przynajmniej jeden element
	//   co wynika z logiki (je�li poddajemy zbi�r analizie
	//   to taki zbi�r nie powienien by� pusty
	//Dodanie dodatkowego (zapasowego) elementu do tablicy (na ko�cu)
	//to:
	//		-	koszt - dodatkowa pamie� (kwestia zawsze problematyczna)
	//		-	zysk - dope�nienie ilo�ci element�w tablicy, aby by�a
	//			ona parzysta, nie wp�ywa na ilo�� iteracji poniewa�
	//			w ka�dym jej kroku analizujemy par� jej element�w
	//
	//Test:
	//Sprawd� jak� warto�� b�dzie mia�a zmienna iteration_counter
	//zwi�kszaj�c liczb� element�w tablicy - spr�buj to wyrazi� wzorem

	int iteration_counter = 0;//diagnostyka

	if (size % 2)//je�li tablica ma nieparzyst� ilo�� element�w
		Tab[size] = Tab[size - 1];//dublujemy ostatni element

	//bierzemy dwa pierwsze elementy i wyznaczamy wst�pnie min i max
	int min;//kandydat na maksimum
	int max;//kandydat na minimum

	if (Tab[0] > Tab[1])
	{
		min = Tab[1];
		max = Tab[0];
	}
	else
	{
		min = Tab[0];
		max = Tab[1];
	}

	//Skracamy iteracj�, bo rozpoczynamy od i = 2
	//(zauwa�, �e w przypadku tablicy, kt�ra ma mniej ni� 3 elementy
	//p�tla for w og�le si� nie wykona.
	//Dodatkowo zarz�dzamy licznikiem p�tli co dwa elementy i +=2
	//zatem zmniejszamy ilo�ci� wywo�a� iteracyjnych.
	//Pami�taj:
	//Iteracja to przede wszystkim czas,
	//a ten jest bezcenny. I na tym zazwyczaj "wyk�adaj�"
	//si�  a l g o r y t m y.

	for (int i = 2; i < size; i += 2)
	{
		if (Tab[i] > Tab[i + 1])
		{
			if (Tab[i] > max) max = Tab[i];
			if (Tab[i + 1] < min) min = Tab[i + 1];
		}
		else
		{
			if (Tab[i] < min) min = Tab[i];
			if (Tab[i + 1] > max) max = Tab[i + 1];
		}
		iteration_counter++;
	}

	std::cout << "Rozmiar tablicy :  " << size << std::endl;
	std::cout << "Minimum         :  " << min << std::endl;
	std::cout << "Maksimum        :  " << max << std::endl;
	std::cout << "Iteracja        :  " << iteration_counter << std::endl;
}

//Szyfrowanie
std::string Szyfrowanie(std::string slowo, int klucz)
{
	//obliczamy d�ugo�ci s�owa do iteracji (ilo�� liter w s�owie)
	int dlugosc_slowa = slowo.length();

	//wyliczenie krotno�ci klucza w alfabecie poniewa� klucze to spore liczby
	//a my mo�emy w oparciu o za�o�enia zadania porusza� si� tylko
	//w obr�bie alfabetu �aci�skiego po�r�d wielkich liter: od 'A' do 'Z',
	//a tych jest 26;
	const unsigned int IL_LITER = 26;//ilo�� du�ych liter: od 'A' do 'Z'
	klucz = klucz % IL_LITER;

	if (klucz >= 0)//klucz musi by� dodatni
		for (int i = 0; i < dlugosc_slowa; i++)
			//sprawdzenie czy klucz wychodzi poza zakres
			if (slowo[i] + klucz <= 'Z')
				slowo[i] = slowo[i] + klucz;
			else
				slowo[i] = slowo[i] + klucz - IL_LITER;
	return slowo;
}

//Deszyfrowanie
std::string Deszyfrowanie(std::string slowo, int klucz)
{
	//obliczamy d�ugo�ci s�owa do iteracji (ilo�� liter w s�owie)
	int dlugosc_slowa = slowo.length();

	//wyliczenie krotno�ci klucza w alfabecie poniewa� klucze to spore liczby
	//a my mo�emy w oparciu o za�o�enia zadania porusza� si� tylko
	//w obr�bie alfabetu �aci�skiego po�r�d wielkich liter: od 'A' do 'Z',
	//a tych jest 26;
	const unsigned int IL_LITER = 26;//ilo�� du�ych liter: od 'A' do 'Z'
	klucz = klucz % IL_LITER;

	if (klucz >= 0)//klucz musi by� dodatni
		for (int i = 0; i < dlugosc_slowa; i++)
			//sprawdzenie czy klucz wychodzi poza zakres
			if (slowo[i] - klucz >= 'A')
				slowo[i] = slowo[i] - klucz;
			else
				slowo[i] = slowo[i] - klucz + IL_LITER;
	return slowo;
}

//Funkcja sprawdza, czy dwa napisy (w jednej linii jawny i tajny, s� zakodowane
//takim samym kluczem (znak po znaku - ten sam klucz)
bool TestujSzyfr(std::string slowo, std::string szyfr)
{
	int klucz;
	//obliczamy d�ugo�ci s�owa do iteracji (ilo�� liter w s�owie)
	//zak�adaj�c, �e s�owo jawne i zaszyforwane maj� tak� sam� d�ugo��
	int dlugosc_slowa = slowo.length();
	int roznica;//r�nica - zmienna sprawdza, czy r�nica dw�ch kluczy si� zeruje

				//ustalamy klucz dla szyfru na podstawie pierwszsego znaku
	klucz = slowo[0] - szyfr[0];
	const unsigned int IL_LITER = 26;//ilo�� du�ych liter: od 'A' do 'Z'
	if (klucz < 0) klucz = klucz + IL_LITER;

	//znaliza znak po znaku...
	for (int i = 0; i < dlugosc_slowa; i++)
	{
		//obliczamy r�nic� klucza dla znaku ze s�owa i z szyfru
		roznica = slowo[i] - szyfr[i];

		//sprawdzamy, czy kolejne znaki maj� ten sam klucz
		if (roznica < 0) roznica = roznica + IL_LITER;

		//jest r�nica - znaki s�owa nie s� zakodowane takim samym kluczem
		if (roznica != klucz)
		{
			return false;
			break;//przerywamy - nie na sensu dalej sprawdza�...
		}
	}
	return true;//napis jawny oraz tajny maj� takim sam klucz - s� poprawnie zakodowane
}

//Funkcja sprawdza, czy indeks tablicy dwuwymiarowej jest poprawny
bool correct_index(int i, int j, int size_i, int size_j)
{
	//sprawdzaj�c, czy wskazany indeks znajduje si� w tablicy
	//nale�y uwzgl�dni� uwzgl�dni� rozmiar tablicy
	return (i >= 0 && i < size_i && j >= 0 && j < size_j);
}

//Rekurencja - alpha
void test(int n)
{
	std::cout << n << '\n';

	if (n > 0)
		test(n - 1);

	std::cout << n << '\n';
}

//Rekurencja - beta
void Odliczanie(int i)
{
	std::cout << "Rakieta startuje za "	<< i << " sek.\n";
	if (i > 0)
		Odliczanie(i - 1);
	//std::cout << i << ". Start zgodny z planem\n";
}

//Rekurencja - gamma
long long suma(int n)
{
	if (n<1)
		return 0;

	return n + suma(n - 1);
}

//Rekurencja - delta
void zamien(int n)
{
	//jesli n == 0 to zawracamy
	if (n == 0)return;
	zamien(n / 2); //zagnie�d�amy rekurencj�
	std::cout << n % 2; //przy powrocie 
}

bool czy_anagram_One(char *a, char *b)
{
	//wyznaczenie liczby liter w slowie a i w slowie b
	int dl1 = strlen(a), dl2 = strlen(b);
	//jesli dlugosci wyraz�w nie sa r�wne, to nie moga
	//byc anagramy
	if (dl1 != dl2)return false;

	int licz[127] = {}; //zerujemy liczniki

	for (int i = 0; i<dl1; i++)
		licz[a[i]]++; //zliczamy litery pierwszego wyrazu

	for (int i = 0; i<dl1; i++)
		licz[b[i]]--; //odejmowanie wystapien liter

	for (int i = 0; i<127; i++)
		if (licz[i] != 0) //jesli ktorys licznik sie nie wyzerowal
			return false; //to oznacza, ze s�owa nie sa anagramami

	return true; //jesli wszystkie liczniki sie wyzerowa�y, to mamy anagramy
}

//....
void sortuj(string &napis)
{

	for (int i = 0, zamiany = 1; i<napis.length() - 1 && zamiany != 0; i++)
	{
		zamiany = 0;
		for (int j = 0; j<napis.length() - 1; j++)
			if (napis[j]>napis[j + 1])
			{
				swap(napis[j], napis[j + 1]);
				zamiany++;
			}
	}

}

bool czy_anagramy_Two(string napis1, string napis2)
{
	if (napis1.length() != napis2.length()) return false;

	sortuj(napis1);
	sortuj(napis2);

	if (napis1 == napis2) return true;
	else
		return false;

}
