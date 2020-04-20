import tkinter
import random

window = tkinter.Tk() # okno...
window.geometry("400x300") # okno - rozmiar
window.title( "Acodemia  - Tkinter 2020" ) # tytuł okna

# etykieta z wylosowaną liczbą - tylko do testów...
liczba = tkinter.IntVar()
label = tkinter.Label(window, textvariable = liczba)
label.place(x=1, y=2, height=20, width=200)

# etykieta informacyjna
text_info = tkinter.StringVar()
label_info = tkinter.Label(window, textvariable = text_info)
label_info.place(x=100, y=20, height=20, width=200)

# etykieta na licznik odpowiedzi
counter = tkinter.IntVar()
label_counter = tkinter.Label(window, textvariable = liczba)
label_counter.place(x=400, y=20, height=20, width=200)

# entry - pole edycyjne...
entry_value = tkinter.IntVar()
entry = tkinter.Entry(window, textvariable = entry_value)
entry.place(x=100, y=80, height=20, width=200)
entry.focus_set()


losowana = random.randint(1, 1000) # losujemy liczbę do odgadnięcia
liczba.set(losowana)# update label - wyświeltamy ją na etkiecie
entry_value.set(0)# update entry - wyświetlamy 0 w polu edycji
text_info.set("Odgadnij liczbę") # update label_info - wyświetlamy tekst informujący gracza



def clicked():
    wpisana = 0
    try:
        wpisana = int(entry.get())
        #licznik_odpowiedzi += 1

        if(wpisana == losowana):
            text_info.set("Gratulacje!")
            entry.destroy()
            button.destroy()
        else:
            
            if(wpisana > losowana):
                text_info.set("Za dużo")
            else:
                text_info.set("Za mało")
            pass
    except:
        text_info.set("To ma być liczba !")
        entry_value.set(0)

#button
button = tkinter.Button(window, text="Sprawdź", command = clicked)
button.place(x = 100, y = 150, height = 30, width = 200)

tkinter.mainloop() # wywołanie pętli komunikatów
