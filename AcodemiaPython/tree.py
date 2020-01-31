import pygame


class Tree(pygame.sprite.Sprite):
    """ Acodemia - klasa reprezentuje drzewo """

    # zakłdamy, że grafika jest tworzona na białym tle
    ALPHA = (255, 255, 255)

    def __init__(self, filename, x=0, y=0):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load(filename).convert()
        self.image.convert_alpha()
        self.image.set_colorkey(self.ALPHA)
        self.rect = self.image.get_rect()
        self.rect.center = (x, y)
        self.filename = filename

    def load_image(self, filename):
        self.image = pygame.image.load(filename).convert()
        self.image.convert_alpha()
        self.image.set_colorkey(self.ALPHA)
        self.rect = self.image.get_rect()
        pass

    def update(self):
        """ aktualizacja obiektu """
    pass
