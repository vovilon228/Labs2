#ifndef TIMER_H
#define TIMER_H

#include <QString>
#include <QTime>

class Timer
{
private:
    QString timerName;
    int timerHoursInterval;
    int timerMinutesInterval;
    int timerSecondsInterval;
    QDateTime timerTime;
    QString timerSignal;
    bool isActivated;
public:
    Timer();

    QString get_timer_name();
    int get_timer_hours_Interval();
    int get_timer_minutes_Interval();
    int get_timer_seconds_Interval();
    QDateTime get_timer_time();
    QString get_timer_signal();
    bool is_activated();

    void set_timer_name(const QString &newTimerName);
    void set_timer_hours_Interval(const int &newTimerHoursInterval);
    void set_timer_minutes_Interval(const int &newTimerMinutesInterval);
    void set_timer_seconds_Interval(const int &newTimerSecondsInterval);
    void set_timer_time(const QDateTime &newTimerTime);
    void set_timer_signal(const QString &newTimerSignal);
    void set_is_activated(const bool &newIsActivated);
};

#endif // TIMER_H
