#include <iostream>

using namespace std;

int main()
{
    int year = 0;

    cout << "Inserisci anno: ";
    cin >> year;

    while(year != 0){
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
            cout << "Anno bisestile" << endl;
        }
        else{
            cout << "Anno non bisestile" << endl;
        }

        cout << "Inserisci anno: ";
        cin >> year;
    }

    return 0;
}

