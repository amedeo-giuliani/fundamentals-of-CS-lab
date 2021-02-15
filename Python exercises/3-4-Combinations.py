def genComb(txt: str) -> str:

    txt2 = ''

    for i in range(len(txt)):
        for j in range(len(txt)):
            for k in range(len(txt)):
                txt2 += txt[i] + txt[j] + txt[k]
                txt2 +=  "\t"

    return txt2

def main():
    t1 = input("Insert text: ")

    t2 = genComb(t1)

    print(t2)
    
main()
