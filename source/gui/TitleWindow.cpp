// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "TitleWindow.h"
#include "GameSelectionDialog.h"
#include "NameEntryDialog.h"
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
using namespace std;

TitleWindow::TitleWindow()
{
    QImage programIconImage(":/images/program_icon.png");
    setWindowIcon(QIcon(QPixmap::fromImage(programIconImage)));
    setWindowTitle("Welcome");

    QLabel* titleLabel = new QLabel("<center><h2>Welcome to <font color = purple>Chess++</font></h2></center>");
    QLabel* createdByLabel = new QLabel("Created by: Aaron Oeder, Jacob Owens, and Trevor Berceau");
    QLabel* imageLabel = new QLabel;
    imageLabel->setPixmap(QPixmap::fromImage(programIconImage));
    imageLabel->setAlignment(Qt::AlignCenter);

    QPushButton* newGameButton = new QPushButton("Start a new chess game");
    QObject::connect(newGameButton, SIGNAL(clicked()), this, SLOT(newGameButtonHandler()));
    QPushButton* resumeGameButton = new QPushButton("Resume a previous chess game");
    QObject::connect(resumeGameButton, SIGNAL(clicked()), this, SLOT(resumeGameButtonHandler()));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(createdByLabel);
    layout->addWidget(imageLabel);
    layout->addWidget(newGameButton);
    layout->addWidget(resumeGameButton);
    setLayout(layout);
}

void TitleWindow::newGameButtonHandler()
{
    close();
    NameEntryDialog* nameEntryDialog = new NameEntryDialog(this);
    nameEntryDialog->exec();
}

void TitleWindow::resumeGameButtonHandler()
{
    close();
    GameSelectionDialog* gameSelectionDialog = new GameSelectionDialog;
    gameSelectionDialog->exec();
}
