def smooth(m,rows,cols):

    ms = [0.0] * rows * cols

    dirs = [(0,1),(1,0),(0,-1),(-1,0),(1,-1),(1,1),(-1,1),(-1,-1)]

    for y in range(rows):
        for x in range(cols):
            i = y * cols + x
            s = m[i]
            c = 1
            
            for k in range(len(dirs)):
                dy, dx = dirs[k]
                y1 = y + dy
                x1 = x + dx
                
                if 0 <= x1 < cols and 0 <= y1 < rows:
                    j = y1 * cols + x1
                    s += m[j]
                    c += 1
                       
            ms[i] = (s / c)

    return ms


def main():

    with open('input2.csv','r') as r1:   #count rows and cols
        rows = 0
        for line in r1:
            rows += 1
            nl = line.strip()
            s = nl.split(',')
            cols = len(s)

    with open('input2.csv','r') as r2:

        m = [0.0] * rows * cols

        for y in range(rows):
            l = r2.readline()
            nl = l.strip()
            s = nl.split(',')
            
            for x in range(cols):
                i = y * cols + x
                m[i] = float(s[x])

    ms = smooth(m,rows,cols)

    with open('output.csv','w') as w:

        w.write("Initial matrix\n\n")

        for y in range(rows):
            for x in range(cols):
                i = y * cols + x
                if x == cols - 1:
                    w.write("{0:.2f}".format(m[i]))
                else:
                    w.write("{0:.2f}".format(m[i]) + ',')
            w.write("\n")

        w.write("\n")
        w.write("\n")

        w.write("Matrix with smooth\n\n")

        for y in range(rows):
            for x in range(cols):
                i = y * cols + x
                print('i ',i)
                if x == cols-1:
                    w.write("{0:.2f}".format(ms[i]))
                else:
                    w.write("{0:.2f}".format(ms[i]) + ',')
            w.write("\n")

        

main()
