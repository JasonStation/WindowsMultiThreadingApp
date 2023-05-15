#ifndef QMESSAGETHREAD_H
#define QMESSAGETHREAD_H

#include <QThread>

class QMessageThread : public QThread
{
public:
    explicit QMessageThread(QObject *parent = nullptr);


    void startThread(){
        runningProcess = true;
        start();
    }

    void stopThread(){
        runningProcess = false;
    }

    void messageSet(const QString& str){
        message = str;
    }

    void setValue(int start, int end, int steps, int delay, int counter){
        mStart = start;
        mEnd = end;
        mSteps = steps;
        mDelay = delay;
        mCounter = counter;
    }

protected:
    void run();

public:
       QString message;
       bool runningProcess;
       int mStart, mEnd, mSteps, mDelay, mCounter;
};

#endif // QMESSAGETHREAD_H
