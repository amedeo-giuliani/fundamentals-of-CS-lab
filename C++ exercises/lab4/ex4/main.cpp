#include <iostream>
#include <vector>
#include <string>
#include <vector>

using namespace std;

vector<string> combine(int n, string signs){
    vector<string> comb;
    vector<string> comb2;
    string t;

    if (n == 1){
        for (auto s : signs){
            auto s2 = string(1,s);
            comb.push_back(s2);
        }
        return comb;
    }

    for (auto s : signs){
        auto s2 = string(1,s);
        comb2 = combine(n-1,signs);

        for (auto c : comb2){
            t = s2 + c;
            comb.push_back(t);
        }
    }

    return comb;
}

int main()
{
    int n;
    string signs;

    cout << "Insert number of *wheels*: ";
    cin >> n;

    cout << "Insert signs: ";
    cin >> signs;

    vector<string> c = combine(n,signs);

    for (auto i : c){
        cout << i << endl;
    }

    return 0;
}

