#include "qm_pot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QM_Pot w;
    w.show();

    return a.exec();
}
