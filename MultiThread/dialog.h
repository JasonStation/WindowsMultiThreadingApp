#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qmessagethread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:

    void pushButtonA();
    void pushButtonB();
    void pushButtonC();
    void resetA();
    void resetB();
    void resetC();

private:
    Ui::Dialog *ui;
    bool threadARunning;
    bool threadBRunning;
    bool threadCRunning;
    QMessageThread threadA, threadB, threadC;

};

#endif // MULTITHREAD_H
