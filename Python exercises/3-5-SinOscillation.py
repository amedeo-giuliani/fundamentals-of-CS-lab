import game2d
import math

ARENA_W = 1000
ARENA_H = 1000

class Ball:

    def __init__(self, x, y):
        self._x = x
        self._y = y
        self._y0 = y
        self._dx = 5
        self._ballW = 200
        self._ballH = 200
        self._k = 100
        

    def move(self):
        
        if self._x + self._dx > ARENA_W - self._ballW:
            self._x = 0
        elif self._x + self._dx < 0:
            self._x = ARENA_W - self._ballW

        self._x += self._dx
        self._y = self._y0 + self._k * math.sin (self._x*math.pi/180)
        
    def getX(self):
        return self._x

    def getY(self):
        return self._y

game2d.canvas_init((ARENA_W,ARENA_H))
img = game2d.image_load("basketball.png")

b1 = Ball(100,100)
b2 = Ball(500,500)

def draw():
    game2d.canvas_fill((255,255,255))
    game2d.image_blit(img, (b1.getX(),b1.getY()))
    game2d.image_blit(img, (b2.getX(),b2.getY()))

    b1.move()
    b2.move()

game2d.set_interval(draw, 1000 // 30)
