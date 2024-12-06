#ifndef STOPWATCH_HEAD_H
#define STOPWATCH_HEAD_H

#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QLatin1Char>
#include <QObject>

class StopWatch : public QObject{
    Q_OBJECT

public:
    int num = 1;

    StopWatch(){
        QObject::connect(&timer, &QTimer::timeout, this, &StopWatch::update);
    }
    void start(QLabel *timeLabel){
        this->timeLabel = timeLabel;
        if(this->el_time.isNull()){
            QTime el_time;
            el_time = QTime::currentTime();
            this->el_time = el_time;
        }
        if(st_time.isValid()){
            el_time = el_time.addMSecs(st_time.msecsTo(QTime::currentTime()));
        }
        timer.start(100);
    }

    ~StopWatch(){
        delete timeLabel;
    }
    void stop(){
        timer.stop();
        st_time = QTime::currentTime();
    }
    bool timer_check(){
        if(timer.isActive()){
            return true;
        }
        else{
            return false;
        }
    }

public slots:
    void update(){
        int elapsed = el_time.msecsTo(QTime::currentTime());
        int seconds = elapsed / 1000;
        int milliseconds = elapsed % 100;
        timeLabel->setText(QString("%1.%2").arg(seconds).arg(milliseconds));
    }

private:
    QTime st_time;
    QTime el_time;
    QTimer timer;
    QLabel *timeLabel;
};
#endif // STOPWATCH_HEAD_H
