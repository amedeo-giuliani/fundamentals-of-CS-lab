#include "skyscraper.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Skyscraper::Skyscraper(string fn)
{
    filename = fn;
    readGameArena();
}

//lettura del file contenente la matrice iniziale
void Skyscraper::readGameArena(){
    string l,item;

    m.clear();

    rows = 0;
    cols = 0;

    ifstream in {filename};
    if (in.good()){
        while(getline(in,l)){
            vector<int> row;
            if (l.length()>1){
                istringstream s{l};
                while(getline(s,item,',')){
                    row.push_back(stoi(item));
                }
                rows++;
                m.push_back(row);
            }
        }

        cols = m[0].size();
    }

    maxV = rows-2;

    in.close();
}

string Skyscraper::getVal(int i, int j)
{
    return to_string(m[i][j]);
}

void Skyscraper::playAt(int i, int j)
{
    if ((j >= 1) && (j <= cols - 2) && (i >= 1) && (i <= rows - 2))
        m[i][j]++;
    else
        fillCell(i,j);

    if (m[i][j] > maxV)
        m[i][j] = 0;
}

//controllo dei tetti massimi sul vettore
int Skyscraper::maxChanges(vector<int> cells)
{
    int c = 1;
    int max = cells[0];

    for (auto i : cells){
        if (i > max){
            max = i;
            c++;
        }
    }

    return c;
}

//conteggio dei tetti massimi sul vettore reversed
int Skyscraper::maxChangesReversed(vector<int> cells)
{
    int c = 1;

    reverse(cells.begin(),cells.end());
    int max = cells[0];

    for (auto i : cells){
        if (i > max){
            max = i;
            c++;
        }
    }

    return c;
}

bool Skyscraper::finished()
{
    vector<int> cells;
    vector<int>unique;
    int max = 0;
    int maxRev = 0;

    for (int i = 1; i < rows - 1; i++){
        for (int j = 1; j < cols - 1; j++)
            if (m[i][j] == 0)
                return false;
    }

    for (int i = 0; i < rows; i++){
        if ((i == 0) || (i == rows - 1)){
            for (int j = 1; j < cols - 1; j++){
                for (int k = 1; k < rows - 1; k++)  //creazione di un vettore con gli elementi della colonna j-esima giocabile
                    cells.push_back(m[k][j]);

                for (auto c : cells)
                    cout << "Col control: " << c << " ";

                cout << endl;

                //controllo dell'unicità dei singoli valori all'interno di ogni colonna
                for (int c = 0; c < cells.size(); c++)
                    unique.push_back(count(cells.begin(),cells.end(),c+1));

                for (auto u : unique)
                    if (u != 1)
                        return false;

                max = maxChanges(cells);
                maxRev = maxChangesReversed(cells);
                cells.clear();

                //controllo del vincolo in alto
                if (m[0][j] != 0)
                    if (m[0][j] != max)
                        return false;

                //controllo del vincolo in basso
                if (m[rows-1][j] != 0)
                    if (m[rows-1][j] != maxRev)
                        return false;
            }
        }

        if ((i >= 1) && (i <= rows - 3)){
            for (int j = 1; j < cols -1 ; j++){
                for (int k = 1; k < cols -1; k++)   //creazione di un vettore con gli elementi della riga i-esima giocabile
                    cells.push_back(m[i][k]);

                //controllo dell'unicità dei singoli valori all'interno di ogni riga
                for (int c = 0; c < cells.size(); c++)
                    unique.push_back(count(cells.begin(),cells.end(),c+1));

                for (auto u : unique)
                    if (u != 1)
                        return false;

                max = maxChanges(cells);
                maxRev = maxChangesReversed(cells);
                cells.clear();

                //controllo del vincolo a sinistra
                if (m[i][0] != 0)
                    if (m[i][0] != max)
                        return false;

                //controllo del vincolo a destra
                if(m[i][cols-1] != 0)
                    if (m[i][cols-1] != maxRev)
                        return false;
            }
        }
    }

    return true;        //se non si entra in nessun controllo che ritorna false, si può ritornare true perché la partita è vinta
}

void Skyscraper::save(string fn)
{
    ofstream out{fn};

    //salvataggio della partita corrente su file csv valore per valore
    if (out){
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (j != cols -1)
                    out << getVal(i,j) << ",";
                else
                    out << getVal(i,j);
            }
            out << endl;
        }
    }

    out.close();
}

void Skyscraper::fillCell(int i, int j)
{
    if (m[i][j] != 0){
        if ((i == 0) || (i == rows-1)){
            if (m[i][j] == maxV){
                cout << i << " " << j << endl;
                if (i == 0){
                    for (int k = 2; k <= rows-1 ; k++)
                        m[rows-k][j] = rows-k;
                }
                if(i == rows-1){
                    for (int k = rows-1; k >= 2; k--)
                        m[rows-k][j] = k-1;
                }
            }
            if (m[i][j] == 1){
                if (i == 0)
                    m[i+1][j] = maxV;
                if (i == rows-1)
                    m[i-1][j] = maxV;
            }
        }

        if ((i >= 1) && (i <= rows - 2)){
            if (m[i][j] == maxV){
                if (j == 0){
                    for (int k = 2; k <= cols-1; k++)
                        m[i][cols-k] = cols-k;
                }
                if (j == cols-1){
                    for (int k = cols-1; k >= 2; k--)
                        m[i][cols-k] = k-1;
                }
            }
            if (m[i][j] == 1){
                if (j == 0)
                    m[i][j+1] = maxV;
                if (j == cols-1)
                    m[i][j-1] = maxV;
            }
        }
    }
}




