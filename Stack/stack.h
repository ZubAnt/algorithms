#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <algorithm>
#include <stdexcept>

template<class Type>
class Stack
{
public:
    Stack();
    ~Stack();
    void push_back(Type val);
    Type pop_back();
    bool is_empty();
    Type get_last();

private:
    size_t Size;
    size_t Capacity;
    Type *Data;
    void realloc_data();
};

template<class Type>
Stack<Type>::Stack():Size(0), Capacity(8), Data(new Type[Capacity])
{}

template<class Type>
Stack<Type>::~Stack()
{
    delete[] Data;
}

template<class Type>
void Stack<Type>::push_back(Type val)
{
   if(Size == Capacity){ realloc_data(); }
   Data[Size] = val;
   ++Size;
}

template<class Type>
Type Stack<Type>::pop_back()
{
    if(Size == 0){ throw std::out_of_range("Size == 0"); }
    Type val = Data[Size];
    --Size;
    return val;
}

template<class Type>
bool Stack<Type>::is_empty()
{
    return (Size == 0) ? true: false;
}

template<class Type>
Type Stack<Type>::get_last()
{
    if(Size == 0){ throw std::out_of_range("Size == 0"); }
    return Data[Size - 1];
}

template<class Type>
void Stack<Type>::realloc_data()
{
    size_t new_capacity = 2 * Capacity;
    Type *new_data = new Type[new_capacity];

    std::copy(Data, Data + Capacity, new_data);
    delete[] Data;

    Data = new_data;
    Capacity = new_capacity;
}

#endif // STACK_H
