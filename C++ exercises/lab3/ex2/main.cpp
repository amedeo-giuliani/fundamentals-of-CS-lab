#include <iostream>
#include "ellipse.h"

using namespace std;

int main()
{
    double a,b;

    cout << "Inserisci prima semiasse: ";
    cin >> a;

    cout << "Inserisci seconda semiasse: ";
    cin >> b;

    Ellipse* e = new Ellipse(a,b);

    cout << "Area: " << e->area() << endl;
    cout << "Distanza focale: " << e->focal_dist() << endl;
    return 0;
}

