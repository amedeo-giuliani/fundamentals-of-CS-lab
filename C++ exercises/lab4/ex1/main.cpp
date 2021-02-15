#include <iostream>

using namespace std;

int mcd(int n1, int n2){
    if (n2 == 0)
        return n1;

    return mcd(n2, n1 % n2);
}

int main()
{
    int n1,n2;

    cout << "Inserisci primo numero: ";
    cin >> n1;

    cout << "Inserisci secondo numero: ";
    cin >> n2;

    cout << "Massimo comun divisore: " << mcd(n1,n2) << endl;


    return 0;
}

