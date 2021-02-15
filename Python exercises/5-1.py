with open("input.txt","r") as f:

    t = ''
    flag = False
    c = 0

    for line in f:

        print(line)

        for i in range(len(line)):

            if line[i] == '<' or line[i] == '>':
                flag = not flag

            if line[i] == '<':
                c += 1

            if flag:
                if line[i] != '<' and line[i] != '>':
                    t += line[i]

            if c > 1:
                t += '|'
                c = 0

print(t)
