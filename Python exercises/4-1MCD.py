def mcd(a: int, b: int) -> int:

    if b == 0:
        return a
    else:
        return mcd(b, a % b)

a = int(input("Insert first number: "))
b = int(input("Insert second number: "))

print(mcd(a,b))
