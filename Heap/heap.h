#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cstdlib>

class heap
{
public:
    heap();
    heap(const std::vector<int> &_data);

    void BuildHeap();
    void Insert(int number);
    int ExtractMax();
    void Show();
    bool IsMaxHeap();
    bool IsMinHeap();

private:
    std::vector<int> data;
    size_t size;

    void Heapify(int index);
};

#endif // HEAP_H
