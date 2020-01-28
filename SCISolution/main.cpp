#include <iostream>
#include <fstream>
#include <string>

#include <vector>//STL
#include <list>//STL


int main()
{
	std::vector<std::string> box;

	std::list<std::string> jureczek;
	

	//odczyt pliku
	std::fstream plik;
	plik.open("barwy.txt", std::ios::in);
	std::string napis;
	unsigned counter = 0;

	while (!plik.eof())
	{
		std::getline(plik, napis);
		//box.push_back(napis);
		jureczek.push_back(napis);
		//if (napis == "RED")
		//	counter++;
		//std::cout << napis << std::endl;
	}
	int sssss = 0;

	jureczek.sort();

	std::cout << counter << std::endl;

	getchar();
	return 0;
}
