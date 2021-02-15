class Skyscrapers:
    def __init__(self,m,rows,cols):
        self._maxV = rows - 2
        self._m = m
        self._r = rows
        self._c = cols

    def max_changes(self):
        max_change_rows = []
            
        for y in range(self._r):
            if 1 <= y <= self._r -2:
                max = m[y][0]
                c = 1
            for x in range(self._c):
                if 1 <= x <= self._c -2:
                    if max < m[y][x]:
                        max = m[y][x]
                        c += 1
            max_change_rows.append(c)
            
        max_change_cols = []
            
        for x in range(self._c):
            if 1 <= x <= self._c -2:
                max = m[0][x]
                c = 1
            for y in range(self._r):
                if 1 <= y <= self._r -2:
                    if max < m[y][x]:
                        max = m[y][x]
                        c += 1
                    
            max_change_cols.append(c)

    def max_changes_reversed(self):
        to_rev = []
        max_change_rows_rev = []

        for y in range(self._r):
            to_rev = []
            for x in range(self._c):
                if 1 <= x <= self._c -2 and 1 <= y <= self._r -2:
                    to_rev.append(m[y][x])

            to_rev.reverse()

            max = to_rev[0]
            c = 1

            for i in to_rev:
                if max < i:
                    max = i
                    c += 1
            max_change_rows_rev.append(c)
                    
        max_change_cols_rev = []
        to_rev = []

        for x in range(self._c):
            to_rev = []
            for y in range (self._r):
                if 1 <= x <= self._c -2 and 1 <= y <= self._r -2:
                    to_rev.append(m[y][x])
                
            to_rev.reverse()
            
            max = to_rev[0]
            c = 1
            
            for i in to_rev:
                if max < i:
                    max = i
                    c += 1
            max_change_cols_rev.append(c)                    

    def get_val(self,y,x):
        return m[y][x]
    
    def play_at(self,y,x):
        if 1 <= x <= self._c - 2 and 1 <= y <= self._r -2:
            self._m[y][x] += 1
        if self._m[y][x] > self._maxV:
            self._m[y][x] = 0

    def finished(self):
        for y in range(self._r):
            for x in range(self._c):
                if not (1 <= y <= self._r -2) and not (1 <= x <= self._c -2):
                    if m[y][x] != 0:
                        if 
                        
        return False

            
def main():      

    rows = 5
    cols = 5
                
    m = [[ 0 for x in range(cols)] for y in range(rows)]


    with open('input.csv','r') as r:
        for y in range(rows):
            l = r.readline()
            nl = l.strip()
            s = nl.split(',')
            for x in range(cols):
                m[y][x] = int(s[x])

    s = Skyscrapers(m,rows,cols)

    while not s.finished():
        for y in range(rows):
            for x in range(cols):
               print(m[y][x], end = ' ')
            print()
        
        x = int(input('X: '))
        y = int(input('Y: '))
        
        s.play_at(x,y)


main()  
