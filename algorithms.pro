TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp Fibonacci/Fibonacci.cpp \
    GreedyAlgorithms/gralg.cpp

HEADERS += \
    Fibonacci/fibonacci.h \
    GreedyAlgorithms/gralg.h
