#include "mainwindow.h"
#include "boardgamegui.h"
#include "skyscraper.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow()
{
    QMenu* menu = menuBar()->addMenu(tr("Game"));
    QAction* game = menu->addAction(tr("New Game"));
    QAction* load = menu->addAction(tr("Load"));
    QAction* save = menu->addAction(tr("Save"));
    connect(game,&QAction::triggered,this,&MainWindow::newGame);
    connect(load,&QAction::triggered,this,&MainWindow::loadGame);
    connect(save,&QAction::triggered,this,&MainWindow::saveGame);

    setWindowTitle("Skyscrapers");

    newGame();
}

void MainWindow::newGame()
{
    if (g != nullptr)
        delete g;

    if(centralWidget() != nullptr)
        delete centralWidget();

    string filename = QFileDialog::getOpenFileName().toStdString();

    g = new Skyscraper{filename};

    setCentralWidget(new BoardGameGui{g});

    adjustSize();
    setFixedSize(sizeHint());
}

void MainWindow::loadGame()
{
    if (g != nullptr)
        delete g;

    if(centralWidget() != nullptr)
        delete centralWidget();

    string filename = QFileDialog::getOpenFileName().toStdString();

    g = new Skyscraper{filename};

    setCentralWidget(new BoardGameGui{g});

    adjustSize();
    setFixedSize(sizeHint());
}

void MainWindow::saveGame()
{
    string filename = QFileDialog::getSaveFileName().toStdString();

    g->save(filename);
}


