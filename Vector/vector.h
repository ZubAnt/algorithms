#ifndef VECTOR_H
#define VECTOR_H

#define CAPACITY_VECTOR_8 8


#include <cstdlib>
#include <algorithm>

template<class Type>
class my_vector
{
public:
    my_vector();
    my_vector(const my_vector<Type> &obj);
    my_vector& operator=(const my_vector<Type> &obj);
    ~my_vector();

private:
    size_t Size;
    size_t Capacity;
    Type *Data;
};


template<class Type>
my_vector<Type>::my_vector()
{
    Size = 0;
    Capacity = CAPACITY_VECTOR_8;
    Data = new Type[Capacity];
}

template<class Type>
my_vector<Type>::my_vector(const my_vector<Type> &copy):
    Size(copy.Size),
    Capacity(copy.Capacity),
    Data(new Type[Capacity])
{
    std::copy(copy.Data, copy.Data + copy.Size, Data);
}

template<class Type>
my_vector<Type> &my_vector<Type>::operator=(const my_vector<Type> &obj)
{
    ~my_vector();
    Size = obj.Size;
    Capacity = obj.Capacity;
    Data = new Type[Capacity];
    std::copy(obj.Data, obj.Data + obj.Size, Data);
    return *this;
}


template<class Type>
my_vector<Type>::~my_vector()
{
    delete Data;
}










#endif // VECTOR_H



