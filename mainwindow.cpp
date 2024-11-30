#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Button_stop_start->setText(QString("Cтарт"));
    ui->Button_stop_start->setCheckable(true);

    ui->Button_Clear->setText(QString("Очистить"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

StopWatch::StopWatch() {
    QObject::connect(&timer, &QTimer::timeout, this, &StopWatch::update);
}
void StopWatch::start(QLabel *timeLabel) {
    this->timeLabel = timeLabel;
    QTime el_time;
    el_time = QTime::currentTime();
    this->el_time = el_time;
    timer.start(10);
}
void StopWatch::update(){
    int elapsed = el_time.msecsTo(QTime::currentTime());
    int seconds = elapsed / 1000;
    int milliseconds = elapsed % 1000;
    timeLabel->setText(QString("%1.%2").arg(seconds).arg(milliseconds));
}
void StopWatch::stop(){
    timer.stop();
}

void MainWindow::on_Button_stop_start_toggled(bool checked)
{
    StopWatch sw;
    if(checked == true){
        ui->Button_stop_start->setText(QString("Cтоп"));
        sw.start(ui->Time_label);
    }
    else{
        ui->Button_stop_start->setText(QString("Cтарт"));
        sw.stop();
    }
}

