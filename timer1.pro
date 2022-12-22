QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choosewindow.cpp \
    clock.cpp \
    createclockwindow.cpp \
    creategroupwindow.cpp \
    createtimerwindow.cpp \
    donotdisturbinfowindow.cpp \
    group.cpp \
    infoclockwindow.cpp \
    infogroupwindow.cpp \
    infotimerwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    removewindow.cpp \
    signalwindow.cpp \
    timer.cpp

HEADERS += \
    choosewindow.h \
    clock.h \
    createclockwindow.h \
    creategroupwindow.h \
    createtimerwindow.h \
    donotdisturbinfowindow.h \
    group.h \
    infoclockwindow.h \
    infogroupwindow.h \
    infotimerwindow.h \
    mainwindow.h \
    removewindow.h \
    signalwindow.h \
    timer.h

FORMS += \
    choosewindow.ui \
    createclockwindow.ui \
    creategroupwindow.ui \
    createtimerwindow.ui \
    donotdisturbinfowindow.ui \
    infoclockwindow.ui \
    infogroupwindow.ui \
    infotimerwindow.ui \
    mainwindow.ui \
    removewindow.ui \
    signalwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    snd.qrc
