import game2d

ARENA_W = 1000
ARENA_H = 1000

class Ball:

    def __init__(self, x, y):
        self._x = x
        self._y = y
        self._dx = 5
        self._ballW = 200
        self._ballH = 200
        

    def move(self):
        if self._x + self._dx > ARENA_W - self._ballW:
            self._x = 0
        elif self._x + self._dx < 0:
            self._x = ARENA_W - self._ballW

        self._x += self._dx
        
    def getX(self):
        return self._x

    def getY(self):
        return self._y

game2d.canvas_init((ARENA_W,ARENA_H))
img = game2d.image_load("basketball.png")

b = Ball(100,100)

def draw():
    game2d.canvas_fill((255,255,255))
    game2d.image_blit(img, (b.getX(),b.getY()))

    
    b.move()

game2d.set_interval(draw, 1000 // 30)
