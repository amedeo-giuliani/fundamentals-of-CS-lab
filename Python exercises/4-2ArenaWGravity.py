import game2d

i = 0

class Actor:

    def move(self):
        raise NotImplementedError("Abstract method!")

    def collide(self, other: 'Actor'):
        raise NotImplementedError("Abstract method!")

    def rect(self) -> (int,int,int,int):
        raise NotImplementedError("Abstract method!")

    def symbol(self) -> (int,int):
        raise NotImplementedError("Abstract method!")

class Arena():

    def __init__(self, w, h):
        self._w, self._h = w, h
        self._actors = []

    def add(self, a: Actor):
        if a not in self._actors:
            self._actors.append(a)

    def remove(self, a: Actor):
        if a in self._actors:
            self._actors.remove(a)

    def moveAll(self):

        actors = list(reversed(self._actors))

        for a in actors:
            prev_pos = a.rect()
            a.move()

            if a.rect() != prev_pos:
                for other in actors:

                    if other is not a and self.checkCollision(a, other):
                        a.collide(other)
                        other.collide(a)

    def checkCollision(self, a1: Actor, a2: Actor) -> bool:
        ax1, ay1, aw1, ah1 = a1.rect()
        ax2, ay2, aw2, ah2 = a2.rect()

        return (ay2 < ay1 + ah1 and ay1 < ay2 + ah2
                and ax2 < ax1 + aw1 and ax1 < ax2 +  aw2
                and a1 in self._actors and a2 in self._actors)

    def arenaSize(self) -> (int,int):
        return self._w, self._h

    def actors(self) -> list:
        return list(self._actors)


class Ball(Actor):

    def __init__(self,arena,x,y):
        self._x, self._y = x, y
        self._w, self._h = 20, 20
        self._speed = 5
        self._dx, self._dy = self._speed, self._speed
        self._arena = arena     
        arena.add(self)

    def move(self):

        arena_w, arena_h = self._arena.arenaSize()

        if not ( 0 <= self._x + self._dx <= arena_w - self._w ):
            self._dx = -self._dx
        if not ( 0 <= self._y + self._dy <= arena_h - self._h ):
            self._dy = -self._dy
        else:
            self._dy += 0.4

        self._x += self._dx
        self._y += self._dy

    def collide(self,other):
        global i

        if i >= 10:
        
            if not isinstance(other,self):
                x, y, w, h = other.rect()

                if x < self._x:
                    self._dx = self._speed
                else:
                    self._dx = -self._speed

            i = 0

    def rect(self):
        return self._x, self._y, self._w, self._h

    def symbol(self):
        return 0,0

def setup():
    global arena, ball

    arena = Arena(300,300)
    Ball(arena,10,10)
    Ball(arena,280,10)

    game2d.canvas_init(arena.arenaSize())
    ball = game2d.image_load("ball.png")
    game2d.set_interval(draw, 1000 // 30)

def draw():
    global i
    
    arena.moveAll()
    i += 1

    game2d.canvas_fill((255,255,255))

    for a in arena.actors():
        x, y, w, h = a.rect()

        xs, ys = a.symbol()

        game2d.image_blit(ball, (x,y), area = (xs,ys,w,h))

setup()
