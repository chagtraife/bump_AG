QT += widgets serialport core sql

TARGET = terminal
TEMPLATE = app

CONFIG += staticlib
QTPLUGIN     += qgif

INCLUDEPATH += $$PWD
INCLUDEPATH += ../qtBaseLib
RC_FILE = terminal.rc

SOURCES += \
    authen.cpp \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp \
    dmxconsole.cpp \
    deviceview.cpp \
    loadingdialog.cpp \
    TestDialog.cpp \
    dmx_monitor.cpp \
    WindDMXConverter_Setting.cpp

HEADERS += \
    authen.h \
    mainwindow.h \
    settingsdialog.h \
    console.h \
    dmxconsole.h \
    deviceview.h \
    loadingdialog.h \
    TestDialog.h \
    dmx_monitor.h \
    WindDMXConverter_Setting.h\
    qtBaseLib.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui \
    dmxconsole.ui \
    deviceview.ui \
    loadingdialog.ui \
    TestDialog.ui \
    dmx_monitor.ui \
    WindDMXConverter_Setting.ui

LIBS += -L"$$_PRO_FILE_PWD_/" -lqtBaseLib

RESOURCES += \
    terminal.qrc

DISTFILES +=
