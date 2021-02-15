#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <string>

using namespace std;

class BoardGame
{
public:
    virtual void playAt(int i, int j) = 0;
    virtual int getCols() = 0;
    virtual int getRows() = 0;
    virtual string getVal(int i, int j) =0;
    virtual bool finished() = 0;
    virtual string message() = 0;

    virtual ~BoardGame() {}
};

#endif // BOARDGAME_H
