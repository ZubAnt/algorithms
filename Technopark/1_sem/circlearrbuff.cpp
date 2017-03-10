#include "circlearrbuff.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

CircleArrBuff::CircleArrBuff():
    Size(0),
    Capacity(CAPACITY_BUFF),
    RightBor(Capacity - 1),
    Tail(0),
    Head(0),
    Data(new int[CAPACITY_BUFF])
{
    std::fill_n(Data, Capacity, '\0');
}

CircleArrBuff::~CircleArrBuff()
{
    Size = 0;
    Capacity = 0;
    RightBor = 0;
    Tail= 0;
    Head = 0;
    delete[] Data;
}

void CircleArrBuff::push_back(int val)
{
    if (Size == Capacity) { realloc_data(); }

    if (Head == RightBor && Size != 0) { Head = 0; }
    else if (Head != RightBor && Size != 0) { ++Head; }
    else if (Size == 0) {
        Head = 0;
        Tail = 0;
    }

    Data[Head] = val;
    ++Size;
}

int CircleArrBuff::pop_front()
{
    if (Size == 0) { return -1; }
    int val = Data[Tail];

    if (Tail == RightBor && Head < Tail) { Tail = 0; }
    else if (Tail == RightBor && Tail == Head) {}
    else { ++Tail; }
    --Size;

    return val;
}

void CircleArrBuff::show()
{
    std::cout << "SHOW_______________" << std::endl;

    std::cout << "Tail = " << Tail << "; Head = " << Head
              << "; Size = " << Size << "; Capasity = " << Capacity
              << std::endl;
    for(size_t i = 0; i < Capacity; ++i){std::cout << Data[i] << " ";}
    std::cout << std::endl;

    std::cout << "END----------------" << std::endl;
}

void CircleArrBuff::realloc_data()
{
    size_t new_capacity = Capacity * RESIZE_FACTOR;
    int *new_data = new int[new_capacity];
    std::fill_n(new_data, new_capacity, '\0');
    if (Head < Tail) {

        std::copy(Data + Tail, Data + Capacity, new_data);
        std::copy(Data, Data + Head + 1, new_data + Capacity - Tail);
    }
    else { std::copy(Data + Tail, Data + Head + 1, new_data); }

    delete[] Data;
    Data = new_data;
    Capacity = new_capacity;

    RightBor = Capacity - 1;
    Tail = 0;
    Head = Size - 1;
}
