#include "dialog.h"
#include "ui_dialog.h"
#include <QThread>
#include <QtDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPushButton *buttonA = Dialog::findChild<QPushButton *>("buttonA");
        connect(buttonA, SIGNAL(pressed()), this, SLOT(pushButtonA()));


     QPushButton *buttonB = Dialog::findChild<QPushButton *>("buttonB");
        connect(buttonB, SIGNAL(pressed()), this, SLOT(pushButtonB()));

     QPushButton *buttonC = Dialog::findChild<QPushButton *>("buttonC");
        connect(buttonC, SIGNAL(pressed()), this, SLOT(pushButtonC()));

     QPushButton *resetA = Dialog::findChild<QPushButton *>("resetA");
           connect(resetA, SIGNAL(pressed()), this, SLOT(resetA()));

     QPushButton *resetB = Dialog::findChild<QPushButton *>("resetB");
           connect(resetB, SIGNAL(pressed()), this, SLOT(resetB()));

      QPushButton *resetC = Dialog::findChild<QPushButton *>("resetC");
           connect(resetC, SIGNAL(pressed()), this, SLOT(resetC()));



    threadA.messageSet("Thread 1");
    threadB.messageSet("Thread 2");
    threadC.messageSet("Thread 3");


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog :: pushButtonA(){

    threadA.setValue(ui->spinBox->value(),
                     ui->spinBox_2->value(),
                     ui->spinBox_3->value(),
                     ui->spinBox_13->value(),
                     ui->spinBox->value());

    if(ui->buttonA->text().startsWith("Start")){
        ui->buttonA->setText("Stop");
        threadA.startThread();
    }
    else{
        ui->buttonA->setText("Start");
        threadA.stopThread();
    }
}

void Dialog :: pushButtonB(){
    threadB.setValue(ui->spinBox_18->value(),
                     ui->spinBox_19->value(),
                     ui->spinBox_20->value(),
                     ui->spinBox_21->value(),
                     ui->spinBox_18->value());
    if(ui->buttonB->text().startsWith("Start")){
        threadB.startThread();
        ui->buttonB->setText("Stop");
    }
    else{
        ui->buttonB->setText("Start");
        threadB.stopThread();
    }
}

void Dialog :: pushButtonC(){
    threadC.setValue(ui->spinBox_22->value(),
                     ui->spinBox_23->value(),
                     ui->spinBox_24->value(),
                     ui->spinBox_25->value(),
                     ui->spinBox_22->value());
    if(ui->buttonC->text().startsWith("Start")){
        threadC.startThread();
        ui->buttonC->setText("Stop");
    }
    else{
        ui->buttonC->setText("Start");
        threadC.stopThread();
    }
}

void Dialog :: resetA(){
    threadA.mCounter = ui->spinBox->value() - 1;
    qDebug("Reset thread");
}

void Dialog :: resetB(){
    threadB.mCounter = ui->spinBox_18->value() - 1;
    qDebug("Reset thread");
}

void Dialog :: resetC(){
    threadC.mCounter = ui->spinBox_22->value() - 1;
    qDebug("Reset thread");
}

