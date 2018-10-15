#include "hotlinesave.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hotlineSave w;
    w.show();

    return a.exec();
}
