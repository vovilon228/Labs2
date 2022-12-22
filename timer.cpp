#include "timer.h"

Timer::Timer()
{
    timerName = "";
    timerHoursInterval = 0;
    timerMinutesInterval = 0;
    timerSecondsInterval = 0;
    timerTime = QDateTime::currentDateTime();
    timerSignal = "";
    isActivated = true;
}

QString Timer::get_timer_name()
{
    return timerName;
}

int Timer::get_timer_hours_Interval()
{
    return timerHoursInterval;
}

int Timer::get_timer_minutes_Interval()
{
    return timerMinutesInterval;
}

int Timer::get_timer_seconds_Interval()
{
    return timerSecondsInterval;
}

QDateTime Timer::get_timer_time()
{
    return timerTime;
}

QString Timer::get_timer_signal()
{
    return timerSignal;
}

bool Timer::is_activated()
{
    return isActivated;
}

void Timer::set_timer_name(const QString &newTimerName)
{
    timerName = newTimerName;
}

void Timer::set_timer_hours_Interval(const int &newTimerHoursInterval)
{
    timerTime = timerTime.addSecs(3600*(newTimerHoursInterval-timerHoursInterval));
    timerHoursInterval = newTimerHoursInterval;
}

void Timer::set_timer_minutes_Interval(const int &newTimerMinutesInterval)
{
    timerTime = timerTime.addSecs(60*(newTimerMinutesInterval-timerMinutesInterval));
    timerMinutesInterval = newTimerMinutesInterval;
}

void Timer::set_timer_seconds_Interval(const int &newTimerSecondsInterval)
{
    timerTime = timerTime.addSecs(newTimerSecondsInterval-timerSecondsInterval);
    timerSecondsInterval = newTimerSecondsInterval;
}

void Timer::set_timer_time(const QDateTime &newTimerTime)
{
    timerTime = newTimerTime;
}

void Timer::set_timer_signal(const QString &newTimerSignal)
{
    timerSignal = newTimerSignal;
}

void Timer::set_is_activated(const bool &newIsActivated)
{
    isActivated = newIsActivated;
    if (isActivated)
    {
        timerTime = QDateTime::currentDateTime();
        timerTime = timerTime.addSecs(3600*timerHoursInterval + 60*timerMinutesInterval +timerSecondsInterval);
    }
}
