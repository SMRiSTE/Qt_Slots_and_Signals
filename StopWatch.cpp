#include "StopWatch_head.h"

StopWatch::StopWatch(){
    QObject::connect(&timer, &QTimer::timeout, this, &StopWatch::update);
}

void StopWatch::start(QLabel *timeLabel){
    this->timeLabel = timeLabel;
    timer.start(100);
}

void StopWatch::stop(){
    timer.stop();
}

void StopWatch::update(){
    this->time+=0.10;
    this->circle_time+=0.10;
    timeLabel->setText(QString("%1").arg(time));
}

bool StopWatch::timer_check(){
    if(timer.isActive()){
        return true;
    }
    else{
        return false;
    }
}

void StopWatch::reInst(){
    if(timer_check()){
        timer.stop();
        time = 0;
        circle_time = 0;
        this->num = 1;
    }
    else{
        time = 0;
        circle_time = 0;
        this->num = 1;
    }
}

void StopWatch::circle(QTextEdit *textEdit){
    this->textEdit = textEdit;

    textEdit->append(QString("%1) %2").arg(this->num).arg(circle_time));
    this->num++;
    circle_time = 0.0;
}

StopWatch::~StopWatch(){
    delete timeLabel;
    delete textEdit;
}
