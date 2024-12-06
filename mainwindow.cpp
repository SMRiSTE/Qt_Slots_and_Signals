#include "mainwindow.h"
#include "StopWatch_head.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    sw = new StopWatch;
    ui->setupUi(this);

    ui->Time_label->setText(QString("Время"));

    ui->Button_stop_start->setText(QString("Cтарт"));
    ui->Button_stop_start->setCheckable(true);

    ui->Button_Clear->setText(QString("Очистить"));

    ui->Button_Circle->setText(QString("Круг"));

}

void MainWindow::reInst(){
    if(sw->timer_check()){
        qDebug() << "У вас уже запущен таймер, остановите его, а потом очистите";
    }
    else{
        sw = nullptr;
        sw = new StopWatch;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_stop_start_toggled(bool checked)
{
    if(checked == true){
        ui->Button_stop_start->setText(QString("Cтоп"));
        sw->start(ui->Time_label);
    }
    else{
        ui->Button_stop_start->setText(QString("Cтарт"));
        sw->stop();
    }
}


void MainWindow::on_Button_Circle_clicked()
{
    QString str = ui->Time_label->text();
    ui->textEdit->append(QString("%1) %2").arg(sw->num).arg(str));
    sw->num++;
}


void MainWindow::on_Button_Clear_clicked()
{
    reInst();
    ui->Time_label->setText(QString("Время"));
    ui->textEdit->clear();
}

