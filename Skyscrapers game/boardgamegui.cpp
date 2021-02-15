#include "boardgamegui.h"

#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QVariant>

BoardGameGui::BoardGameGui(BoardGame *g)
{
    game = g;

    QGridLayout* gl = new QGridLayout;

    setLayout(gl);

    for (int i = 0; i < game->getRows(); i++){
        for (int j = 0; j < game->getCols(); j++){
            QPushButton* pb = new QPushButton;

            pb->setFixedSize(50,50);
            gl->addWidget(pb,i,j);

            connect(pb, &QPushButton::clicked, [=]{
                game->playAt(i,j);
                updateButtons();
            });
        }
    }

    updateButtons();

    layout()->setMargin(0);
    layout()->setSpacing(0);
}

void BoardGameGui::updateButtons()
{
    for (int i = 0; i < game->getRows(); i++){
        for (int j = 0; j < game->getCols(); j++){
            auto v = game->getVal(i,j).c_str();
            int k = i * game->getCols() + j;
            auto w = layout()->itemAt(k)->widget();
            w->setProperty("text",v);
        }
    }

    if(game->finished()){
        auto msg = game->message().c_str();
        QMessageBox::information(this,tr("Game finished!"), tr(msg));
        window()->close();
    }
}


