#include "signalwindow.h"
#include "ui_signalwindow.h"

signalwindow::signalwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signalwindow)
{
    ui->setupUi(this);
}

signalwindow::~signalwindow()
{
    delete ui;
}

void signalwindow::set_timer(Timer t)
{
    ui->label->setText("The timer \"" + t.get_timer_name() + "\"" + "[" + t.get_timer_time().time().toString()  + "]" + " has expired");
    signal = new QSound(t.get_timer_signal());
    signal->setLoops(100);
}

void signalwindow::set_clock(Clock c)
{
    ui->label->setText("The clock \"" + c.get_clock_name() + "\"" + "[" + c.get_clock_time().toString()  + "]" + " has expired");
    signal = new QSound(c.get_signal());
    signal->setLoops(100);
}

void signalwindow::play()
{
    signal->play();
}

void signalwindow::on_OkButton_clicked()
{
    signal->stop();
    this->close();
}

