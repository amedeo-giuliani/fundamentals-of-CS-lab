def combine(n: int, s: str):

    comb = []
    
    if n == 1:
        for i in range(len(s)):
            comb.append(s[i])

        return comb

    else:

        for i in range(len(s)):
            comb2 = combine(n-1,s)
            for j in range(len(comb2)):
                t = s[i] + comb2[j]
                comb.append(t)
        return comb

n = int(input("Insert number of *wheels*: "))
s = input("Insert signs: ")

print(combine(n,s))
