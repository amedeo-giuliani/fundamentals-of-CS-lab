import game2d

ARENA_W = 1000
ARENA_H = 1000

class Ball:

    def __init__(self, x,y):
        self._x = x
        self._y = y
        self._dx = 5
        self._dy = 10
        self._g = 0.4

    def move(self):

        if not (0 <= self._x + self._dx <= ARENA_W - 200):
            self._dx = -self._dx

        if not (0 <= self._y + self._dy <= ARENA_H - 200):
            self._dy = -self._dy

        self._x += self._dx
        self._y += self._dy
        self._dy += self._g

    def getX(self):
        return self._x

    def getY(self):
        return self._y

balls = [Ball(600,600), Ball(300,300), Ball(700,300)]
game2d.canvas_init((ARENA_W, ARENA_H))
img = game2d.image_load("basketball.png")

def draw():
    game2d.canvas_fill((255,255,255))

    for i in balls:
        game2d.image_blit(img, (i.getX(),i.getY()))

    for i in balls:
        i.move()

game2d.set_interval(draw, 1000 //30)
