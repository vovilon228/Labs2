#ifndef SIGNALWINDOW_H
#define SIGNALWINDOW_H

#include <QDialog>
#include "group.h"
#include "qsound.h"

namespace Ui {
class signalwindow;
}

class signalwindow : public QDialog
{
    Q_OBJECT

public:
    explicit signalwindow(QWidget *parent = nullptr);
    ~signalwindow();
    void set_timer(Timer t);
    void set_clock(Clock c);
    void play();
private slots:
    void on_OkButton_clicked();

private:
    Ui::signalwindow *ui;
    QSound *signal;
};

#endif // SIGNALWINDOW_H
