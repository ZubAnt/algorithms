#ifndef GETPRIMES_H
#define GETPRIMES_H


class CIntVector {
public:
    CIntVector( int _size );
    CIntVector( const CIntVector& other );
    ~CIntVector() { delete data; }

    // Размер массива.
    int Size() const { return size; }

    // Операторы доступа к элементам по индексу.
    // Константный оператор возвращает копию элемента.
    int operator[]( int index ) const;
    // Неконстантный оператор возвращает ссылку на элемент.
    int& operator[]( int index );

private:
    int* data;
    int size;
};

CIntVector GetPrimes( int n );


#endif // GETPRIMES_H
