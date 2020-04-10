#include "powershell_history_parser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    powershell_history_parser w;
    w.show();
    return a.exec();
}
