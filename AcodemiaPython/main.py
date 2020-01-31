import pygame
import physical

# Rozmiar okna
WIDTH = 800
HEIGHT = 600

# FPS - ilość klatek na sekundę
FPS = 60

# Kolory
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
ALPHA = (0, 0, 0)

# inicjalizajca bilbioteki PyGame
pygame.init()

# tworzenie okna
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Szczecińskie Collegium Informatyczne SCI 2020")
icon = pygame.image.load("data/sci_ship_one.png")
pygame.display.set_icon(icon)

# synchronizacja FPS
clock = pygame.time.Clock()

ship = physical.Physical(400, 300)
ship.load_image("data/sci_ship_two.png")

# rejestrujemy obiekty w kontenerze
all_sprites = pygame.sprite.Group()
all_sprites.add(ship)


# zarządzanie czasem
timer = 0  # czas do odliczania.
dt = 0  # delta time (czas od ostatniego tyknięcia).

# główna pętla gry - pętla czasu rzeczywistego
running = True
while running:

    # 1. aktualizacja czasu
    clock.tick(FPS)

    # testy...można to potem deaktywować...
    dt = clock.tick(FPS)/1000
    timer -= dt
    if timer <= 0:
        timer = 1  # Reset it to 10 or do something else.
        print("Tik,tak...") # ... testy

    # 2. aktualizacja zdarzeń
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # 3. aktualizacja gry
    pygame.display.update()
    ship.update()


    # 4. rysowanie tła gry - rendering
    screen.fill(WHITE)

    # 5. rysowanie duszków na ekranie - rendering
    all_sprites.draw(screen)

    # 6. wysyłamy wszystko na ekran - dane do karty graficznej
    pygame.display.flip()

pygame.quit()  # zamykamy bibliotekę PyGame

