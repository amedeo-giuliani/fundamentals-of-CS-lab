#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "boardgame.h"
#include "skyscraper.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    void newGame();
    void loadGame();
    void saveGame();
    ~MainWindow(){}
private:
    Skyscraper* g = nullptr;
};

#endif // MAINWINDOW_H
