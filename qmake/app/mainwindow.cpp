#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    MelodyRoll = new ClickableLabel(ui->tab);
    DrumRoll = new ClickableLabel(ui->tab_2);
    FullSong = new Song;
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
    int y = pos.y()/24;

    // 이하 Visual용 push
    VisualNote *note = new VisualNote(tab);
    melody_notes.push_back(note);
    melody_notes.back()->set(pos);
    cout<<" >> melody size : "<<melody_notes.size()<<endl;

    // 이하 ISeq용 push
    as4::model::Timestamp start = 0.5+(0.5*x);
    Pitch topPitch(3, 5);
    for(int i=0; i!=y; i++){
        topPitch.operator++();
        // 이제 이 topPitch를 sequence에 집어넣기
    }
    cout<<" >> new start : "<<start<<endl;
    cout<<" >> new pitch : "<<topPitch.GetPitchClass()<<endl;
    cout<<" >> new octave : "<<topPitch.GetOctave()<<endl;
    FullSong->GetMelodySeq()->Put({start, 2, {topPitch.GetPitchClass(), topPitch.GetOctave()}});
}

void mainwindow::PutDrumNote(QPoint pos, ClickableLabel* tab)
{
    cout<<" >> 슬롯 실행 : PutNote"<<endl;
    int x = pos.x()/24;
    int y = pos.y()/24;

    // 이하 Visual용 push
    VisualNote *note = new VisualNote(tab);
    drum_notes.push_back(note);
    drum_notes.back()->set(pos);
    cout<<" >> drum size : "<<drum_notes.size()<<endl;

    // 이하 ISeq용 push
    as4::model::Timestamp start = 0.5+(0.5*x);
    Pitch topPitch(3, 5);
    for(int i=0; i!=y; i++){
        topPitch.operator++();
        // 이제 이 topPitch를 sequence에 집어넣기
    }
    cout<<" >> new start : "<<start<<endl;
    cout<<" >> new pitch : "<<topPitch.GetPitchClass()<<endl;
    cout<<" >> new octave : "<<topPitch.GetOctave()<<endl;
    FullSong->GetDrumSeq()->Put({start, 2, {topPitch.GetPitchClass(), topPitch.GetOctave()}});
}

void mainwindow::RemoveMelodyNote(QPoint pos, ClickableLabel* tab)
{
    cout<<" >> 슬롯 실행 : RemoveNote"<<endl;
    int x = pos.x()/24;
    int _x = x;
    x *= 24;
    x += 3;
    int y = pos.y()/24;
    int _y = y;
    y *= 24;
    y += 4;
    // 이하 Visual용 pop
    for(int i=0; i<melody_notes.size(); i++){
        if(melody_notes[i]->find(x, y)){
            melody_notes[i]->hide();
            melody_notes.remove(i);
            cout<<" >> melody size : "<<melody_notes.size()<<endl;
            break;
        }
    }

    // 이하 ISeq용 pop
    as4::model::Timestamp start = 0.5+(0.5*_x);
    cout<<" >> start : "<<start<<endl;
    Pitch topPitch(3, 5);
    for(int i=0; i!=_y; i++){
        topPitch.operator++();
    }
    as4::model::Note target(start, 2, topPitch);
    // 이제 target을 이용해 ISeq에서 일치하는 요소 제거

    cout<<" >> target start : "<<target.GetStart()<<endl;
    cout<<" >> target pitch : "<<target.GetPitch().GetPitchClass()<<endl;
    cout<<" >> target octave : "<<target.GetPitch().GetOctave()<<endl;

    Note* detectedTarget = FullSong->GetMelodySeq()->FindNote(target);
    if(FullSong->GetMelodySeq()->Remove(detectedTarget)){
        cout<<" >> ISeq target 제거완료"<<endl;
    }
    else{
        cout<<" >> ISeq target 제거실패"<<endl;
    }
}

void mainwindow::RemoveDrumNote(QPoint pos, ClickableLabel* tab)
{
    cout<<" >> 슬롯 실행 : RemoveNote"<<endl;
    int x = pos.x()/24;
    int _x = x;
    x *= 24;
    x += 3;
    int y = pos.y()/24;
    int _y = y;
    y *= 24;
    y += 4;
    // 이하 Visual용 pop
    for(int i=0; i<drum_notes.size(); i++){
        if(drum_notes[i]->find(x, y)){
            drum_notes[i]->hide();
            drum_notes.remove(i);
            cout<<" >> drum size : "<<drum_notes.size()<<endl;
            break;
        }
    }

    // 이하 ISeq용 pop
    as4::model::Timestamp start = 0.5+(0.5*_x);
    cout<<" >> start : "<<start<<endl;
    Pitch topPitch(3, 5);
    for(int i=0; i!=_y; i++){
        topPitch.operator++();
    }
    as4::model::Note target(start, 2, topPitch);
    // 이제 target을 이용해 ISeq에서 일치하는 요소 제거

    cout<<" >> target start : "<<target.GetStart()<<endl;
    cout<<" >> target pitch : "<<target.GetPitch().GetPitchClass()<<endl;
    cout<<" >> target octave : "<<target.GetPitch().GetOctave()<<endl;

    Note* detectedTarget = FullSong->GetDrumSeq()->FindNote(target);
    if(FullSong->GetDrumSeq()->Remove(detectedTarget)){
        cout<<" >> ISeq target 제거완료"<<endl;
    }
    else{
        cout<<" >> ISeq target 제거실패"<<endl;
    }
}


void mainwindow::on_PlayButton_clicked()
{
    Player.SetAndPlay(FullSong, ui->tabWidget);

}

void mainwindow::on_pushButton_clicked()
{
    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(":/audio/melody/audio/melody/3_4.wav"));
    effect.setLoopCount(QSoundEffect::Infinite);
    effect.setVolume(0.25f);
    effect.play();
    QThread::msleep(5000);
    Player.test();

}
