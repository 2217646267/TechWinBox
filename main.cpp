#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a3(argc, argv);
    Widget w3;
    w3.show();
    return a3.exec();
}
