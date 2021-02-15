#include <iostream>
#include <vector>

using namespace std;

vector<string> anagrammi(string signs){
    vector<string> comb;
    vector<string> comb2;

    string signs_sx, signs_dx;
    string t;

    if (signs.empty()){
        comb.push_back(signs);
        return comb;
    }

    for (int i = 0; i < signs.length(); i++){
        signs_sx = signs.substr(0,i);
        signs_dx = signs.substr(i+1,signs.length()-i-1);
        comb2 = anagrammi(signs_sx + signs_dx);

        for (int j = 0; j < comb2.size(); j++){
            t = signs[i] + comb2[j];
            comb.push_back(t);
        }
    }

    return comb;
}

int main()
{
    string signs;
    cout << "Insert signs: ";
    cin >> signs;

    vector<string> a = anagrammi(signs);

    for (int i = 0; i < a.size(); i++){
        cout << a[i]<< endl;
    }

    return 0;
}

