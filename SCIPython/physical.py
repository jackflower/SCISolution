import pygame


class Physical(pygame.sprite.Sprite):
    """ SCI - klasa reprezentuje statek kosmiczny - Spaceship """
    ALPHA = (0, 0, 0)

    def __init__(self, x=0, y=0):
        pygame.sprite.Sprite.__init__(self)
        self.pos_x = x
        self.pos_y = y
        self.image = pygame.image.load("data/sci_ship_one.png").convert()
        self.image.convert_alpha()
        self.image.set_colorkey(self.ALPHA)
        self.rect = self.image.get_rect()
        #self.rect.center = (x, y)
        self.rect.center = (self.pos_x, self.pos_y)
        self.speed = 2

    def load_image(self, filename):
        self.image = pygame.image.load(filename).convert()
        self.image.convert_alpha()
        self.image.set_colorkey(self.ALPHA)
        self.rect = self.image.get_rect()
        self.rect.center = (self.pos_x, self.pos_y)
        pass

    def control(self):
        """sterowanie obiektem"""

        key_state = pygame.key.get_pressed()

        if key_state[pygame.K_LEFT]:
            self.rect.x = self.rect.x - self.speed
            # self.rect.x -= self.speed

        if key_state[pygame.K_RIGHT]:
            self.rect.x = self.rect.x + self.speed
            # self.rect.x += self.speed

        if key_state[pygame.K_UP]:
            self.rect.y = self.rect.y - self.speed
            # self.rect.y -= self.speed
            pass

        if key_state[pygame.K_DOWN]:
            self.rect.y = self.rect.y + self.speed
            # self.rect.y += self.speed
            pass
        pass

    def move_restriction(self):
        """ ograniczenie przemieszczania się obiektu """

        if self.rect.right > 800:
            self.rect.right = 800
        if self.rect.left < 0:
            self.rect.left = 0

        if self.rect.top < 0:
            self.rect.top = 0
        if self.rect.bottom > 600:
            self.rect.bottom = 600
        pass

    def update(self):
        """ aktualizacja obiektu """

        self.control()  # aktualizacja pozycji
        self.move_restriction()  # ograniczenie ruchu
    pass
