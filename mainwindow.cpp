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

MainWindow::~MainWindow()
{
    delete ui;
    delete sw;
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
    sw->circle(ui->textEdit);
}


void MainWindow::on_Button_Clear_clicked()
{
    sw->reInst();
    ui->Time_label->setText(QString("Время"));
    ui->textEdit->clear();
    if(ui->Button_stop_start->isChecked()){
        ui->Button_stop_start->setChecked(false);
    }
}

