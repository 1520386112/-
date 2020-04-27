QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    calcu.cpp \
    dialog_bj.cpp \
    dialog_bx.cpp \
    main.cpp \
    samplewidget.cpp \
    widget_sy_single.cpp \
    widget_sy_totle.cpp \
    widget_zh.cpp

HEADERS += \
    calcu.h \
    dialog_bj.h \
    dialog_bx.h \
    samplewidget.h \
    widget_sy_single.h \
    widget_sy_totle.h \
    widget_zh.h

FORMS += \
    dialog_bj.ui \
    dialog_bx.ui \
    samplewidget.ui \
    widget_sy_single.ui \
    widget_sy_totle.ui \
    widget_zh.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
