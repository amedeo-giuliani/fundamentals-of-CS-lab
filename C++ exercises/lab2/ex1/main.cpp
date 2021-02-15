#include <iostream>

using namespace std;

int main()
{
    string txt = "";
    string numbers = "0123456789";
    int c = 0;
    int total = 0;
    float perc = 0.0;

    cout << "Insert string: ";
    getline(cin,txt);

    for (int i = 0; i < txt.length(); i++){
        for (int j = 0; j < numbers.length(); j++){
            if (txt[i] == numbers[j]){
                c++;
            }
        }
    }

    total = txt.length();
    perc = (float)(((float)c / (float)total) * 100);

    cout << total << c << endl;

    cout << "Percentuale di cifre presenti nella stringa: " << perc << "%" << endl;

    return 0;
}


