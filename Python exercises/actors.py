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
