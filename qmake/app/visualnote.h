#ifndef __AS4_VISUALNOTE_H_
#define __AS4_VISUALNOTE_H_

#include <QLabel>
#include <QWidget>
#include <Qt>

class VisualNote : public QLabel
{
    Q_OBJECT

public:
    explicit VisualNote(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~VisualNote();
    int getX() const;
    int getY() const;
    void set(QPoint pos);
    bool find(int x, int y);

private:
    int x;
    int y;
};

#endif // VISUALNOTE_H
