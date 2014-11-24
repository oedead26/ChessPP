// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "TitleWindow.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TitleWindow* titleWindow = new TitleWindow;
    titleWindow->show();
    return app.exec();
}
