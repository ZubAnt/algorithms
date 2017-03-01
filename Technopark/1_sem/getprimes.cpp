#include "getprimes.h"

#include <assert.h>
#include <iostream>
#include <string.h>



CIntVector::CIntVector( int _size ) :
    size( _size )
{
    if( size == 0 ) {
        data = 0;
    } else {
        data = new int[size];
    }
}

CIntVector::CIntVector( const CIntVector& other )
{
    size = other.size;
    data = new int[size];
    ::memmove( data, other.data, size * sizeof( int ) );
}

int CIntVector::operator[]( int index ) const
{
    assert( index >= 0 );
    assert( index < size );
    return data[index];
}

int& CIntVector::operator[]( int index )
{
    assert( index >= 0 );
    assert( index < size );
    return data[index];
}

// Возвращает массив простых чисел до n.
CIntVector GetPrimes( int n )
{
    assert( n > 0 );

    // Выделим массив под решето Эратосфена.
    bool* sieve = new bool[n + 1];
    for( int i = 0; i <= n; ++i ) {
        sieve[i] = true;
    }

    sieve[0] = false;
    sieve[1] = false;

    int primesCount = 0;
    // Выкалываем числа, кратные простым.
    for( int prime = 2; prime <= n; ++prime ) {
        if( !sieve[prime] ) {
            continue;
        }
        ++primesCount;
        for( int k = 2; k * prime <= n; ++k ) {
            sieve[k * prime] = false;
        }
    }

    CIntVector primes( primesCount );
    int currentIndex = 0;
    for( int i = 2; i <= n; ++i ) {
        if( sieve[i] ) { // Осталось не выколото => простое.
            primes[currentIndex++] = i;
        }
    }

    delete[] sieve;

    return primes;
}

