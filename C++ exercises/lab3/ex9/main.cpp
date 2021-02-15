#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in{"output.txt"};

    string l;
    int val1,val2;
    vector<int> sum;

    if (in.good()){

        while(in >> val1 >> val2){
            sum.push_back(val1+val2);
        }
    }

    in.close();

    for (int i = 0; i < sum.size(); i++){
        cout << i+1 << " launch sums to: " << sum[i] << endl;
    }

    return 0;
}

