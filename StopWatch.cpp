#include "StopWatch_head.h"

StopWatch::StopWatch(){
    QObject::connect(&timer, &QTimer::timeout, this, &StopWatch::update);
}

void StopWatch::start(QLabel *timeLabel){
    this->timeLabel = timeLabel;
    if(!this->bo_el_time && !this->bo_st_time){
        el_time = QTime::currentTime();
        for_circle = el_time;
        bo_el_time = true;
        this->el_time = el_time;
    }
    if(bo_st_time){
        el_time = el_time.addMSecs(st_time.msecsTo(QTime::currentTime()));
        for_circle = for_circle.addMSecs(st_time.msecsTo(QTime::currentTime()));
    }
    timer.start(100);
}

void StopWatch::stop(){
    timer.stop();
    st_time = QTime::currentTime();
    bo_st_time = true;
}

void StopWatch::update(){
    int elapsed = el_time.msecsTo(QTime::currentTime());
    int seconds = elapsed / 1000;
    int milliseconds = elapsed % 100;
    timeLabel->setText(QString("%1.%2").arg(seconds).arg(milliseconds));
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
        qDebug() << "У вас уже запущен таймер, остановите его, а потом очистите";
    }
    else{
        bo_el_time = false;
        bo_st_time = false;
        this->num = 1;
    }
}

void StopWatch::circle(QTextEdit *textEdit){
    this->textEdit = textEdit;
    int elapsed = for_circle.msecsTo(QTime::currentTime());
    int seconds = elapsed / 1000;
    int milliseconds = elapsed % 100;
    textEdit->append(QString("%1) %2.%3").arg(this->num).arg(seconds).arg(milliseconds));
    this->num++;
    for_circle = QTime::currentTime();
}
