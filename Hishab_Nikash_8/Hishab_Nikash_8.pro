#-------------------------------------------------
#
# Project created by QtCreator 2019-02-28T09:02:35
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hishab_Nikash_8
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        hishab_nikash.cpp \
    sign_in.cpp \
    sign_up.cpp \
    all.cpp \
    history.cpp \
    fill.cpp \
    invalid.cpp \
    done.cpp \
    mismatch.cpp \
    exist.cpp

HEADERS += \
        hishab_nikash.h \
    sign_in.h \
    sign_up.h \
    all.h \
    history.h \
    fill.h \
    invalid.h \
    done.h \
    mismatch.h \
    exist.h

FORMS += \
        hishab_nikash.ui \
    sign_in.ui \
    sign_up.ui \
    all.ui \
    history.ui \
    fill.ui \
    invalid.ui \
    done.ui \
    mismatch.ui \
    exist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
