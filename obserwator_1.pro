TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ObserverPattern/observerinterface.cpp \
        ObserverPattern/subjectinterface.cpp \
        SimpleObserverPattern/simpleobserver.cpp \
        SimpleObserverPattern/simplesubject.cpp \
        main.cpp

HEADERS += \
    ObserverPattern/observerinterface.h \
    ObserverPattern/subjectinterface.h \
    SimpleObserverPattern/simpleobserver.h \
    SimpleObserverPattern/simplesubject.h
