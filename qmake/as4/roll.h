#ifndef ROLL_H
#define ROLL_H

#include <QWidget>

namespace Ui {
class Roll;
}

class Roll : public QWidget
{
    Q_OBJECT

public:
    explicit Roll(QWidget *parent = nullptr);
    ~Roll();

private:
    Ui::Roll *ui;
};

#endif // ROLL_H
