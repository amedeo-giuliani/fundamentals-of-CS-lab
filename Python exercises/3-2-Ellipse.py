import math

class Ellipse:
    
    def __init__(self, a: float, b: float):
        if a >= b:
            self._a = a
            self._b = b
        else:
            self._b = a
            self._a = b

    def getArea(self) -> float:
        return math.pi * self._a * self._b

    def getDistance(self) -> float:
        return 2 * math.sqrt((math.pow(self._a,2)-pow(self._b,2)))


def main():

    a = float(input("Inserisci primo semiasse: "))
    b = float(input("Inserisci secondo semiasse: "))

    e = Ellipse(a,b)

    print("Area ellisse: ", e.getArea())
    print("Distanza focale: ", e.getDistance())

main()

    

    
