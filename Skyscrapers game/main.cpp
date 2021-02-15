#include <iostream>
#include <fstream>
#include <sstream>
#include "skyscraper.h"
#include "boardgamegui.h"
#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc,argv);

    //string filename = QFileDialog::getOpenFileName().toStdString();

    //Skyscraper* s = new Skyscraper{filename};

    //BoardGameGui* gui = new BoardGameGui{s};
    //gui->show();

    MainWindow w;
    w.show();

    return a.exec();

    /*while(!S->finished()){

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                cout << m[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Row: ";
        cin >> i;
        cout << "Col: ";
        cin >> j;

        S->playAt(i,j);
    }*/

    return 0;
}
