#include "circlearrbuff.h"
#include <algorithm>

CircleArrBuff::CircleArrBuff():
    Size(0),
    Capacity(CAPACITY_BUFF),
    Tail(0),
    Head(0),
    Data(new int[CAPACITY_BUFF])
{}

CircleArrBuff::~CircleArrBuff()
{
    Size = 0;
    Capacity = 0;
    Tail= 0;
    Head = 0;
    delete[] Data;
}

void CircleArrBuff::realloc_data()
{
    size_t new_capacity = Capacity * RESIZE_FACTOR;
    int *new_data = new int[new_capacity];
    if (Head < Tail) {

        std::copy(Data + Tail, Data + Capacity, new_data);
        std::copy(Data, Data + Head + 1, new_data + Capacity - Tail);
    }
    else { std::copy(Data + Tail, Data + Head, new_data); }

    delete[] Data;
    Data = new_data;
    Capacity = new_capacity;
    Tail = 0;
    Head = Size - 1;
}


