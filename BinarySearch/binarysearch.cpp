#include "binarysearch.h"
#include <assert.h>
#include <stdexcept>
#include <iostream>

BinarySearch::BinarySearch(const std::vector<int> &data):data(data)
{}

int BinarySearch::get_index(int number)
{
    assert(!data.empty());
    int a = 0;
    int b = data.size() - 1;

    int index = 0;
    bool find = false;


    while( (b - a) > 0 ){

        index = a + (b - a) / 2;
        if(number == data[index]){
            find = true;
            break;
        }
        else if(number < data[index]){
            b = index;
        }
        else if(number > data[index]){
            a = index + 1;
        }
    }

    if(a == b){
        if(number == data[a]){
            return a + 1;
        }
    }

    if(!find){
        return -1;
//        throw std::logic_error("cannot find number in data vector");
    }

    return index + 1;
}
