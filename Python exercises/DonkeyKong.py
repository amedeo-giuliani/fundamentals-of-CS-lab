from actors import *

class Mario(Actor):

    def __init__(self, arena, x,y):
        self._x = x
        self._y = y
        self._w, self._h = 16, 16
        self._speed = 3
        self._maxspeed = 3
        self._dx = 0
        self._dy = 0
        self._g = 0.4
        self._land = False #True: Mario si trova su una piattaforma, False: Mario sta saltando o cadendo
        self._climb = False #True: Mario sta salendo, False: Mario non sta salendo
        self._ladder = None
        self._hit = False #True: Mario colpito da un barile, False: Mario ancora in gioco
        self._arena = arena
        arena.add(self)

    def move(self):

        if self._hit:
            arena.remove(self)  # Mario ucciso dal barile, viene rimosso dal gioco

        arena_w, arena_h = self._arena.arenaSize()
        self._y += self._dy

        if self._dx != 0 and self._climb:
            self._climb = False
            self._dy = 0
            
        if not (self._land or self._climb):
            self._dy += self._g
            self._dy = min(self._dy,self._maxspeed)

        self._land = False

        # se Mario è in collisione con una scala, può salire
        if self._ladder != None:
            sx, sy, sw, sh = self.rect()
            ox, oy, ow, oh = self._ladder.rect()

            if not ( ox < sx + sw // 2 < ox + ow and oy <= sy + sh <= oy + oh):
                if self._climb:
                    self._y -= self._dy
            
        self._x += self._dx

        # limiti dell'arena che Mario non può superare
        if self._x < 0:
            self._x = 0
        elif self._x > arena_w - self._w:
            self._x = arena_w - self._w

    def goRight(self):
        self._dx = self._speed

    def goLeft(self):
        self._dx = -self._speed

    def goUp(self):
        # Mario può salire solo se è in collisione con una scala
        if self._ladder and (self._climb or self._land):
            self._climb = True
            self._dy = -self._maxspeed
        else:
            self._climb = False

    def goDown(self):
        # Mario può scendere solo se è in collisione con una scala
        if self._ladder and (self._climb or self._land):
            self._climb = True
            self._dy = self._maxspeed
        else:
            self._climb = False

    def jump(self):
        # Mario può saltare solo se è su una piattaforma
        if self._land:
            self._dy = -self._speed
            self._land = False

    def stay(self):
        self._dx = 0
        self._dy = 0

    def collide(self,other):
        # rettangolo occupato dell'oggetto "other"
        ox, oy, ow, oh = other.rect()
        # rettangolo occupato da Mario
        sx, sy, sw, sh = self.rect()
        
        # gestione collisione tra Mario e le piattaforme
        if isinstance(other,Platform) and not self._climb:            
            if sy + sh < oy + oh:
                self._land = True
                self._y = oy - sh
                
        # gestione collisione tra Mario e le scale
        elif isinstance(other,Ladder):
            if ox <= sx + sw // 2 <= ox + ow and oy <= sy + sh <= oy + oh:
                self._ladder = other
            else:
                self._ladder = None

        # gestione collisione tra Mario ed i barili
        elif isinstance(other,Barrel):
            if ox <= sx + sw <= ox + ow:
                self._hit = True
    
    def rect(self):
        return self._x, self._y, self._w, self._h

    def symbol(self):
        #if self._climb:
         #   return 124,12
        return 92,2

class Platform(Actor):

    def __init__(self,arena,x,y,w,h):
        self._w , self._h = w , h
        self._dx , self._dy = 0, 0
        self._x = x
        self._y = y
        self._arena = arena
        arena.add(self)

    #le piattaforme sono oggetti immobili
    def move(self):
        pass

    def collide(self,other):
        pass

    def rect(self):
        return self._x, self._y, self._w, self._h

    def symbol(self):
        return -1,-1

class Ladder(Actor):

    def __init__(self,arena,x,y,w,h):
        self._x = x
        self._y = y
        self._w = w
        self._h = h
        self._arena = arena
        arena.add(self)

    #le scale sono oggetti immobili
    def move(self):
        pass

    def collide(self,other):
        pass

    def rect(self):
        return self._x,self._y,self._w,self._h

    def symbol(self):
        return -1,-1

class Barrel(Actor):

    def __init__(self,arena,x,y):
        self._x = x
        self._y = y
        self._w = 15
        self._h = 12
        self._speed = 3
        self._maxspeed = 3
        self._dx = self._maxspeed
        self._dy = 0
        self._g = 0.4
        self._land = False
        self._drop = False
        self._arena = arena
        arena.add(self)

    def move(self):

        arena_w , arena_h = self._arena.arenaSize()

        #self._x += self._dx
        self._y += self._dy

        self._dy = self._maxspeed

        if self._land:
            self._dy = 0
            self._x += self._dx
        else:
            self._dy += self._g
            self._x += self._dx // 2

        self._land = False

        #gestione dei rimbalzi ai limiti dell'arena
        if self._x < 0:
            #if self._land == False:
            self._dx = self._maxspeed
            self._dy = self._maxspeed + 1

        if self._x + self._w > arena_w:
            #if self._land == False:
            self._dx = -self._maxspeed
            self._dy = self._maxspeed + 1

    def collide(self,other):
        # rettangolo occupato dell'oggetto "other"
        ox, oy, ow, oh = other.rect()
        # rettangolo occupato dal barile
        sx, sy, sw, sh = self.rect()

        # gestione collisioni tra i barili e le piattaforme
        if isinstance(other,Platform):            
            if sy + sh < oy + oh:
                self._land = True
                self._y = oy - sh
        # gestione collisioni tra i barili e le scale per la caduta casuale incompleta, commented out
        #elif isinstance(other,Ladder):
        #    if ox <= sx + sw // 2 <= ox + ow and oy <= sy + sh <= oy + oh:
        #        self._drop = True

    def rect(self):
        return self._x,self._y,self._w,self._h

    def symbol(self):
        return 65,257

def print_arena(arena):
    for a in arena.actors():
        print(type(a).__name__, '@', a.rect())

    
def main():
    arena = Arena(320, 240)
    print_arena(arena)

    while input() != 'x':
        arena.moveAll()
        print_arena(arena)

if __name__ == '__main__':
    main()

