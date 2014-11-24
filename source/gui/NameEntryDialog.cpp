// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "NameEntryDialog.h"
#include "GameWindow.h"
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
using namespace std;

NameEntryDialog::NameEntryDialog(QWidget* parent) : QDialog(parent)
{
    QImage windowIconImage(":/images/program_icon.png");
    setWindowIcon(QIcon(QPixmap::fromImage(windowIconImage)));
    setWindowTitle("Players");

    QVBoxLayout* layout = new QVBoxLayout;

    QLabel* instructionsLabel = new QLabel("<i>Enter the name of the user playing the <b>WHITE</b> pieces and the name of the user playing the <b>BLACK</b> pieces.</i>");
    instructionsLabel->setWordWrap(true);

    QHBoxLayout* playerWhiteLayout = new QHBoxLayout;
    QLabel* whitePlayerLabel = new QLabel;
    QImage whitePawnImage(":/images/WHITE_PAWN.png");
    whitePlayerLabel->setPixmap(QPixmap::fromImage(whitePawnImage));
    playerWhiteLayout->addWidget(whitePlayerLabel);
    whitePlayerLineEdit = new QLineEdit;
    playerWhiteLayout->addWidget(whitePlayerLineEdit);

    QHBoxLayout* playerBlackLayout = new QHBoxLayout;
    QLabel* blackPlayerLabel = new QLabel;
    QImage blackPawnImage(":/images/BLACK_PAWN.png");
    blackPlayerLabel->setPixmap(QPixmap::fromImage(blackPawnImage));
    blackPlayerLineEdit = new QLineEdit;
    playerBlackLayout->addWidget(blackPlayerLabel);
    playerBlackLayout->addWidget(blackPlayerLineEdit);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    QPushButton* okButton = new QPushButton("OK");
    QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(okButtonHandler()));
    QPushButton* backButton = new QPushButton("Back");
    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(backButtonHandler()));
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(backButton);

    layout->addWidget(instructionsLabel);
    layout->addLayout(playerWhiteLayout);
    layout->addLayout(playerBlackLayout);
    layout->addLayout(buttonsLayout);

    setLayout(layout);
}

void NameEntryDialog::okButtonHandler()
{
    close();
    strWhitePlayerName = whitePlayerLineEdit->text().toStdString();
    strBlackPlayerName = blackPlayerLineEdit->text().toStdString();
    GameWindow* gameWindow = new GameWindow(strWhitePlayerName, strBlackPlayerName);
    gameWindow->move(500, 0);
    gameWindow->show();
}

void NameEntryDialog::backButtonHandler()
{
    close();
    parentWidget()->show();
}
