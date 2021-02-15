#include <iostream>
#include <math.h>

using namespace std;

float sphere_density(float r, float m){
    float d;

    float v = 4/3 * 3.14 * pow(r,3);

    d = float(m/v);

    return d;
}

int main()
{
    float m,r;

    cout << "Inserisci massa della sfera: ";
    cin >> m;

    cout << "Inserisci raggio della sfera: ";
    cin >> r;

    cout << "Densita' della sfera: " << sphere_density(r,m) << endl;

    return 0;
}

