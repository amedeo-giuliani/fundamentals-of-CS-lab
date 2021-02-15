#include <iostream>
#include "triangle.h"

using namespace std;

int main()
{
    double a,b,c;

    cout << "Inserisci primo lato: ";
    cin >> a;

    cout << "Inserisci secondo lato: ";
    cin >> b;

    cout << "Inserisci terzo lato: ";
    cin >> c;


    Triangle* t = new Triangle(a,b,c);

    cout << "Perimetro triangolo: " << t->perimeter();
    cout << endl;
    cout << "Area triangolo: " << t->area();
    cout << endl;

    return 0;
}

