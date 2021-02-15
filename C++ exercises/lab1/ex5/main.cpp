#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(nullptr));
    int r = 10;

    QApplication a(argc, argv);

    QPixmap screen{800,800};
    QPainter painter{&screen};

    painter.setBrush(QColor(rand() % 255,rand() % 255,rand() % 255));
    painter.drawEllipse(QPoint(300,300),200,200);


    while (200 - r> 10){
        r = rand() % 200;
        painter.setBrush(QColor(rand() % 255,rand() % 255,rand() % 255));
        painter.drawEllipse(QPoint(300,300),200-r,200-r);
    }

    QLabel label;
    label.setPixmap(screen);
    label.show();

    
    return a.exec();
}
