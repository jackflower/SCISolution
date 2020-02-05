"""
SCI 2020-02-05
Przykład odczytu pliku
 - pamiętaj, że plik "datafile.txt" musi być umieszczony w projekcie
   czyli plik skryptu Python "pliki.py" musi "widzieć" plik, który
   chcemy odczytać.
   
   a) plik - zawartość (w osobnych liniach):

      1000
      1000
      1000
      1000
      1000

   b) plik - zawartość (w jednej linii):

      1000 1000 1000 1000 1000

"""
suma = 0 # zmienna będzie przychowywać narastająco sumę liczb z pliku

# zmienna file - odwołuje się do pliku "datafile.txt" - tryb "r" read (odczyt)
file = open("datafile.txt", "r").read()

lines = file.split("\n") # a) plik - zawartość (w osobnych liniach):
#lines = file.split(" ") # b) plik - zawartość (w jednej linii):
# split - separator odzielający elementy pliku (rozumiane jako liczby)
# muszą być zamienione funkcją int(...) na wartości całkowite
# skoro będziemy je traktować operatorem arytmetycznym "+" - dodawać.

# iterujemy po piku
for line in lines:
    #suma = suma + int(line)
    suma += int(line)  # kumulujemy w zmiennej suma sumę tych wartości
    print(line)        # wydruk na konsolę - test poprawności

print("-------------") # kosmetyka
print(suma)            # suma

