"""
  ________________________
 | SCIPython -  functions |
 | SCI - 2019-2020        |
 |________________________|

"""

"""
Funkcja dodaje dwie liczby
"""
def sum(a, b):
    return (a + b)
    pass

"""
Funkcja zwraca większą liczbę w dwóch liczb całkowitych
"""
def max(a, b):
    if (a > b):
        return a
    return b
    pass

"""
Funkcja zwraca większą liczbę w trzech liczb całkowitych
"""
def max(a, b, c):
    max = a
    if(b > max):
        max = b
    if(c > max):
        max = c
    return max
    pass

"""
Funkcja zwraca maksymalną wartość z tablicy
"""
def maximum(tab, size):
    max = tab[0];
    for i in range(size):
        if(tab[i]> max):
            max = tab[i]
    return max
    pass

"""
Funkcja zwraca średnią arytmetyczną
"""
def average(a, b):
    #return ((a+b)/2)
    return ((a + b) * 0.5)
    pass

"""
Funkcja zwraca wartość bezwzlędną
"""
def abs(value):
    if(value < 0):
        return -value
    return value
    pass

"""
Funkcja zwraca część dziesiętną
"""
def decimalPart(value):
    return (value - int(value))
    pass

"""
Funkcja zwraca flagę, czy rok jest przestępny (and. leap year)
"""
def leapYear(year):
    return ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0)
    pass


"""
Funkcja sprawdza, czy liczba jest parzysta
"""
def isEven(value):
    if(value % 2 == 0):
        return True
    return False
    pass