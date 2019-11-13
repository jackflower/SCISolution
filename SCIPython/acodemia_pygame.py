import pygame
import random


class Player(pygame.sprite.Sprite):
    """ Acodemia - klasa reprezentuje gracza """
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load("ship.png").convert()
        self.image.convert_alpha()
        self.image.set_colorkey(ALPHA)
        self.rect = self.image.get_rect()
        self.rect.center = (WIDTH / 2, HEIGHT / 2)

    def update(self):
        """ aktualizacja pozycji """
        self.rect.x += 1
    pass

class Enemy(pygame.sprite.Sprite):
    """ Acodemia - klasa reprezentuje wroga """
    def __init__(self):
        super().__init__()
        self.image = pygame.Surface([50, 50])
        self.image.fill(RED)
        self.rect = self.image.get_rect()
        self.rect.center = (700, 100)
 
    def update(self):
        """ aktualizacja pozycji """
        self.rect.x -= 1
        #pos = pygame.mouse.get_pos()
        #self.rect.x = pos[0]
        #self.rect.y = pos[1]
    pass


WIDTH = 800
HEIGHT = 600
FPS = 30

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
pygame.display.set_caption("Acodemia - 2019 <wpisz swoje imię>")

# synchronizacja FPS
clock = pygame.time.Clock() 


#Acodemia 2019-11-09
player = Player()
enemy = Enemy()


# ------------------- A c o d e m i a -------------------------
 
all_sprites = pygame.sprite.Group()

duszek = pygame.sprite.Sprite()
duszek.image = pygame.image.load("ship.png").convert()
#duszek.image = pygame.transform.scale(duszek.image, (32, 32))
duszek.rect = duszek.image.get_rect()
#duszek.rect.topleft = ([400,300])
duszek.rect.center = ([400,300])

all_sprites.add(duszek)
all_sprites.add(player)
all_sprites.add(enemy)
# ------------------- A c o d e m i a -------------------------


# główna pętla gry - pętla czasu rzeczywistego
running = True
while running:

    # 1. aktualizacja czasu
    clock.tick(FPS)

    # 2. aktualizacja zdarzeń
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # 3. aktualizacja gry        
    pygame.display.update()
    player.update()
    enemy.update()

    # 4. rysowanie tła gry - rendering
    screen.fill(WHITE)
    
    # 5. rysowanie duszków na ekranie - rendering
    all_sprites.draw(screen)

    # 6. wysyłamy wszystko na ekran - dane do karty graficznej
    pygame.display.flip()

pygame.quit() # zamykamy bibliotekę PyGame
#quit() # zamykamy program
