def anagrammi(s:str):

    comb = []

    if s == '':
        return [s]

    else:
        for i in range(len(s)):
            s2 = s[i+1:]
            s3 = s[:i]
            comb2 = anagrammi(s2+s3)

            for j in range(len(comb2)):
                t = s[i] + comb2[j]
                comb.append(t)
        return comb

s = input('Insert string: ')     
print(anagrammi(s))
