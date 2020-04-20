# gra w zgadywanie liczby
import random

game = True
wylosowana = random.randint(1, 1000)
print (wylosowana)
podawana = 0
licznik_odpowiedzi = 0
print("Liczby w przedziale 1..1000")


while(game):

    try:
        podawana = int(input("Podaj liczbę: "))
    except:
        print("To ma być liczba !")
        
    if(podawana == wylosowana):
        licznik_odpowiedzi += 1
        game = False
        print("Wygrana!")
    else:
        licznik_odpowiedzi += 1
        if(podawana > wylosowana):
            print ("za dużo")
        else:
            print ("za mało")

print (licznik_odpowiedzi)
print ("Koniec gry....")
