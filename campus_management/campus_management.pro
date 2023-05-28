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
    form1.cpp \
    form2.cpp \
    form3.cpp \
    insert_event.cpp \
    main.cpp \
    mainwindow.cpp \
    tabwidget.cpp

HEADERS += \
    Alarm.h \
    Building.h \
    Event.h \
    Person.h \
    _Time.h \
    form1.h \
    form2.h \
    form3.h \
    insert_event.h \
    mainwindow.h \
    tabwidget.h

FORMS += \
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

DISTFILES += \
    ../build-campus_management-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/debug/qt.conf