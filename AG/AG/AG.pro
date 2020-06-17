QT       += serialport core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += staticlib
CONFIG += c++11
QTPLUGIN     += qgif

INCLUDEPATH += $$PWD
INCLUDEPATH += ../qtBaseLib

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    WindDMXConverter_Setting.cpp \
    authen.cpp \
    deviceview.cpp \
    dmx_monitor.cpp \
    dmxconsole.cpp \
    loadingdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    testdialog.cpp \
    console.cpp \

HEADERS += \
    WindDMXConverter_Setting.h \
    authen.h \
    deviceview.h \
    dmx_monitor.h \
    dmxconsole.h \
    loadingdialog.h \
    mainwindow.h \
    settingsdialog.h \
    testdialog.h \
    console.h \
    qtBaseLib.h \

FORMS += \
    WindDMXConverter_Setting.ui \
    deviceview.ui \
    dmx_monitor.ui \
    dmxconsole.ui \
    loadingdialog.ui \
    mainwindow.ui \
    settingsdialog.ui \
    testdialog.ui \


LIBS += -L"$$_PRO_FILE_PWD_/" -lqtBaseLib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



RESOURCES += \
    AG.qrc

