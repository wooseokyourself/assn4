#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    MelodyRoll = new ClickableLabel(ui->tab);
    DrumRoll = new ClickableLabel(ui->tab_2);
    connect(MelodyRoll, SIGNAL(Put(QPoint, ClickableLabel*)), this, SLOT(PutNote(QPoint, ClickableLabel*)));
    connect(DrumRoll, SIGNAL(Put(QPoint, ClickableLabel*)), this, SLOT(PutNote(QPoint, ClickableLabel*)));
    connect(MelodyRoll, SIGNAL(Remove(QPoint, ClickableLabel*)), this, SLOT(RemoveNote(QPoint, ClickableLabel*)));
    connect(DrumRoll, SIGNAL(Remove(QPoint, ClickableLabel*)), this, SLOT(RemoveNote(QPoint, ClickableLabel*)));
}

mainwindow::~mainwindow()
{
    delete ui;
    delete MelodyRoll;
    delete DrumRoll;
}

void mainwindow::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
}

void mainwindow::mouseMoveEvent(QMouseEvent* event)
{
    QWidget::mouseMoveEvent(event);
}


// slots

void mainwindow::PutNote(QPoint pos, ClickableLabel* tab)
{
    cout<<" >> 슬롯 실행 : PutNote"<<endl;
    int x = pos.x()/24;
    x *= 24;
    x += 3;
    int y = pos.y()/24;
    y *= 24;
    y += 4;
    cout<<" >> ("<<x<<","<<y<<")"<<endl;
    VisualNote *note = new VisualNote(tab);
    notes.push_back(note);
    notes.back()->set(pos);
}

void mainwindow::RemoveNote(QPoint pos, ClickableLabel* tab)
{
    cout<<" >> 슬롯 실행 : RemoveNote"<<endl;
    int x = pos.x()/24;
    x *= 24;
    x += 3;
    int y = pos.y()/24;
    y *= 24;
    y += 4;
    cout<<" >> ("<<x<<","<<y<<")"<<endl;
    for(int i=0; i<notes.size(); i++){
        if(notes[i]->find(x, y)){
            delete notes[i];
            notes.erase(notes.begin()+i);
        }
    }
}
