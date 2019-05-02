#ifndef __AS4_WIDGETS_MAINWINDOW_H
#define __AS4_WIDGETS_MAINWINDOW_H

#include <QWidget>

namespace as4::widgets
{
    /**
     * A root widget for this application
     * 
     * Note)
     * All the other widgets are spawned and manages inside this class
     */
    class MainWindowWidget : public QWidget
    {
        public:
        MainWindowWidget();
    };
}

#endif
