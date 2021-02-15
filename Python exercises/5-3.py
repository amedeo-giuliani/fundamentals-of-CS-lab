def smooth(m,rows,cols):

    ms = [[ 0 for x in range(cols)] for y in range(rows)]

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
    
    return ms


def main():

    with open('input.csv','r') as r1:   #count rows and cols
        rows = 0
        for line in r1:
            rows += 1
            nl = line.strip()
            s = line.split(',')
            cols = len(s)

    with open('input.csv','r') as r2:

        m = [[ 0.0 for x in range(cols)] for y in range(rows)]
        print(m)

        for x in range(rows):
            l = r2.readline()
            nl = l.strip()
            s = nl.split(',')
            print(s)
            
            for y in range(cols):
                m[x][y] = float(s[y])                

    m2 = smooth(m,rows,cols)

    with open('output.csv','w') as w:

        w.write("Initial matrix\n\n")

        for x in range(rows):
            for y in range(cols):
                if y == cols - 1:
                    w.write("{0:.2f}".format(m[x][y]))
                else:
                    w.write("{0:.2f}".format(m[x][y]) + ',')
            w.write("\n")

        w.write("\n")
        w.write("\n")

        w.write("Matrix with smooth\n\n")

        for x in range(rows):
            for y in range(cols):
                if y == cols - 1:
                    w.write("{0:.2f}".format(m2[x][y]))
                else:
                    w.write("{0:.2f}".format(m2[x][y]) + ',')
            w.write("\n")

        

main()
