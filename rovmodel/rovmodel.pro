TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    floatingobject.cpp \
    core.cpp \
    robot.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    floatingobject.h \
    robot.h
