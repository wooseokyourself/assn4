#ifndef __AS4_WIDGETS_MAINWINDOW_H
#define __AS4_WIDGETS_MAINWINDOW_H
#include <iostream>
#include <QMainWindow>

/*
#include <QWidget>

namespace as4::widgets
{
   *
     * A root widget for this application
     * 
     * Note)
     * All the other widgets are spawned and manages inside this class

    class MainWindowWidget : public QWidget
    {
        public:
        MainWindowWidget();
    };
}
*/
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_pressed();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif
