#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QLatin1Char>
#include <QObject>
#include "StopWatch_head.h"

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

    void on_Button_Circle_clicked();

    void on_Button_Clear_clicked();

private:
    Ui::MainWindow *ui;
    StopWatch *sw;
};

#endif // MAINWINDOW_H
