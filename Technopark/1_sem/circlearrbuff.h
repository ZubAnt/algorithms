#ifndef CIRCLEARRBUFF_H
#define CIRCLEARRBUFF_H

#include <cstdlib>

#define CAPACITY_BUFF 2
#define RESIZE_FACTOR 2

/*
 *  -->> Tail -->> Head -->>
 */

class CircleArrBuff
{
public:
    CircleArrBuff();
    ~CircleArrBuff();
    void push_back(int val);
    int pop_front();
    void show();
private:

    size_t Size;
    size_t Capacity;
    size_t RightBor;    // индекс правой границы (Capacity - 1)
    size_t Tail;
    size_t Head;

    int *Data;

    void realloc_data();
};

#endif // CIRCLEARRBUFF_H
