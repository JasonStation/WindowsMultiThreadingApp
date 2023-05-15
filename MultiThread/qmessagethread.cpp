#include "qmessagethread.h"
#include <QtDebug>

QMessageThread::QMessageThread(QObject *parent) :
    QThread{parent}
{
    runningProcess = false;
}

void QMessageThread::run(){
    qDebug() << "Start Thread " << message;
    while (runningProcess){
        qDebug() << message << " is running. Counter: " << mCounter;
        QThread::msleep(mDelay);
        mCounter += mSteps;
        if(mCounter > mEnd) break;
    }

    qDebug() << "Ended thread " << message;
}
