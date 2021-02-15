#ifndef SKYSCRAPER_H
#define SKYSCRAPER_H

#include <vector>
#include "boardgame.h"
#include <string>
#include <QFileDialog>

using namespace std;

class Skyscraper : public BoardGame
{
public:
    Skyscraper(string fn);
    string getVal(int i, int j);
    void playAt(int i, int j);
    int maxChanges(vector<int> cells);
    int maxChangesReversed(vector<int> cells);
    void readGameArena();
    bool finished();
    string message() {return "Solved!";}
    int getRows(){return rows;}
    int getCols(){return cols;}
    void save(string fn);
    void fillCell(int i, int j);

private:
    int rows,cols;
    int maxV;
    string filename;
    vector<vector<int>> m;
};

#endif // SKYSCRAPER_H
