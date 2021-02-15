#include <iostream>
#include <vector>

using namespace std;

vector<int> searchPrimes(int n){
    vector<int> p;
    vector<bool> isPrime;

    for (int i = 0; i <= n; i++)
        isPrime.push_back(true);

    for (int i = 2; i <= n; i++){
        if (isPrime[i]){
            p.push_back(i);

            for (int j = 0; j < n / i +1; j++)
                isPrime[i * j] = false;
        }
    }

    return p;
}

int main()
{
    int n;

    cout << "Inserire il numero limite: ";
    cin >> n;

    vector <int> r = searchPrimes(n);

    for (auto i : r)
        cout << i << " ";

    cout << endl;

    cout << "Numeri primi trovati: " << r.size() << endl;

    return 0;
}

