#include "hishab_nikash.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hishab_nikash w;
    w.show();

    return a.exec();
}
