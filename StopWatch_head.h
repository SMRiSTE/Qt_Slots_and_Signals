#ifndef STOPWATCH_HEAD_H
#define STOPWATCH_HEAD_H

#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QTextEdit>
#include <QLatin1Char>
#include <QObject>

class StopWatch : public QObject{
    Q_OBJECT

public:
    int num = 1;

    StopWatch();
    void start(QLabel *timeLabel);

    ~StopWatch(){
        delete timeLabel;
    }
    void stop();
    bool timer_check();
    void reInst();
    void circle(QTextEdit *textEdit);

public slots:
    void update();

private:
    bool bo_st_time = false;
    bool bo_el_time = false;
    QTime st_time;
    QTime el_time;
    QTime for_circle;
    QTimer timer;
    QLabel *timeLabel;
    QTextEdit *textEdit;
};
#endif // STOPWATCH_HEAD_H
