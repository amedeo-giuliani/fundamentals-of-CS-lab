import game2d

def SierpTriangle(x0,y0,w0,h0):

    w4 = w0 / 2
    h4 = h0 / 2

    if w0 <= 1 or h0 <= 1:
        return

    for r in range(2):
        for c in range(2):
            x1 = x0 + w4 * c
            y1 = y0 + w4 * r

            if r == 0 and c == 1:
                game2d.draw_rect((255,255,255) , (x1,y1,w4,h4))

            else:
                SierpTriangle(x1,y1,w4,h4)

game2d.canvas_init((800,800))
game2d.draw_rect((0,0,0) , (100,100,200,200))
SierpTriangle(100,100,200,200)
    
