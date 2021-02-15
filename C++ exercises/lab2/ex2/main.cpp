#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;

    vector<int> v;

    cout << "Insert value: ";
    cin >> n;

    while (n >= 0){
        v.push_back(n);

        cout << "Insert value: ";
        cin >> n;
    }

    int max = v[v.size()-1];
    int c = 0;

    for (int i = 0; i < v.size(); i++){
        if (v[i] > max)
            c++;
    }

    cout << "Maximum values: " << c << endl;


    return 0;
}

