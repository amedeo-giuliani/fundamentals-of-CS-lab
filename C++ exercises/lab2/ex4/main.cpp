#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string txt;
    string numbers = "0123456789";

    cout << "Inserisci stringa: ";
    getline(cin,txt);

    vector<int>v;
    v.assign(10, 0);

    for (int i = 0; i < txt.length(); i++){
        for (int j = 0; j < numbers.length(); j++){
            if (txt[i] == numbers[j]){
                v[j] += 1;
                cout << v[i] << endl;
            }
        }
    }

    for (int i = 0; i < v.size(); i++){
        cout << "Cifra " << i << ":" << "\t" << v[i] << endl;
    }

    return 0;
}

