#include "MiniBankGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MiniBankGUI window;
    window.show();
    return app.exec();
}
