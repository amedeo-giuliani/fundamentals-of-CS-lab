#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> val;

    cout << "Inserisci numero: ";
    cin >> n;

    while (n >= 0){
        val.push_back(n);
        cout << "Inserisci numero: ";
        cin >> n;
    }

    reverse(val.begin(),val.end());

    int max = val[0];
    int c = 1;

    for (int i = 0; i < val.size(); i++){
        if (val[i] > max){
            max = val[i];
            c++;
        }
    }

    cout << "Numero di tetti visibili al contrario: " << c << endl;

    return 0;
}

