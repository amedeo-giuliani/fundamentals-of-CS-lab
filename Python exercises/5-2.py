from random import random

cols = 5
rows = 5

def smooth(m):

    global rows,cols

    ms = [[ 0 for x in range(rows)] for y in range(cols)]

    dirs = [(0,1),(1,0),(0,-1),(-1,0)]

    for x in range(rows):
        for y in range(cols):
            s = m[x][y]
            c = 1
            
            for k in range(len(dirs)):
                dx, dy = dirs[k]
                x1 = x + dx
                y1 = y + dy
                
                if 0 <= x1 < rows and 0 <= y1 < cols:
                    s += m[x1][y1]
                    c += 1
                
            ms[x][y] = s / c

    print()
    
    return ms


def main():

    global rows,cols

    m = [[ random() * 10 for x in range(rows)] for y in range(cols)]

    m2 = smooth(m)

    print("Initial matrix")

    for x in range(rows):
        for y in range(cols):
            print("{0:.2f}".format(m[x][y]), end = '  ')
        print()

    print()
    print()

    print("Matrix with smooth")

    for x in range(rows):
        for y in range(cols):
            print("{0:.2f}".format(m2[x][y]), end = '  ')
        print()

main()
