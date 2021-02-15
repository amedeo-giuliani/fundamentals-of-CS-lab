def capitalize(text: str) -> str:

    flag = False
    text2 = ''

    for i in range(len(text)):
        c = text[i]
        
        if c == '*':
            flag = not flag
            
        if flag:
            c = c.upper()

        if c != '*':
            text2 += c

    return text2

    

def main():

    text1 = input("Insert text: ")

    text2 = capitalize(text1)

    print(text2)

main()
