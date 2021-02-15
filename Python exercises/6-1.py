class Person:
    def __init__(self,name,surname,bd,bm,by):
        self._name = name
        self._surname = surname
        self._bd = bd
        self._bm = bm
        self._by = by

    def age(self,d,m,y) -> int:
        age = y - self._by

        if m <= self._bm and d <= self._bd:
            age -= 1

        return age


def main():

    name = input('Insert your name: ')
    surname = input('Insert your surname: ')
    
    d = int(input('Insert birth day: '))
    m = int(input('Insert birth month: '))
    y = int(input('Insert birth year: '))

    p = Person(name,surname,d,m,y)

    cd = int(input('Insert current day: '))
    cm = int(input('Insert current month: '))
    cy = int(input('Insert current year: '))

    print('Age: ',p.age(cd,cm,cy))

main()
