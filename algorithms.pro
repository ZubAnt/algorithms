TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -fpermissive -std=c++11

SOURCES += main.cpp Fibonacci/Fibonacci.cpp \
    GreedyAlgorithms/gralg.cpp \

HEADERS += \
    Fibonacci/fibonacci.h \
    GreedyAlgorithms/gralg.h \
    Huffman_code/huffman.h \
