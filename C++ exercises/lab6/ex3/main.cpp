#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

vector<double>smooth(vector<int> m, int rows, int cols){
    vector<double> ms;
    ms.assign(rows*cols,0.0);
    int s,c,k,l;
    int dj,di,j1,i1;

    vector<int> dirsJ = {0,1,0,-1,1,1,-1,-1};
    vector<int> dirsI = {1,0,-1,0,1,-1,1,-1};

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            k = i * cols + j;
            s = m[k];
            c = 1;

            for (int h = 0; h < dirsJ.size(); h++){
                dj = dirsJ[h];
                di = dirsI[h];

                j1 = j + dj;
                i1 = i + di;

                if (((j1 < cols) && (j1 >= 0)) && ((i1 < rows) && (i1 >= 0))){
                    l = i1 * cols + j1;
                    s += m[l];
                    c++;
                }
            }

            ms[k] = (double)s / (double)c;
        }
    }

    return ms;
}

int main()
{
    ifstream in{"input.csv"};

    string l,item;

    int rows = 0, cols = 0;
    int k;

    vector<int> m;

    if (in.good()){
        while(getline(in,l)){
            istringstream s{l};
            while(getline(s,item,',')){
                m.push_back(stoi(item));
            }
            if (rows == 0)
                cols = l.length();
            rows++;
        }
    }

    cols = m.size() / rows;

    in.close();

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            k = i * cols + j;
            if (j == cols -1)
                cout << m[k];
            else{
                cout << m[k] << ",";
            }
        }
        cout << endl;
    }

    vector<double> m2 = smooth(m,rows,cols);

    ofstream out{"output.csv"};

    if(out.good()){
        out << "Initial matrix: " << endl << endl;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                k = i * cols + j;
                if (j == cols -1)
                    out << m[k];
                else{
                    out << m[k] << ",";
                }
            }
            out << endl;
        }

        out << endl << endl;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                k = i * cols + j;
                if (j == cols -1)
                    out << setprecision(2) <<  m2[k];
                else{
                    out << setprecision(2) << m2[k] << ",";
                }
            }
            out << endl;
        }
    }

    out.close();
    return 0;
}

