#include "heap.h"
#include <assert.h>
#include <iostream>

heap::heap()
{}

heap::heap(const std::vector<int> &_data):data(_data),size(_data.size())
{}

void heap::BuildHeap()
{
    for(size_t i = 0 ; i < size / 2 - 1; ++i){
        Heapify(i);
    }
}

void heap::Insert(int number)
{
    data.push_back(number);
    size = data.size();
    int index = size - 1;
    int root = (index - 1) / 2;
    while (data[root] < data[index]) {
        std::swap(data[root], data[index]);
        index = root;
        root = (index - 1) / 2;
    }
}

//void heap::Insert(int number)
//{
//    data.push_back(number);
//    size = data.size();
//    int index = data.size() - 1;

//    while (index > 0) {
//        int root = (index - 1) / 2;
//        if(data[index] <= data[root]){
//            return;
//        }
//        std::swap(data[root], data[index]);
//        index = root;
//    }
//}


int heap::ExtractMax()
{

    assert(!data.empty());

    int result = data[0];   // Запоминаем значение корня.

    data[0] = data.back();  // Переносим последний элемент в корень.
    data.pop_back();

    if(!data.empty()){ // Вызываем Heapify для корня.
        Heapify(0);
    }

    return result;
}

void heap::Show()
{
    for(auto &it:data){
        std::cout << it << " ";
    }
    std::cout << std :: endl;
}

bool heap::IsMaxHeap()
{
    if(!data.empty()){

        for(size_t index = 0; index < size / 2 - 1; ++index){

            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;

            if(left < data.size() && data[left] > data[index]){
                return false;
            }

            if(right < data.size() && data[right] > data[index]){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool heap::IsMinHeap()
{
    if(!data.empty()){

        for(size_t index = 0; index < size / 2 - 1; ++index){

            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;

            if(left < data.size() && data[left] < data[index]){
                return false;
            }

            if(right < data.size() && data[right] < data[index]){
                return false;
            }
        }
        return true;
    }
    return false;
}

void heap::Heapify(int index)
{
    int index_max = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Ищем большего сына, если такой есть
    if(left < data.size() && data[left] > data[index_max]){
        index_max = left;
    }
    if(right < data.size() && data[right] > data[index_max]){
        index_max = right;
    }
    // Если больший сын есть, то проталкиваем в него корень
    if(index != index_max){
        std::swap(data[index], data[index_max]);
        Heapify(index_max);
    }
}
