TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -fpermissive -std=c++11

SOURCES += main.cpp Fibonacci/Fibonacci.cpp \
    GreedyAlgorithms/gralg.cpp \
    Heap/heap.cpp \
    BinarySearch/binarysearch.cpp \
    Technopark/factorial_last_zero_digits.cpp \
    Technopark/1_sem/getprimes.cpp \
    Technopark/1_sem/anagram.cpp \
    List/duallylist.cpp \
    Technopark/1_sem/circlearrbuff.cpp \
    Technopark/1_sem/widepyramid.cpp


HEADERS += \
    Fibonacci/fibonacci.h \
    GreedyAlgorithms/gralg.h \
    Huffman_code/huffman.h \
    Heap/heap.h \
    BinarySearch/binarysearch.h \
    Mearge/mearge.h \
    Technopark/factorial_last_zero_digits.h \
    Technopark/1_sem/getprimes.h \
    Vector/vector.h \
    Technopark/1_sem/anagram.h \
    List/duallylist.h \
    Technopark/1_sem/circlearrbuff.h \
    Stack/stack.h \
    Technopark/1_sem/widepyramid.h
