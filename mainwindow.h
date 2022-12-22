#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "group.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void read_timers();
    void read_clocks();
    void write_timers();
    void write_clocks();
    void update_timers();
    void update_clocks();
    void play_timer(Timer t);
    void play_clock(Clock c);

private slots:
    void on_AddTimerButton_clicked();
    void check_activations_of_timers();
    void check_activations_of_clocks();

    void on_RemoveTimerButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QVector<Timer> timers;
    QVector<Clock> clocks;

    QTimer *timer;
};
#endif // MAINWINDOW_H
