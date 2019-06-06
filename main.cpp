#include "customsplash.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomSplash w;
    w.startSplash();
    w.show();

    return a.exec();
}
