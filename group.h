#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QVector>
#include "clock.h"
#include "timer.h"


class Group
{
private:
    QString groupName;
    QVector<Clock> clocks;
    QVector<Timer> timers;
    bool isActivated;
public:
    Group();

    QString get_group_name();
    QVector<Clock> get_clocks();
    QVector<Timer> get_timers();
    bool is_activated();

    void set_group_name(const QString &newGroupName);
    void set_clocks(const QVector<Clock> &newClocks);
    void set_timers(const QVector<Timer> &newTimers);
    void set_is_activated(const bool &newIsActivated);
};

#endif // GROUP_H
