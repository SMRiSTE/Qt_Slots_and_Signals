#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QLatin1Char>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_stop_start_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

class StopWatch : public QObject{
    Q_OBJECT
public:
    StopWatch();
    void start(QLabel *timeLabel);
    void stop();
public slots:
    void update();
private:
    QTime el_time;
    QTimer timer;
    QLabel *timeLabel;
};

#endif // MAINWINDOW_H
