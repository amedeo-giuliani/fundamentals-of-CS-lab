#ifndef BOARDGAMEGUI_H
#define BOARDGAMEGUI_H

#include <QWidget>

#include "boardgame.h"

class BoardGameGui : public QWidget
{
    BoardGame* game;
public:
    BoardGameGui(BoardGame* g);
    void updateButtons();
};

#endif // BOARDGAMEGUI_H
