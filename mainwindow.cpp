#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "choosewindow.h"
#include "signalwindow.h"

#include "group.h"

#include <QFile>
#include <QTimer>
#include <QDebug>

void MainWindow::read_timers()
{
    QFile fileTimers("timers.dat");
    fileTimers.open(QIODevice::ReadOnly);

    QDataStream inTimers(&fileTimers);
    timers.clear();
    while(1)
    {
        Timer currentTimer;
            QString timerName;
            int timerHoursInterval;
            int timerMinutesInterval;
            int timerSecondsInterval;
            QDateTime timerTime;
            QString timerSignal;
            bool isTimerActivated;

        inTimers >> timerName;
        if(!timerName.isEmpty())
        {
            inTimers >> timerHoursInterval;
            inTimers >> timerMinutesInterval;
            inTimers >> timerSecondsInterval;
            inTimers >> timerTime;
            inTimers >> timerSignal;
            inTimers >> isTimerActivated;

            currentTimer.set_timer_name(timerName);
            currentTimer.set_timer_hours_Interval(timerHoursInterval);
            currentTimer.set_timer_minutes_Interval(timerMinutesInterval);
            currentTimer.set_timer_seconds_Interval(timerSecondsInterval);
            currentTimer.set_timer_time(timerTime);
            currentTimer.set_timer_signal(timerSignal);
            currentTimer.set_is_activated(isTimerActivated);

            timers.push_back(currentTimer);
        }
        else
            break;
    }
    fileTimers.close();
}

void MainWindow::read_clocks()
{
    QFile fileClocks("clocks.dat");

    fileClocks.open(QIODevice::ReadOnly);

    QDataStream inClocks(&fileClocks);
    clocks.clear();
    while(1)
    {
        Clock currentClock;
            QString clockName;
            QTime clockTime;
            bool weekDays[7];
            QString clockSignal;
            bool isClockActivated;

        inClocks >> clockName;
        if(!clockName.isEmpty())
        {
            inClocks >> clockTime;
            for(int i = 0; i < 7; i++)
                inClocks >> weekDays[i];
            inClocks >> clockSignal;
            inClocks >> isClockActivated;

            currentClock.set_clock_name(clockName);
            currentClock.set_clock_time(clockTime);
            currentClock.set_week_days(weekDays);
            currentClock.set_signal(clockSignal);
            currentClock.set_is_activated(isClockActivated);

            clocks.push_back(currentClock);
        }
        else
            break;
    }
    fileClocks.close();
}

void MainWindow::write_timers()
{
    QFile fileTimers("timers.dat");
    fileTimers.resize(0);
    fileTimers.open(QIODevice::Append);
    QDataStream outTimers(&fileTimers);
    for (int i = 0; i < timers.count(); i++)
    {
        outTimers << timers[i].get_timer_name();
        outTimers << timers[i].get_timer_hours_Interval();
        outTimers << timers[i].get_timer_minutes_Interval();
        outTimers << timers[i].get_timer_seconds_Interval();
        outTimers << timers[i].get_timer_time();
        outTimers << timers[i].get_timer_signal();
        outTimers << timers[i].is_activated();
    }
    fileTimers.close();
}

void MainWindow::write_clocks()
{
    QFile fileClocks("clocks.dat");
    fileClocks.resize(0);
    fileClocks.open(QIODevice::Append);
    QDataStream outClocks(&fileClocks);
    for (int i = 0; i < clocks.count(); i++)
    {
        outClocks << clocks[i].get_clock_name();
        outClocks << clocks[i].get_clock_time();
        for (int j = 0; j < 7; j++)
        {
            outClocks << clocks[i].get_week_days()[j];
        }
        outClocks << clocks[i].get_signal();
        outClocks << clocks[i].is_activated();
    }
    fileClocks.close();
}

void MainWindow::update_timers()
{
    int c = ui->TimerListWidget->count();
    for (int i = 0; i < timers.count(); i++)
    {
        ui->TimerListWidget->addItem("Timer : " +
                                     timers[i+c].get_timer_name() +
                                     " [ " +
                                     QString::number(timers[i+c].get_timer_hours_Interval()) + "h " +
                                     QString::number(timers[i+c].get_timer_minutes_Interval()) + "m " +
                                     QString::number(timers[i+c].get_timer_seconds_Interval()) + "s" +
                                     " ]");
        ui->TimerListWidget->setCurrentRow(i+c);
        if(timers[i+c].is_activated())
            ui->TimerListWidget->currentItem()->setBackgroundColor(Qt::green);
        else
            ui->TimerListWidget->currentItem()->setBackgroundColor(Qt::red);
    }
}

void MainWindow::update_clocks()
{
    int c = ui->TimerListWidget->count();
    for(int i = 0; i < clocks.count(); i++)
    {
        ui->TimerListWidget->addItem("Clock : " +
                                     clocks[i].get_clock_name() +
                                     " [ " +
                                     clocks[i].get_clock_time().toString() +
                                     " ]" +
                                     " [ " +
                                     (clocks[i].get_week_days()[0]?"(Mon)":"") +
                                     (clocks[i].get_week_days()[1]?"(Tue)":"") +
                                     (clocks[i].get_week_days()[2]?"(Wed)":"") +
                                     (clocks[i].get_week_days()[3]?"(Thu)":"") +
                                     (clocks[i].get_week_days()[4]?"(Fri)":"") +
                                     (clocks[i].get_week_days()[5]?"(Sat)":"") +
                                     (clocks[i].get_week_days()[6]?"(Sun)":"") +
                                     " ]");
        ui->TimerListWidget->setCurrentRow(i+c);
        if(clocks[i].is_activated())
            ui->TimerListWidget->currentItem()->setBackgroundColor(Qt::green);
        else
            ui->TimerListWidget->currentItem()->setBackgroundColor(Qt::red);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TimerListWidget->clear();
    read_timers();
    read_clocks();
    update_timers();
    update_clocks();

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(check_activations_of_timers()));
    connect(timer, SIGNAL(timeout()), this, SLOT(check_activations_of_clocks()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddTimerButton_clicked()
{
    choosewindow *cw =  new choosewindow;
    cw->setWindowTitle("Type choosing");
    cw->show();
    this->close();
}

void MainWindow::play_timer(Timer t)
{
    signalwindow *sw = new signalwindow;
    sw->setWindowTitle("Timer timeout");
    sw->set_timer(t);
    sw->setFixedSize(sw->size());
    sw->play();
    sw->show();
}

void MainWindow::play_clock(Clock c)
{
    signalwindow *sw = new signalwindow;
    sw->setWindowTitle("Clock alarm");
    sw->set_clock(c);
    sw->setFixedSize(sw->size());
    sw->play();
    sw->show();
}

void MainWindow::check_activations_of_timers()
{
    bool flag = false;
    for (int i = 0; i < timers.count(); i++)
    {
        if (timers[i].is_activated() && (QDateTime::currentDateTime().msecsTo(timers[i].get_timer_time())) <= 1000)
        {
            flag = true;
            timers[i].set_is_activated(false);
            play_timer(timers[i]);
        }
    }
    if (flag)
    {
       write_timers();
       ui->TimerListWidget->clear();
       update_timers();
       update_clocks();
    }
}

void MainWindow::check_activations_of_clocks()
{
    bool flag = false;
    for(int i = 0; i < clocks.count(); i++)
    {
        if (clocks[i].is_activated())
            if (clocks[i].get_clock_time().secsTo(QTime::currentTime()) <= 5)
            {
                if(clocks[i].get_week_days()[QDate::currentDate().dayOfWeek()-1])
                {
                    flag = true;
                    play_clock(clocks[i]);
                }
            }
    }
    if (flag)
    {
        write_clocks();
        ui->TimerListWidget->clear();
        update_timers();
        update_clocks();
    }
}


void MainWindow::on_RemoveTimerButton_clicked()
{
    int i = ui->TimerListWidget->currentRow();
    qDebug() << i;
    if ((i >= 0) && (i < timers.count()))
    {
        timers.remove(i);
        write_timers();
    }
    else if ((i - timers.count() >= 0) && (i - timers.count() < clocks.count()))
    {
        clocks.remove(i - timers.count());
        write_clocks();
    }
    ui->TimerListWidget->clear();
    update_timers();
    update_clocks();
}


void MainWindow::on_pushButton_clicked()
{
    int i = ui->TimerListWidget->currentRow();
    qDebug() << i;
    if ((i >= 0) && (i < timers.count()))
    {
        if (timers[i].is_activated())
            timers[i].set_is_activated(false);
        else
            timers[i].set_is_activated(true);
        write_timers();
    }
    else if ((i - timers.count() >= 0) && (i - timers.count() < clocks.count()))
    {
        if (clocks[i - timers.count()].is_activated())
            clocks[i - timers.count()].set_is_activated(false);
        else
            clocks[i - timers.count()].set_is_activated(true);
        write_clocks();
    }
    ui->TimerListWidget->clear();
    update_timers();
    update_clocks();
}

