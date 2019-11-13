//  __________________________________
// | SCILibrary.cpp -  implementation |
// | SCI - September 2015             |
// |__________________________________|

#include "SCILibrary.h"
#include <sstream>

//Funkcja zamienia liczbê z systemu dziesiêtnego na system dwójkowy
std::string DecToBin(int decimal)
{
	//zmienne pomocnicze lokalne
	int liczba = decimal;		//liczba, któr¹ zamieniamy - inicjujemy j¹ parametrem
	std::string binary = "";	//liczba binarna postaci ci¹gu zer i jedynek,
								//któr¹ ta funkcja wygenruje - inicjujemy pustym
								//³añcuchem

	//kosmetyka...
	if (liczba == 0)
		return "0";				//bo inaczej nie wejdziemy do pêtli while(...)

	//algorytm...

	while (liczba)						//dopóki liczba jest ró¿na od zera
	{
		if (liczba % 2 == 0)			//jeœli wyra¿enie modulo zwraca 0
			binary = "0" + binary;		//do ³añcucha (tablica char) wstawiamy "0" - cyfrê zero
		else
			binary = "1" + binary;		//w przeciwnym wypadku  wstawiamy "1" - cyfrê zero
		liczba /= 2;					//dzielimy liczbê na dwa (system dwójkowy)
	}
							
	return binary;
}

//Funkcja zamienia liczbê z systemu dwójkowego na system dziesiêtny
int BinToDec(std::string & binary)
{
	//zmienne pomocnicze...
	int x;							//odczytany element ³añcucha zamieniony na zero lub jedenkê
	int power = 1;					//wyk³adnik potêgowania
	int dlugosc = binary.length();	//wyliczamy d³ugoœæ std::string binary
	int system = 2;					//operujemy na systemie dwójkowym
	int result = 0;					//wyliczona liczba dziesiêtna, któr¹ zwraca ta fukcja

	//zaczynamy od koñca ³añcucha (tablicy)...
	for (int i = dlugosc - 1; i >= 0; i--)
	{
		if (binary[i] == '1') x = 1;
		if (binary[i] == '0') x = 0;
		result += x * power;		//do wyniku dodajemy otrzyman¹ wartoœæ,
									//któr¹ mno¿ymy przez podstawê systemu do odpowiedniej potêgi
		power *= system;			//ustawiamy power (wyk³adnik) na odpowiedni¹ potegê systemu (2)
	}
	return result;
}

//Funkcja zamienia liczbê z systemu ósemkowego na system dziesiêtny
int OctalToDecimal(std::string & octal)
{
	//zmienne pomocnicze...
	int x;							//odczytany element ³añcucha zamieniony na liczby <0..7> - tyle ich jest w systemie ósemkowym
	int power = 1;					//wyk³adnik potêgowania
	int dlugosc = octal.length();	//wyliczamy d³ugoœæ std::string octal
	int system = 8;					//operujemy na systemie ósemkowym
	int result = 0;					//wyliczona liczba dziesiêtna, któr¹ zwraca ta fukcja

	//zaczynamy od koñca ³añcucha (tablicy)...
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
		result += x * power;		//do wyniku dodajemy otrzyman¹ wartoœæ,
									//któr¹ mno¿ymy przez podstawê systemu
									//do odpowiedniej potêgi
		power *= system;			//ustawiamy power (wyk³adnik) na odpowiedni¹ potegê systemu (2)
	}
	return result;
}


//Funkcja zamienia liczbê z dowolnego systemu na system dziesiêtny
int AnyToDec(std::string & number_in_any_system, int system)
{
	int x;							//odczytany element ³añcucha
	int wynik = 0;					//wartoœæ, któr¹ zwraca ta funkcja
	int power = 1;					//potêga
	int dlugosc = number_in_any_system.length();//wyliczamy d³ugoœæ std::string binary

	//zaczynamy od koñca tablicy...
	for (int i = dlugosc - 1; i >= 0; i--)
	{
		//je¿eli odczytany element ³añcucha jest cyfr¹...
		if (number_in_any_system[i] >= '0' && number_in_any_system[i] <= '9')
			//odejmujemy kod zera - zamieniamy kod cyfry na cyfrê
			x = number_in_any_system[i] - '0';
		else
			//je¿eli jest to litera (musi byc du¿a)
			x = number_in_any_system[i] - 55;//to odejmujemy 55 np. A(65) - 55 = 10

		//do wyniku dodajemy otrzyman¹ wartoœæ
		//pomno¿on¹ przez podstawê systemu do odpowiedniej potêgi
		wynik += x * power; 
		power *= system; // ustawiamy power(wyk³adnik) na odpowiedni¹ potegê systemu
	}

	return wynik;
}

//Binary Search - implementacja
bool BinarySearch(int tab[], int tab_size, int value_searched)
{
	//zak³adamy, ¿e przeszukujemy tablicê w pe³nym zakresie
	//czyli ca³¹ tablicê od indeksu 0 do ostatniego elementu
	int l = 0;			//pocz¹tek tablicy
	int r = tab_size;	//koniec tablicy
	int sr= (l + r)/2;	//indeks - wyliczany œrodek (miejsce) indeks
	bool result = false;//flaga okreœla, czy w tablicy znajduje siê szukana wartoœæ
						//na pocz¹tku zak³adamy, ¿e nie...

	std::cout << "Elementy tablicy:" << std::endl;

	for (int i = 0; i < tab_size; i++)
		std::cout << tab[i] << "  ";

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Szukamy w talicy wartosci: " << value_searched  << std::endl;


	while (l <= r)
	{
		sr = (l + r) / 2;//wyliczamy œrodek
		if (tab[sr] == value_searched)//jeœli szukana jest w tablicy...
		{
			//mo¿na o tym poinformowaæ...
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

//Funkcja sprawdza, czy w tablicy znajduje siê szukana wartoœæ
bool LineSearch(int tab[], int tab_size, int value_searched)
{
	for (int i = 0; i < tab_size; i++)
		if (tab[i] == value_searched)
			return true;
	return false;
}

//Funkcja losuje liczbê z przedzia³u obustronnie domkniêtego
int Rand(int min, int max)
{
	//P a m i ê t a j !!! - ziarno
	//Zawsze ustawiaj tylko jeden raz
	//np: w main() - zaraz na pocz¹tku kodu
	//poprawne wywo³anie funkcji:
	//	srand((unsigned)time(NULL));

	int pseudolosowa = ((rand() % (max - min + 1))) + (min);
	return pseudolosowa;//nasza cywilizacja potrafi za pomoc¹
						//komputerów generowaæ tylko liczby
						//p s e u d o l o s o w e
}

//Funkcja zwraca flagê, czy rok jest przestêpny
bool checkYear(int year)
{
	//operatory logiczne - poczytaæ...
	//&& operator AND	- koniunkcja
	//|| operator OR	- alternatywa

	//rok jest przestêpny wtedy i tylko wtedy gdy:
	//dzieli siê przez 4 i nie dzieli siê przez 100,
	//za wyj¹tkiem lat podzielnych przez 400
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

//Funkcja konwerstuje typ int na std::string
std::string IntToString(int value)
{
	std::stringstream ssBufor;	//stringstream...bufor
	std::string sWynik;			//zwyk³y string - to zwraca funkcja
	ssBufor << value;			//wysy³amy liczbê int do bufora
	ssBufor >> sWynik;			//przepisujemy z bufora do zwyk³ego stringa,
								//z którym mo¿emy ju¿ sobie "poradziæ"...
	return sWynik;
}

//Funkcja zamienia wartoœci z a na b i b na a
void Swap(int & a, int & b)
{
	int pom = a;//zapamiêtano a
	a = b;		//do a przekazujê b
	b = pom;	//do b przekazujê zapamiêtane a
}

//Funkcja zwraca iloœæ cyfr podanej liczby
short CounterDigit(int liczba)
{
	short counter_digit = 0;//licznik cyfr
	if (liczba == 0) counter_digit = 1;
	while (liczba != 0)
	{
		counter_digit++;
		liczba /= 10;//jest to system dziesiêtny
	}
	return counter_digit;
}


//Funkcja sortuje zbiór (tablicê) metod¹ b¹belkow¹
void BubbleSort(int tab[], int size)
{
	int temp;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++) //pêtla wewnêtrzna
			if (tab[j] > tab[j + 1])
			{
				//zamiana miejscami jeœli warunek jest spe³niony
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
}

//Funkcja sortuje zbiór (tablicê) metod¹ b¹belkow¹
void BubbleSortEasy(int tab[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (tab[j] > tab[j + 1])
				Swap(tab[j], tab[j + 1]);//zamiana miejscami jeœli warunek jest spe³niony
		}
	}
}

//Funkcja sortuje zbiór (tablicê) metod¹ przez wstawianie A
void InsertSortA(int tab[], int size)
{
	int pom, j;
	for (int i = 1; i < size; i++)//zaczyna itreracjê od drugiego elementu
	{
		//wstawienie elementu w odpowiednie miejsce
		pom = tab[i];	//ten element bêdzie wstawiony w odpowiednie miejsce
		j = i - 1;		//element nastêpny wzglêdem i

		//przesuwanie elementów wiêkszych od pom
		while (j >= 0 && tab[j] > pom)
		{
			tab[j + 1] = tab[j]; //przesuwanie elementów
			--j;
		}
		tab[j + 1] = pom; //wstawienie pom w odpowiednie miejsce
	}
}

//Funkcja sortuje zbiór (tablicê) metod¹ przez wstawianie B
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

//Funkcja zwraca flagê, czy ³añcch jest palindromem
bool Palindrome(const std::string & word)
{
	unsigned length = word.length();
	std::string napis_forward = word;	//s³owo czytane od lewej do prawej
	std::string napis_backwards;		//s³owo czytane od prawej do lewej
	//skracamy iloœæ iteracji poprzez wykorzystnie zasady,
	//¿e wystarczy sprawdziæ po³owê s³owa...
	int polowa = length / 2;

	for (int i = length - 1; i >= 0; i--)
		napis_backwards = napis_backwards + napis_forward[i];
	return (napis_backwards == napis_forward);
}

//Funkcja zwraca flagê, czy ³añcuch jest palindromem
bool Palindrom(const std::string & napis)
{
	int napis_length = napis.length();	//d³ugoœæ napiasu
										//ustawiam liczniki "i" i "j" na pierwszy i ostatni znak wyrazu tab

	int i = 0;
	int j = napis_length - 1; //pamiêtajmy, ¿e indeksujemy tablicê od 0

	while (i < j) //pêtla wykonuje siê do momentu spotkania liczników
	{
		if (napis[i] != napis[j]) //gdy znaki nie bêd¹ siê zgadzaæ, to wyraz nie jest palindromem
			return false;
		++i; //przejscie do nastêpnej litery id¹c w praw¹ stronê
		--j; //przejscie do poprzedniej litry id¹c w lew¹ stronê
	}
	return true; //wyraz jest palindromem
}

//Funkcja zwraca sumê cyfr liczy ca³kowitej
int SumDigit(int value)
{
	int suma_cyfr = 0;//zak³adamy, ¿e suma równa siê zero

	while (value != 0)
	{
		suma_cyfr += value % 10;	//akumulujemy sumê cyfr
		value /= 10;				//dzielimy liczbê przez 10 (system dziesiêtny)
	}
	return suma_cyfr;
}

//Funkcja zwraca najwiêkszy wspólny dzielnik dwóch liczb
int NWD(int a, int b)
{
	//wybieramy wiêksz¹ z dwóch liczb
	//i zamieniamy j¹ na ró¿nicê wiêkszej i mniejszej,
	//powtarzaj¹c tê czynnoœæ do momentu uzyskania dwóch takich samych wartoœci.
	while (a != b)//powtarzamy dopóki a jest ró¿ne od b
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a; // a lub b - obie zmienne przechowuj¹ wynik

	//Przyk³ad:
	//1989 – 867 = 1122
	//1122 – 867 = 255
	//867 – 255 = 612
	//612 – 255 = 357
	//357 – 255 = 102
	//255 - 102 = 153
	//153 - 102 = 51
	//102 -51 =51
}

//Funkcja zwraca najwiêkszy wspólny dzielnik dwóch liczb - wersj¹ zoptymalizowana
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

//Funkcja sprawdza, czy liczba jest liczb¹ pierwsz¹
bool PrimeNumber(int candidate)
{
	//Aby okreœliæ, czy dana liczba jest pierwsza
	//nale¿y zbadaæ jej dzielniki.
	//Dla zadanej liczby n sprawdzamy kolejne liczby naturalne nale¿¹ce do przedzia³u:
	//[2...pier(n)] (od 2 do pierwistka kwadratowego z n) - tak wynika z analizy
	//matematycznej (sito Erastotenesa)...
	
	if (candidate < 2)
		return false; //gdy liczba jest mniejsza ni¿ 2 to nie jest pierwsz¹

	for (int i = 2; i*i <= candidate; i++)
		//dzielimy (modulo) liczbê (candidate) przez i...
		if (candidate % i == 0)	//jeœli zosta³ wyliczony jakiœ dzielnik
			return false;		//to dana liczba nie jest pierwsza
	return true;
}

//Funkcja sprawdza, czy liczba jest liczb¹ pierwsz¹ - inne wersja
bool Pierwsza(int candidate)
{
	if (candidate < 2)
		return false; //gdy liczba jest mniejsza ni¿ 2 to nie jest pierwsz¹

	for (int p = 2; p < candidate; p++)
		if (candidate % p == 0)//jeœli zosta³ wyliczony jakiœ dzielnik - liczba nie jest pierwsza
			return false;
	return true;
}

//Funkcja generuje liczby pierwsze z podanego zakresu: zbioru (tablicy)
void sitoEratostenesa(bool tab[], unsigned int n)
{
	//szukamy kolejnych kandydatów na liczby pierwsze
	//wystarczy sprawdziæ do pierwiastka z n
	// i <= sqrt(n) - podnosz¹c do kwadratu mamy
	// zatem nasza nierównoœæ ma postaæ: i * i <= n
	for (int i = 2; i*i <= n; i++)
	{              
		//sprawdzamy czy liczba jest pierwsza (ma wartosc 0/false/) - dlatego negacja
		if (!tab[i])
			for (int j = i*i; j <= n; j += i) //to wykreœlamy jej wielokrotnosci
				tab[j] = true;      //ustawiaj¹c wartosæ na 1
	}

	cout << "Kolejne liczby pierwsze z przedzia³u [2.." << n << "]: ";

	for (int i = 2; i <= n; i++)
		if (!tab[i])
			cout << i << " ";
}

//Funkcja zwraca wynik porównania dwóch ³añcuchów
EComparisons Compare(const std::string & a, const std::string & b)
{
	//wyliczamy d³ugoœci napisów
	unsigned a_length = a.length();	//d³ugoœæ a
	unsigned b_length = b.length(); //d³ugoœæ b

	if (a_length < b_length) return EComparisons::A_MNIEJSZA_B;
	else if (a_length > b_length) return EComparisons::A_WIEKSZA_B;

	//gdy d³ugoœci s¹ równe, porównujemy element po elemencie
	else
	{
		for (unsigned i = 0; i < a.length(); i++)//bez znaczenia czy a, czy b (taka sama d³ugoœæ)
		{
			if (a[i] < b[i]) return EComparisons::A_MNIEJSZA_B;		//a < b
			else if (a[i] > b[i]) return EComparisons::A_WIEKSZA_B;	//a > b
		}
	}
	//gdy napisy maj¹ tak¹ sam¹ d³ugoœæ i takie same elementy...
	return EComparisons::A_ROWNA_B;
}

//Funckja zwraca pozycjê, od której wzorzec znajduje siê w tekœcie lub -1, gdy nie ma wzorca
int bruteforce(const std::string & text, const std::string & pattern)
{
	int position = 0;				//indeks okreœlaj¹cy pocz¹tek wzorca
	int dl_t = text.length();		//d³ugoœæ tekstu
	int dl_w = pattern.length();	//d³ugoœæ wzorca
	bool ok = false;				//flaga okreœlaj¹ca, czy znaleziono
	int result = 0;					//wartoœæ, któr¹ zwraca funkcja
									//-1 gdy nie ma wzorca,
									//wartoœæ reprezentuj¹ca pocz¹tek wzorca w tekœcie

	for (int i = 0; i <= dl_t - dl_w; i++)
	{
		//jeœli napotkamy pierwsz¹ literê z wzorca w tekscie
		if (text[i] == pattern[0])
		{
			ok = true;		//ustawiamy flagê na true
			position = 1;	//zapamiêtujemy pozycjê
							//szukamy, czy zgadzaj¹ siê pozosta³e znaki
			for (int j = i + 1; j < dl_w; j++)
				if (text[j] != pattern[++position]) //jeœli siê nie zgadza
				{
					ok = false;		//ustawiamy flagê na fa³sz...
					break;			//przerywamy pêtlê...
				}
			//jeœli wszystkie litery siê zgadzaj¹...
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

//Funkcjê odwraca kolejnoœæ elementów tablicy - iteracyjnie
void odwrocIteration(int *tab, int left, int right)
{
	while (left < right)
	{
		swap(tab[left], tab[right]);//zamiana elementów skrajnych
		left++;						//przesuwamy siê do œrodka od lewej strony
		right--;					//przesuwamy siê do œrodka od prawej strony
	}
}

//Funkcjê odwraca kolejnoœæ elementów tablicy - rekuracyjnie
void odwrocRecursion(int *tab, int left, int right)
{
	if (left < right)
	{
		Swap(tab[left], tab[right]);//zamiana elementów skrajnych
		odwrocRecursion(tab, left + 1, right - 1);//odwracany resztê
	}
}

//Funkcja rekurencyjna przeszukujaca tablicê celem znalezienia szukanej wartoœci
void szukajRekurencyjnie(int tab[], int left, int right, int x)
{
	if (left > right)
		std::cout << "Element " << x << " nie zosta³ znaleziony\n";
	else
		if (tab[left] == x)
			std::cout << "Element szukany " << x << " zosta³ znaleziony\n";
		else
			szukajRekurencyjnie(tab, left + 1, right, x);
}

//Funkcja rejurencyjna oblicz¹j¹ca silniê
unsigned long int silnia(int x)
{
	if (x == 0)
		return 1;
	else
		return x * silnia(x - 1);
}

//Funkcja iteracyjna oblicz¹j¹ca kolejny element ci¹gu Fibonacciego
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

//Funkcja rejurencyjna oblicz¹j¹ca kolejny element ci¹gu Fibonacciego
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

//Funkcja sprawdza, czy w tablicy znajduje siê szukana wartoœæ
bool BinarySearchRecursion(int *tab, int x, int left, int right)
{
	if (left > right)
		return false;//nie znaleziono...
	else
	{
		int mid = (left + right) / 2;//wyznaczamy "œrodek" zbioru...
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

//Funkcja oblicza wartoœæ wielomianu - schemat Hornera
int Horner_Iteration(int wsp[], int st, int x)
{
	int wynik = wsp[0];//dlaczego tutaj musimy zainicjowaæ wartoœæ?

	for (int i = 1; i <= st; i++)
	{
		wynik = wynik * x + wsp[i];
		//std::cout << "x ";//tutaj dowód, ile razy mno¿ymy (Hofner ma racjê)
	}

	return wynik;
}

//Funkcja oblicza wartoœæ wielomianu - schemat Hornera - rekurencyjnie
int Horner_Recursion(int wsp[], int st, int x)
{
	if (st == 0)
		return wsp[0];

	return x * Horner_Recursion(wsp, st - 1, x) + wsp[st];
}

//Funkcja zwraca element najczêœciej wystêpuj¹cy w tablicy (zbiorze) - dominant
int dominant(int tab[], int size)
{
	//zmienne
	int dominant;				//dominant - element najczêœciej wystêpuj¹cy w tablicy
	int dominant_counter = 0;	//licznik jego wyst¹pieñ (wyzerowany)

	//Wyszukujemy dominanta
	for (int i = 0; i < size; i++)
	{
		int local_counter = 0;				//zerujemy lokalny licznik
											//iterujemy po elementach tablicy od pocz¹tku
		for (int j = 0; j < size; j++)
			if (tab[j] == tab[i])			//jeœli zosta³ znaleziony element
				local_counter++;			//zwiêkszamy licznik wyst¹pieñ

		//sprawdzamy, czy licznik lokalny jest wiêkszy od globalnego
		if (local_counter > dominant_counter)
		{
			dominant_counter = local_counter;	//ten staje siê globalnym
			dominant = tab[i];					//wyznaczamy dominant
		}
	}
	return dominant;
}

//Funkcja zwraca wskaŸnik, pod którym znajduje siê dominant
int *Dominant(int tab[], int size)
{
	//zmienne
	int dominant;				//dominant - element najczêœciej wystêpuj¹cy w tablicy
	int dominant_counter = 0;	//licznik jego wyst¹pieñ (wyzerowany)
	int tabPom[2];				//tablica pomocnicza
								//pod indeksem 0 - dominant
								//pod indeksem 1 - licznik wyst¹pieñ dominanta
	int *result;				//zwracany wskaŸnik z opakowaniem informacji

	//Wyszukujemy dominanta
	for (int i = 0; i < size; i++)
	{
		int local_counter = 0;				//zerujemy lokalny licznik
		
		//iterujemy po elementach tablicy od pocz¹tku
		for (int j = 0; j < size; j++)
			if (tab[j] == tab[i])			//jeœli zosta³ znaleziony element
				local_counter++;			//zwiêkszamy licznik wyst¹pieñ

		//sprawdzamy, czy licznik lokalny jest wiêkszy od globalnego
		if (local_counter > dominant_counter)
		{
			dominant_counter = local_counter;	//ten staje siê globalnym
			dominant = tab[i];					//wyznaczamy dominant
		}

		//przepisujemy dane do tablicy pomocniczej
		tabPom[0] = dominant;
		tabPom[1] = dominant_counter;

		//Pamiêtamy, ¿e nazwa tablicy jest adresem jej pocz¹tku...
		//ustawiamy wskaŸnik na tablicê (czyli zwracamy jej adres)
		//spod którego (odwo³uj¹c siê indeksami), mo¿emy odczytaæ
		//dane (dominanta oraz iloœæ jego wyst¹pienia w tablicy (zbiorze)
		result = tabPom;
	}
	return result;

	//usage (u¿ycie, np. w funkcji main()
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
	//*pivot (ang. sworzeñ, oœ, dŸwignia, sedno) u nas - element podzia³u...
	int p = lewy;
	int q = prawy;
	do
	{
		while (tablica[p]<v) p++; //wyszukujemy od Lewej strony tablicy element wiekszy od pivot'a               
		while (tablica[q]>v) q--; //wyszukujemy od prawej strony tablicy element mniejszy od pivot'a
		if (p <= q)
		{
			Swap(tablica[p], tablica[q]);
			//zamieniamy elementy tak aby wiêkszy od pivot'a przesun¹æ
			//na praw¹ stronê, a mniejszy od pivot'a przesun¹æ na lew¹
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

//Funkcja zwraca medianê zbioru
int Mediana(int *tab, int left, int right)
{
	//Mediana to element zbioru, od którego w tym zbiorze
	//jest tyle samo elementów wiêkszych
	//lub równych co mniejszych lub równych.

	//Analiza:
	//Sortujemy zbiór rosn¹co.
	//Mediana to element na pozycji n/2 (dla n nieparzystego – mediana, dla n parzystego – mediana dolna).

	//
	//Pamiêtamy, ¿e nazwa tablicy jest adresem jej pocz¹tku
	//Dlatego te¿, kosztem pamiêci, w tej funkcji celowo utworzê
	//kopiê tej tablicy, do której przepiszê jej elementy, aby po zakoñczeniu
	//funkcji, czyli wyliczeniu mediany, tablica wejœciowa by³a nienaruszona.
	//
	//Pamiêtaj, ¿e takie rozwi¹zanie ma tê wadê, ¿e funkcja na stosie musi
	//zarezerowaæ tyle pamieci, aby pomieœciæ kopiê tablicy...
	//
	//Kopiujemy elementy tablicy oryginalnej (parametr funkcji)
	//do tablicy pomocniczej u¿ywanej wewn¹trz tej funkcji
	//
	int *temp_tab = tab;
	for (int i = left; i < right; i++)
		temp_tab[i] = tab[i];

	int mediana;

	//S o r t u j e m y  tablicê (zbiór)
	//Poni¿szy kod to sortowanie metod¹ b¹belkow¹. 
	//Mo¿na by by³o wykorzystaæ wywo³anie jednej z gotowych funkcji sortuj¹cych,
	//których imoplementacje s¹ w tej lokalizacji, ale umieszczenie
	//kodu sortowania wewn¹trz tej funckji, uniezale¿nia jej dzia³anie
	//i wykorzystanie poza t¹ lokalizacj¹.

	int temp;

	for (int i = left; i < right; i++)
		for (int j = left; j < right - i - 1; j++) //pêtla wewnêtrzna
			if (temp_tab[j] > temp_tab[j + 1])
			{
				//zamiana miejscami jeœli warunek jest spe³niony
				temp = temp_tab[j];
				temp_tab[j] = temp_tab[j + 1];
				temp_tab[j + 1] = temp;
			}

	mediana = temp_tab[(right - left)/2];
	return mediana;
}

//Funkcja zwraca ³añcuch znaków reprezentuj¹cy sumê liczba
std::string BigSum(std::string & number_1, std::string & number_2)
{
	//Przyk³ad zosta³ omówiony na stronie: http://eduinf.waw.pl
	
	
	//Rejestr pamieci, w której maszyna przechwuje zmienne, w naszym
	//przypadku liczby, ma swoj¹ pojemnoœæ. Na komputerze 32-bitowym
	//mamy tylko tyle pamiêci, aby przechowaæ w nim liczbê w postaci
	//binarnej.
	//
	//Rodzi siê problem, jak zatem wykonywaæ obliczenia bazuj¹ce na bardzo
	//du¿ych liczbach, przez co rozumiemy np. liczbê 3 do potêgi 1000?
	//
	//Rozwi¹zanie poni¿ej przedstawione jest najprostszym z mo¿liwych
	//rozwi¹zañ, opierajace siê na spodobie dodawania, któy poznaliœmy
	//w szkole podstawowej.
	//Jest to zreszt¹ chyba jedyby sposób wykonywania operacji arytmetychnych
	//bez pos³ugiwania siê maszynami jakimi s¹ kalkulatory, przez co rozumiemy
	//wszystkie maszyny wymyœlone przez cz³owieka u³atwiaj¹ce zarzadzanie
	//liczbami reprezentuj¹cycmi wielkoœci otaczaj¹cego nas œwiata.
		
	//Przyk³ad:
	//                                       1	//przeniesienie
	//number_                 23432900765432345
	//number_2      + 4309561205471717171934675
	//                -------------------------
	//                                        0
	
	//
	//Uwagi, za³o¿enia, wnioski
	// - zak³adamy, ¿e ³añcuch znaków sk³ada siê tylko z cyfr,
	// - przyk³ad dotyczy dodawania liczb ca³kowitych dodatnich
	//   jakkolwiek mo¿na tak dostosowaæ algorytm, aby dziedzinê
	//   liczb powiekszyæ,
	// - dodawanie jest przemienne, co nale¿y uwzglêdniæ w algorytmie
	//   poniewa¿ wielkoœci (rzêdy wielkoœci) sk³adników sumy mog¹ byæ
	//   ró¿ne
	// - opracje bazuj¹ce na ³añcuchach s¹ wprost ptporcjonalne do ich
	//   d³ugoœci, dlatego te¿ wykonanie tej funkcji jest doœæ kosztowne
	//
	//Za³o¿nie:
	//
	//Pos³ugujemy siê rozwi¹zaniem, które jest standardem (tablica kodów ASCII)
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
	
	//postêpujemy wed³ug nastêujacego algorytmu:
	
	std::string s1;			//pierwszy sk³adnik sumy
	std::string s2;			//drugi sk³adnik sumy
	std::string suma;		//suma

	int przeniesienie;		//przeniesienie
	int w;					//zmienna przechowuje wynik dodawania w "s³upku"
	int length_number_1;	//d³ugoœæ ³añcucha pierwszej liczby
	int length_number_2;	//d³ugoœæ ³añcucha drugiej liczby
	int n;					//w tej zmiennej bêdzie przechowywany krótszy ³añcuch

	//odczytujemy liczby do dodawania z parametrów funkcji
	s1 = number_1;
	s2 = number_2;

	//obliczamy d³ugoœci ka¿dego z ³añcuchów
	length_number_1 = s1.length();
	length_number_2 = s2.length();

	//wyznaczamy d³ugoœæ krótszego ³añcucha
	n = length_number_1;
	if (length_number_2 < length_number_1)
		n = length_number_2;

	przeniesienie = 0;	//zerujemy przeniesienie
	suma = "";			//zerujemy ³añcuch wynikowy

	//sumujemy kolejne od koñca cyfry obu ³añcuchów
	for (int k = 1; k <= n; k++)
	{
		w = (int)(s1[--length_number_1]) + (int)(s2[--length_number_2]) + przeniesienie - 96;
		przeniesienie = w / 10;
		suma = (char)((w % 10) + 48) + suma;//konkatenacja
	}

	//jeœli ³añcuch s1 ma jeszcze cyfry, to dodajemy do nich przeniesienia i umieszczamy w ³añcuchu wynikowym
	while (length_number_1)
	{
		w = s1[--length_number_1] + przeniesienie - 48;
		przeniesienie = w / 10;
		suma = (char)((w % 10) + 48) + suma;
	}

	// jeœli ³añcuch s2 ma jeszcze cyfry, to dodajemy do nich
	//przeniesienia i umieszczamy w ³añcuchu wynikowym
	while (length_number_2)
	{
		w = s2[--length_number_2] + przeniesienie - 48;
		przeniesienie = w / 10;
		suma = (char)((w % 10) + 48) + suma;
	}

	//jeœli pozosta³o przeniesienie, to do³¹czamy je do cyfr w ³añcuchu wynikowym
	if (przeniesienie)
		suma = (char)(przeniesienie + 48) + suma;

	//jeœli w suma nie ma cyfr, to wpisujemy tam 0
	if (suma == "")
		suma = "0";

	//wyœwietlamy wynik
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

//Funkcja zwraca jednoczeœnie minimum i maximum tablicy
void MiniMax(int Tab[], int size)
{
	//P r e a m b u ³ a:
	//
	//Nasze postêpowanie opiera siê na napisaniu takiego kodu,
	//który jest wydajny.
	//Analiza prêdkoœci jego dzia³ania do iloœci zu¿ytej pamiêci
	//oraz u¿ycia czasu procesora - zawsze jest najtrudniejsze
	//
	//Zak³adamy, ¿e zbiór danych (tablica),
	//któr¹ wczeœniej doprowadzimy do stanu aby mia³a parzyst¹
	//iloœæ elementów - bêdzimy brali po dwa elementy (pary)
	//nie muszê dodawaæ, ¿e to elementy nastêpuj¹ce po sobie
	//(tablica to ci¹³y obszar pamieci).
	//Nastêpnie wyznaczamy wstêpnie - inicjujemy zmienne
	//wartoœæ max i min - pocz¹tkow¹ wartoœæ maksymaln¹ i minimaln¹.
	//
	//W ka¿dym kroku iteracji jednoczeœnie pilnujemy wyznaczania
	//wartoœci min i max
	//
	//Za³o¿enie wstêpne - logiczne:
	// - tablica powinna mieæ przynajmniej jeden element
	//   co wynika z logiki (jeœli poddajemy zbiór analizie
	//   to taki zbiór nie powienien byæ pusty
	//Dodanie dodatkowego (zapasowego) elementu do tablicy (na koñcu)
	//to:
	//		-	koszt - dodatkowa pamieæ (kwestia zawsze problematyczna)
	//		-	zysk - dope³nienie iloœci elementów tablicy, aby by³a
	//			ona parzysta, nie wp³ywa na iloœæ iteracji poniewa¿
	//			w ka¿dym jej kroku analizujemy parê jej elementów
	//
	//Test:
	//SprawdŸ jak¹ wartoœæ bêdzie mia³a zmienna iteration_counter
	//zwiêkszaj¹c liczbê elementów tablicy - spróbuj to wyraziæ wzorem

	int iteration_counter = 0;//diagnostyka

	if (size % 2)//jeœli tablica ma nieparzyst¹ iloœæ elementów
		Tab[size] = Tab[size - 1];//dublujemy ostatni element

	//bierzemy dwa pierwsze elementy i wyznaczamy wstêpnie min i max
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

	//Skracamy iteracjê, bo rozpoczynamy od i = 2
	//(zauwa¿, ¿e w przypadku tablicy, która ma mniej ni¿ 3 elementy
	//pêtla for w ogóle siê nie wykona.
	//Dodatkowo zarz¹dzamy licznikiem pêtli co dwa elementy i +=2
	//zatem zmniejszamy iloœci¹ wywo³añ iteracyjnych.
	//Pamiêtaj:
	//Iteracja to przede wszystkim czas,
	//a ten jest bezcenny. I na tym zazwyczaj "wyk³adaj¹"
	//siê  a l g o r y t m y.

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
	//obliczamy d³ugoœci s³owa do iteracji (iloœæ liter w s³owie)
	int dlugosc_slowa = slowo.length();

	//wyliczenie krotnoœci klucza w alfabecie poniewa¿ klucze to spore liczby
	//a my mo¿emy w oparciu o za³o¿enia zadania poruszaæ siê tylko
	//w obrêbie alfabetu ³aciñskiego poœród wielkich liter: od 'A' do 'Z',
	//a tych jest 26;
	const unsigned int IL_LITER = 26;//iloœæ du¿ych liter: od 'A' do 'Z'
	klucz = klucz % IL_LITER;

	if (klucz >= 0)//klucz musi byæ dodatni
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
	//obliczamy d³ugoœci s³owa do iteracji (iloœæ liter w s³owie)
	int dlugosc_slowa = slowo.length();

	//wyliczenie krotnoœci klucza w alfabecie poniewa¿ klucze to spore liczby
	//a my mo¿emy w oparciu o za³o¿enia zadania poruszaæ siê tylko
	//w obrêbie alfabetu ³aciñskiego poœród wielkich liter: od 'A' do 'Z',
	//a tych jest 26;
	const unsigned int IL_LITER = 26;//iloœæ du¿ych liter: od 'A' do 'Z'
	klucz = klucz % IL_LITER;

	if (klucz >= 0)//klucz musi byæ dodatni
		for (int i = 0; i < dlugosc_slowa; i++)
			//sprawdzenie czy klucz wychodzi poza zakres
			if (slowo[i] - klucz >= 'A')
				slowo[i] = slowo[i] - klucz;
			else
				slowo[i] = slowo[i] - klucz + IL_LITER;
	return slowo;
}

//Funkcja sprawdza, czy dwa napisy (w jednej linii jawny i tajny, s¹ zakodowane
//takim samym kluczem (znak po znaku - ten sam klucz)
bool TestujSzyfr(std::string slowo, std::string szyfr)
{
	int klucz;
	//obliczamy d³ugoœci s³owa do iteracji (iloœæ liter w s³owie)
	//zak³adaj¹c, ¿e s³owo jawne i zaszyforwane maj¹ tak¹ sam¹ d³ugoœæ
	int dlugosc_slowa = slowo.length();
	int roznica;//ró¿nica - zmienna sprawdza, czy ró¿nica dwóch kluczy siê zeruje

				//ustalamy klucz dla szyfru na podstawie pierwszsego znaku
	klucz = slowo[0] - szyfr[0];
	const unsigned int IL_LITER = 26;//iloœæ du¿ych liter: od 'A' do 'Z'
	if (klucz < 0) klucz = klucz + IL_LITER;

	//znaliza znak po znaku...
	for (int i = 0; i < dlugosc_slowa; i++)
	{
		//obliczamy ró¿nicê klucza dla znaku ze s³owa i z szyfru
		roznica = slowo[i] - szyfr[i];

		//sprawdzamy, czy kolejne znaki maj¹ ten sam klucz
		if (roznica < 0) roznica = roznica + IL_LITER;

		//jest ró¿nica - znaki s³owa nie s¹ zakodowane takim samym kluczem
		if (roznica != klucz)
		{
			return false;
			break;//przerywamy - nie na sensu dalej sprawdzaæ...
		}
	}
	return true;//napis jawny oraz tajny maj¹ takim sam klucz - s¹ poprawnie zakodowane
}

//Funkcja sprawdza, czy indeks tablicy dwuwymiarowej jest poprawny
bool correct_index(int i, int j, int size_i, int size_j)
{
	//sprawdzaj¹c, czy wskazany indeks znajduje siê w tablicy
	//nale¿y uwzglêdniæ uwzglêdniæ rozmiar tablicy
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
	zamien(n / 2); //zagnie¿d¿amy rekurencjê
	std::cout << n % 2; //przy powrocie 
}

bool czy_anagram_One(char *a, char *b)
{
	//wyznaczenie liczby liter w slowie a i w slowie b
	int dl1 = strlen(a), dl2 = strlen(b);
	//jesli dlugosci wyrazów nie sa równe, to nie moga
	//byc anagramy
	if (dl1 != dl2)return false;

	int licz[127] = {}; //zerujemy liczniki

	for (int i = 0; i<dl1; i++)
		licz[a[i]]++; //zliczamy litery pierwszego wyrazu

	for (int i = 0; i<dl1; i++)
		licz[b[i]]--; //odejmowanie wystapien liter

	for (int i = 0; i<127; i++)
		if (licz[i] != 0) //jesli ktorys licznik sie nie wyzerowal
			return false; //to oznacza, ze s³owa nie sa anagramami

	return true; //jesli wszystkie liczniki sie wyzerowa³y, to mamy anagramy
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
