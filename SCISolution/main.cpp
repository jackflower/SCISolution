#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>

int main()
{
	//random - losowość

	srand((unsigned)time(NULL));

	//int wylosowana_liczba =( std::rand() % ile_liczb_w_przedziale ) + startowa_liczba;
	int liczba = (rand() % 6) + 1;
	//std::cout << liczba << std::endl;
	

	//Mechanizmy losowości
	//Najczęściej programiści potrzebują prostego
	//równomiernego rozkładu liczb całkowitych
	//z określonego przedziału:
	//utwórz domyślny mechanizm losowości

	std::default_random_engine dre;
	dre.seed((unsigned)time(NULL));
	time_t czas = time(nullptr);
	int warta = 0;

	//użyj mechanizmu do wygenerowania liczb całkowitych ze zbioru {10, ..., 20}
	std::uniform_int_distribution<int>di(10, 20);
	std::cout << di(dre) << std::endl;


	getchar();
	return 0;
}










//int wylosowana_liczba =( std::rand() % ile_liczb_w_przedziale ) + startowa_liczba;



//Mechanizmy losowości
//Najczęściej programiści potrzebują prostego
//równomiernego rozkładu liczb całkowitych
//z określonego przedziału:
// utwórz domyślny mechanizm losowości
//std::default_random_engine dre;
//dre.seed((unsigned)time(NULL));
// użyj mechanizmu do wygenerowania liczb całkowitych ze zbioru {10, ..., 20}
//std::uniform_int_distribution<int>di(10, 20);
//std::cout << di(dre) << std::endl;



//Mechanizmy losowości
//Najczęściej programiści potrzebują prostego
//równomiernego rozkładu liczb całkowitych
//z określonego przedziału:
// utwórz domyślny mechanizm losowości
//std::default_random_enginedre;
// użyj mechanizmu do wygenerowania liczb całkowitych ze zbioru {10, ..., 20}
//std::uniform_int_distribution<int>di(10,20);
//std::cout<< di(dre) << std::endl; 