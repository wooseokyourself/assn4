#include <QApplication>
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    /*
     * Create and show our main window. 'mainwindow' is the
     * root QWidget of all QWidgets in this applictaion
     */
    mainwindow mainwindow;
    mainwindow.show();
    /*
     * Enters main event loop and waits until exit() is called.
     * No user interaction can take place before this call.
     */
    return app.exec();
}
