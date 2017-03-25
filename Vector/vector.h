#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <algorithm>
#include <stdexcept>

template<class Type>
class my_vector
{
public:
    my_vector();
    my_vector(const my_vector<Type> &obj);
    my_vector& operator=(const my_vector<Type> &obj);
    void push_back(Type val);
    size_t size();
    bool empty();
    Type pop_back();
    Type operator[](size_t index);
    ~my_vector();
    Type *begin(){ return Data; }
    Type *end(){ return (Data + Size); }

private:
    size_t Size;
    size_t Capacity;
    Type *Data;

    void realloc_data();
};


template<class Type>
my_vector<Type>::my_vector()
{
    Size = 0;
    Capacity = 8;
    Data = new Type[Capacity + 1];
}

template<class Type>
my_vector<Type>::my_vector(const my_vector<Type> &copy):
    Size(copy.Size),
    Capacity(copy.Capacity),
    Data(new Type[Capacity + 1])
{
    std::copy(copy.Data, copy.Data + copy.Size, Data);
}

template<class Type>
my_vector<Type> &my_vector<Type>::operator=(const my_vector<Type> &obj)
{
    ~my_vector();
    Size = obj.Size;
    Capacity = obj.Capacity;
    Data = new Type[Capacity + 1];
    std::copy(obj.Data, obj.Data + obj.Size, Data);
    return *this;
}

template<class Type>
void my_vector<Type>::push_back(Type val)
{
    if(Size == Capacity){ realloc_data(); }
    Data[Size] = val;
    ++Size;
}

template<class Type>
size_t my_vector<Type>::size()
{
    return Size;
}

template<class Type>
bool my_vector<Type>::empty()
{
   return (Size == 0) ? true: false;
}

template<class Type>
Type my_vector<Type>::pop_back()
{
    if (Size == 0) { throw std::out_of_range("Size == 0"); }
    Type val = Data[Size];
    --Size;
    return val;
}

template<class Type>
Type my_vector<Type>::operator[](size_t index)
{
    if(index >= Size)  { throw std::out_of_range("index >= Size"); }
    return Data[index];
}

template<class Type>
my_vector<Type>::~my_vector()
{
    delete Data;
}

template<class Type>
void my_vector<Type>::realloc_data()
{
    size_t new_capacity = 2 * Capacity;
    Type *new_data = new Type[new_capacity + 1];

    std::copy(Data, Data + Capacity, new_data);
    delete[] Data;

    Data = new_data;
    Capacity = new_capacity;
}

#endif // VECTOR_H
