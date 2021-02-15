#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    srand(time(nullptr));

    int nl;
    int d1,d2;

    cout << "Numero di lanci? ";
    cin >> nl;

    ofstream out{"output.txt"};

    for (int i = 0; i < nl; i++){
        d1 = 1 + rand() % 5;
        d2 = 1 + rand() % 5;
        if (out.good())
            out << d1 << " " << d2 << endl;
    }

    out.close();

    return 0;
}

