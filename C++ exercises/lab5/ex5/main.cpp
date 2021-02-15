#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string l,item;

    int rows = 0, cols = 0;

    vector<vector<int>> m;

    ifstream in {"input.csv"};
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

    vector<int> max_changes_rows;
    vector<int> max_changes_cols;

    int max;
    int c;

    for (int i = 0; i < rows; i++){
        max = m[i][0];
        c = 1;
        for (int j = 0; j < cols; j++){
            if (m[i][j] > max){
                max = m[i][j];
                c++;
            }
        }
        max_changes_rows.push_back(c);
    }

    for (int j = 0; j < cols; j++){
        max = m[0][j];
        c = 1;
        for (int i = 0; i < rows; i++){
            if (m[i][j] > max){
                max = m[i][j];
                c++;
            }
        }
        max_changes_cols.push_back(c);
    }

    cout << "Max variations on rows: " << endl;

    for (int i = 0; i < max_changes_rows.size(); i++){
        cout << "Row #" << i << ": " << max_changes_rows[i] << endl;
    }

    cout << "Max variations on cols: " << endl;

    for (int i = 0; i < max_changes_cols.size(); i++){
        cout << "Col #" << i << ": " << max_changes_cols[i] << endl;
    }

    vector<int> max_changes_cols_rev;
    vector<int> max_changes_rows_rev;

    vector<int> to_rev;

    for (int i = 0; i < rows; i++){
        to_rev.clear();
        for (int j = 0; j< cols; j++){
            to_rev.push_back(m[i][j]);
        }

        reverse(to_rev.begin(),to_rev.end());

        max = to_rev[0];
        c = 1;

        for (auto k : to_rev){
            if (k > max){
                max = k;
                c++;
            }
        }
        max_changes_rows_rev.push_back(c);
    }

    cout << "Max variations on rows [reversed]: " << endl;

    for (int i = 0; i < max_changes_rows_rev.size(); i++){
        cout << "Row #" << i << ": " << max_changes_rows_rev[i] << endl;
    }

    for ( int j = 0; j < cols; j++){
        to_rev.clear();
        for (int i  = 0; i < rows; i++){
            to_rev.push_back(m[i][j]);
        }

        reverse(to_rev.begin(),to_rev.end());

        max = to_rev[0];
        c = 1;

        for (auto k : to_rev){
            if (k > max){
                max = k;
                c++;
            }
        }
        max_changes_cols_rev.push_back(c);
    }

    cout << "Max variations on cols [reversed]: " << endl;

    for (int i = 0; i < max_changes_cols_rev.size(); i++){
        cout << "Col #" << i << ": " << max_changes_cols_rev[i] << endl;
    }

    return 0;
}

