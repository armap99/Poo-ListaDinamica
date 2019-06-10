TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    cancion.cpp \
    lista.cpp \
    node.cpp

HEADERS += \
    cancion.h \
    error.h \
    lista.h \
    node.h
