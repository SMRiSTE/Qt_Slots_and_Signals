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
    StopWatch();
    ~StopWatch();

    void start(QLabel *timeLabel);
    void stop();
    bool timer_check();
    void reInst();
    void circle(QTextEdit *textEdit);

    int num = 1;
    double time;
    double circle_time;

public slots:
    void update();

private:
    QTimer timer;
    QLabel *timeLabel;
    QTextEdit *textEdit;
};
#endif // STOPWATCH_HEAD_H
