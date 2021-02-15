import game2d

game2d.canvas_init((1000,1000))

x = 50
y = 50
dx = 5
dy = 10

img = game2d.image_load("basket_ball.png")

def keyup(code: str):
    print(code)

def keydown(code: str):
    global dx
    global dy

    if code == 'ArrowUp' or code == 'ArrowDown':
        dy = -dy
    if code == 'ArrowRight' or code == 'ArrowLeft':
        dx = -dx

    print (code)

def draw():
    global x
    global y

    game2d.canvas_fill((255,255,255))

    game2d.image_blit(img,(x,y))
    
    if 0 <= x + dx <= 800 and 0 <= y + dy <= 800:
            x += dx
            y += dy

    elif y + dy >= 800 and 0 <= x + dx <= 800:
        x += dx     


game2d.handle_keyboard(keydown, keyup)
game2d.set_interval(draw, 1000 // 30)
