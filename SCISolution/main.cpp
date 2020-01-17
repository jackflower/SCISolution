#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//odczyt pliku
	std::fstream plik;
	plik.open("barwy.txt", std::ios::in);
	std::string napis;
	unsigned counter = 0;

	while (!plik.eof())
	{
		std::getline(plik, napis);
		if (napis == "RED")
			counter++;
		std::cout << napis << std::endl;
	}

	std::cout << counter << std::endl;

	getchar();
	return 0;
}
