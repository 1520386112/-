#include "widget_sy_single.h"
#include "samplewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SampleWidget sw;
    sw.show();
    return a.exec();
}
