import pygame
import tree
import random

pygame.init()

WIDTH = 800
HEIGHT = 600
SIZE = WIDTH, HEIGHT
WHITE = 255, 255, 255

screen = pygame.display.set_mode(SIZE)
pygame.display.set_caption("Acodemia - 1 lutego 2020 - sadzimy las")
icon = pygame.image.load("data/tree_beta.png")
pygame.display.set_icon(icon)

""" kontener na drzewa - las """
forest = pygame.sprite.Group()

""" sadzimy las """
# ilość sadzonek
sadzonki = 100 # random.randint(1,100)
#sadzonki = random.randint(1,100)

# obszar zasiewu
obszar_x = 100
obszar_y = 500

for i in range(sadzonki):
    
    # losowania pozycji sadzonki
    tree_position_x = random.randint(obszar_x, obszar_y)
    tree_position_y = random.randint(obszar_x, obszar_y)
    
    #losowanie grafiki sadzonki
    obrazek = random.randint(1, 2)
    if obrazek == 1:
        image = "data/tree_alfa.png"
    else:
        image = "data/tree_beta.png"

    # dodanie sadzonki do lasu
    forest.add(tree.Tree(image, tree_position_x, tree_position_y))
    

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()

    forest.update()
    screen.fill(WHITE)
    forest.draw(screen)

    pygame.display.flip()

pygame.quit()  # zamykamy bibliotekę PyGame
