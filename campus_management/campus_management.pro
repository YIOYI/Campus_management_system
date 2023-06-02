QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QT += multimedia

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Alarm.cpp \
    Building.cpp \
    Event.cpp \
    Person.cpp \
    ShortestPath.cpp \
    _Time.cpp \
    adminwdt.cpp \
    form1.cpp \
    form2.cpp \
    form3.cpp \
    insert_event.cpp \
    main.cpp \
    mainwindow.cpp \
    tabwidget.cpp \
    timepause.cpp

HEADERS += \
    Alarm.h \
    Building.h \
    Event.h \
    Person.h \
    _Time.h \
    adminwdt.h \
    form1.h \
    form2.h \
    form3.h \
    insert_event.h \
    log.h \
    mainwindow.h \
    tabwidget.h \
    timepause.h

FORMS += \
    adminwdt.ui \
    form1.ui \
    form2.ui \
    form3.ui \
    insert_event.ui \
    mainwindow.ui \
    tabwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc

DISTFILES +=
