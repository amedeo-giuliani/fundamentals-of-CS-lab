#include <iostream>
#include <vector>

#include "triangle.h"

using namespace std;

int main()
{
    vector<Triangle*> vt;
    int choice;
    int i;
    double a,b,c;
    double sumArea = 0;

    while(true){
        cout << "[1] Aggiungere triangolo" << endl;
        cout << "[2] Rimuovere triangolo esistente" << endl;
        cout << "[3] Calcolare somma aree dei triangoli" << endl;

        cin >> choice;

        switch(choice){
        case 1:
        {
            cout << "Inserisci primo lato: ";
            cin >> a;
            cout << "Inserisci secondo lato: ";
            cin >> b;
            cout << "Inserisci secondo lato: ";
            cin >> c;

            Triangle* t = new Triangle(a,b,c);
            vt.push_back(t);

            cout << "Fatto!" << endl;
            break;
        }
        case 2:
        {
            cout << "Inserisci l'indice del triangolo da eliminare: ";
            cin >> i;
            delete vt[i];
            vt.erase(vt.begin()+i);

            cout << "Fatto!" << endl;
            break;
        }
        case 3:
        {
            for (int j = 0; j < vt.size(); j++){
                sumArea += vt[j]->area();
            }

            cout << "Somma delle aree dei triangoli: " << sumArea;
            break;
        }

        default:
        {
            cout << "Seleziona una delle scelte possibili." << endl;
            break;
        }
        }
    }


    return 0;
}

