with open('input.csv','r') as r1:   #count rows and cols
        rows = 0
        for line in r1:
            rows += 1
            line.strip()
            nl = line.split(',')
            cols = len(nl)
            
m = [[ 0 for x in range(cols)] for y in range(rows)]


with open('input.csv','r') as r2:

    for x in range(rows):
        l = r2.readline()
        l.strip()
        s = l.split(',')
        for y in range(cols):
            m[x][y] = int(s[y])

max_change_rows = []
            
for x in range(rows):
    max = m[x][0]
    c = 1
    for y in range(cols):
        if max < m[x][y]:
            max = m[x][y]
            c += 1
    max_change_rows.append(c)
    
max_change_cols = []
    
for y in range(cols):
    max = m[0][y]
    c = 1
    for x in range(rows):
        if max < m[x][y]:
            max = m[x][y]
            c += 1
    max_change_cols.append(c)
    
print('Max variations on rows: ',max_change_rows)
print('Max variations on cols: ',max_change_cols)

to_rev = []
max_change_rows_rev = []

for x in range(rows):
    to_rev = []
    for y in range(cols):
        to_rev.append(m[x][y])

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

for y in range(cols):
    to_rev = []
    for x in range (rows):
        to_rev.append(m[x][y])
        
    to_rev.reverse()
    
    max = to_rev[0]
    c = 1
    
    for i in to_rev:
        if max < i:
            max = i
            c += 1
    max_change_cols_rev.append(c)

print()
print()
        

print('Max variations of rows reversed: ',max_change_rows_rev)
print('Max variations of cols reversed: ',max_change_cols_rev)  
            
