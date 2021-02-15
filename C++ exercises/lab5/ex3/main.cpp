#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

vector<vector<double>>smooth(vector<vector<int>> m, int rows, int cols){
                   vector<vector<double>> ms;
                   ms.assign(rows, vector<double>{cols, 0});
                   int s,c;
                   int dx,dy,x1,y1;

                   vector<int> dirsX = {0,1,0,-1};
                   vector<int> dirsY = {1,0,-1,0};

                   for (int y = 0; y < rows; y++){
                        for (int x = 0; x < cols; x++){
                            s = m[y][x];
                            c = 1;

                            for (int i = 0; i < dirsX.size(); i++){
                                dx = dirsX[i];
                                dy = dirsY[i];

                                x1 = x + dx;
                                y1 = y + dy;

                                if (((x1 < cols) && (x1 >= 0)) && ((y1 < rows) && (y1 >= 0))){
                                    s += m[y1][x1];
                                    c++;
                                }
                            }

                            ms[y][x] = (double)s / (double)c;
                        }
                   }

                   return ms;
                   }

int main()
{
    ifstream in{"input.csv"};

    string l,item;

    int rows = 0, cols = 0;

    vector<vector<int>> m;

    if (in.good()){
        while(getline(in,l)){
            vector<int> r;
            istringstream s{l};
            while(getline(s,item,',')){
                r.push_back(stoi(item));
            }
            rows++;
            m.push_back(r);
        }

        cols = m[0].size();
    }

    in.close();

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (j == cols -1)
                cout << m[i][j];
            else{
                cout << m[i][j] << ",";
            }
        }
        cout << endl;
    }

    vector<vector<double>> m2 = smooth(m,rows,cols);

    ofstream out{"output.csv"};

    if(out.good()){
        out << "Initial matrix: " << endl << endl;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (j == cols -1)
                    out << m[i][j];
                else{
                    out << m[i][j] << ",";
                }
            }
            out << endl;
        }

        out << endl << endl;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (j == cols -1)
                    out << setprecision(2) <<  m2[i][j];
                else{
                    out << setprecision(2) << m2[i][j] << ",";
                }
            }
            out << endl;
        }
    }

    out.close();
    return 0;
}

