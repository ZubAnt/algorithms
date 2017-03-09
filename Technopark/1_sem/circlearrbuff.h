#ifndef CIRCLEARRBUFF_H
#define CIRCLEARRBUFF_H

#include <cstdlib>

#define CAPACITY_BUFF 8
#define RESIZE_FACTOR 2

/*
 *  -->> Tail -->> Head -->>
 */

class CircleArrBuff
{
public:
    CircleArrBuff();
    ~CircleArrBuff();
private:

    size_t Size;
    size_t Capacity;
    size_t Tail;
    size_t Head;

    int *Data;

    void realloc_data();
};

#endif // CIRCLEARRBUFF_H
