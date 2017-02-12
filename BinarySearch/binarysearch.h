#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

class BinarySearch
{
public:
    BinarySearch(const std::vector<int> &data);
    int get_index(int number);
private:
    std::vector<int> data;
};

#endif // BINARYSEARCH_H
