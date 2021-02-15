def dec2bin(n: int) -> str:
    last = n % 2
    init = 0

    if n == 0:
        return '0'
    else:
        init = dec2bin(n // 2)

    return str(init) + str(last)

number = int(input('Insert decimal number: '))
print('Binary number: ',dec2bin(number))
