#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    MelodyRoll = new ClickableLabel(ui->tab);
    DrumRoll = new ClickableLabel(ui->tab_2);
    connect(MelodyRoll, SIGNAL(Put(QPoint, ClickableLabel*)), this, SLOT(PutMelodyNote(QPoint, ClickableLabel*)));
    connect(DrumRoll, SIGNAL(Put(QPoint, ClickableLabel*)), this, SLOT(PutDrumNote(QPoint, ClickableLabel*)));
    connect(MelodyRoll, SIGNAL(Remove(QPoint, ClickableLabel*)), this, SLOT(RemoveMelodyNote(QPoint, ClickableLabel*)));
    connect(DrumRoll, SIGNAL(Remove(QPoint, ClickableLabel*)), this, SLOT(RemoveDrumNote(QPoint, ClickableLabel*)));
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

void mainwindow::PutMelodyNote(QPoint pos, ClickableLabel* tab)
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
    melody_notes.push_back(note);
    melody_notes.back()->set(pos);
    cout<<" >> melody size : "<<melody_notes.size()<<endl;
}

void mainwindow::PutDrumNote(QPoint pos, ClickableLabel* tab)
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
    drum_notes.push_back(note);
    drum_notes.back()->set(pos);
    cout<<" >> drum size : "<<drum_notes.size()<<endl;
}

void mainwindow::RemoveMelodyNote(QPoint pos, ClickableLabel* tab)
{
    cout<<" >> 슬롯 실행 : RemoveNote"<<endl;
    int x = pos.x()/24;
    x *= 24;
    x += 3;
    int y = pos.y()/24;
    y *= 24;
    y += 4;
    cout<<" >> ("<<x<<","<<y<<")"<<endl;
    for(int i=0; i<melody_notes.size(); i++){
        if(melody_notes[i]->find(x, y)){
            melody_notes[i]->hide();
            melody_notes.remove(i);
            cout<<" >> melody size : "<<melody_notes.size()<<endl;
            break;
        }
    }
}

void mainwindow::RemoveDrumNote(QPoint pos, ClickableLabel* tab)
{
    cout<<" >> 슬롯 실행 : RemoveNote"<<endl;
    int x = pos.x()/24;
    x *= 24;
    x += 3;
    int y = pos.y()/24;
    y *= 24;
    y += 4;
    cout<<" >> ("<<x<<","<<y<<")"<<endl;
    for(int i=0; i<drum_notes.size(); i++){
        if(drum_notes[i]->find(x, y)){
            drum_notes[i]->hide();
            drum_notes.remove(i);
            cout<<" >> drum size : "<<drum_notes.size()<<endl;
            break;
        }
    }
}

