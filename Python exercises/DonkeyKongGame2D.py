import game2d

from DonkeyKong import Arena, Mario, Platform, Ladder, Barrel
from dk_elements import *
import random

def setup():
    global arena, m, sprites, bg

    arena = Arena(224,256)
    m = Mario(arena,0,232)
    
    # import delle caratteristiche degli oggetti Platform e Ladder
    for i in range(len(map_elements)):
        o, x, y, w, h = map_elements[i]
        if o == 'Platform':
            Platform(arena,int(x),int(y),int(w),int(h))
        elif o == 'Ladder':
            Ladder(arena,int(x),int(y),int(w),int(h))

    game2d.canvas_init(arena.arenaSize())
    sprites = game2d.image_load("dk_sprites.png")
    bg = game2d.image_load('dk_background.png')

    game2d.handle_keyboard(keydown,keyup)
    game2d.set_interval(draw, 1000 // 30)

def draw():

    # generazione casuale dei barili in alto
    r = random.randrange(0,200)

    if r == 3:
        Barrel(arena,10,50)
    
    arena.moveAll()

    game2d.image_blit(bg,(0,0))

    for a in arena.actors():
        if not isinstance(a,Platform):
            x, y, w, h = a.rect()
            xs, ys = a.symbol()
            game2d.image_blit(sprites, (x,y), area = (xs,ys,w,h))

def keydown(code):
    print(code + " dn")
    if code == "ArrowLeft":
        m.goLeft()
    elif code == "ArrowRight":
        m.goRight()
    elif code == "Space":
        m.jump()
    elif code == "ArrowUp":
        m.goUp()
    elif code == "ArrowDown":
        m.goDown()

def keyup(code):
    print(code + " up")
    if code in ("ArrowLeft", "ArrowRight","ArrowDown","ArrowUp") and code != "Space":
        m.stay()

setup()
