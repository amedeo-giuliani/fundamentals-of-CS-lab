text = input("Insert text: ")

count = [0] * 10

for i in range(len(text)):
    if text[i] in '0123456789':
        count[int(text[i])] += 1

for i in range(len(count)):
    print("Cifra " + str(i) + ": " + "\t" + str(count[i]))
