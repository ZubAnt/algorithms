#ifndef MEARGE_H
#define MEARGE_H

#include <vector>
#include <memory>
#include <iostream>

/*
 * Первая строка содержит число 1≤n≤10^5, вторая — массив A[1…n],
 * содержащий натуральные числа, не превосходящие 109109.
 * Необходимо посчитать число пар индексов 1 ≤ i < j ≤ n, для которых A[i]>A[j].
 * (Такая пара элементов называется инверсией массива.
 * Количество инверсий в массиве является в некотором смысле его мерой неупорядоченности:
 * например, в упорядоченном по неубыванию массиве инверсий нет вообще,
 * а в массиве, упорядоченном по убыванию, инверсию образуют каждые два элемента.)
 */

template<class T>
class Mearge{

public:

    Mearge();
    Mearge(const std::vector<T> &data);
    void push_back(const T &data);
    void mearge_sort();
    std::size_t disorder();                     // return disorder coefficient; call after mearge_sort
    std::size_t tupoy_disorder();
    void show();

private:

    std::vector<T> Data;
    std::size_t DisorderCoeff;
};

template<class T>
Mearge<T>::Mearge()
{DisorderCoeff = 0;}

template<class T>
Mearge<T>::Mearge(const std::vector<T> &data):Data(data), DisorderCoeff(0)
{}

template<class T>
void Mearge<T>::push_back(const T &data)
{
    Data.push_back(data);
}

template<class T>
void Mearge<T>::mearge_sort()
{
    std::size_t Size = Data.size();
    std::size_t SortedBlockSize;

    std::size_t LeftIter;
    std::size_t RightIter;

    std::size_t LeftBorder;
    std::size_t MidBorder;
    std::size_t RightBorder;

    for (std::size_t BlockSize = 1; BlockSize < Size; BlockSize *= 2) {

        for (std::size_t BlockIter = 0; BlockIter < Size - BlockSize; BlockIter += 2 * BlockSize) {

            LeftBorder = BlockIter;
            MidBorder = LeftBorder + BlockSize;
            RightBorder = MidBorder + BlockSize;
            RightBorder = (RightBorder < Size) ? RightBorder : Size;

            SortedBlockSize = RightBorder - LeftBorder;

            LeftIter = 0;
            RightIter = 0;

            std::unique_ptr<std::size_t[]> SortedBlocksData(new std::size_t[SortedBlockSize]);

            while (LeftBorder + LeftIter < MidBorder && MidBorder + RightIter < RightBorder) {

                if(Data[LeftBorder + LeftIter] > Data[MidBorder + RightIter]){

                    SortedBlocksData[LeftIter + RightIter] = Data[MidBorder + RightIter];
                    ++RightIter;
                    DisorderCoeff += BlockSize - LeftIter;

                }
                else{
                    SortedBlocksData[LeftIter + RightIter] = Data[LeftBorder + LeftIter];
                    ++LeftIter;

                }
            }

            for (; LeftBorder + LeftIter < MidBorder; ++LeftIter) {

                SortedBlocksData[LeftIter + RightIter] = Data[LeftBorder + LeftIter];
            }

            for (; MidBorder + RightIter < RightBorder; ++RightIter) {

                SortedBlocksData[LeftIter + RightIter] = Data[MidBorder + RightIter];
            }

            for (std::size_t Meargeiter = 0; Meargeiter < SortedBlockSize; ++Meargeiter) {

                Data[LeftBorder + Meargeiter] = SortedBlocksData[Meargeiter];
            }
        }
    }
}

// return disorder coefficient; call after mearge_sort
template<class T>
std::size_t Mearge<T>::disorder()
{
    return DisorderCoeff;
}

template<class T>
std::size_t Mearge<T>::tupoy_disorder()
{
    std::size_t cnt = 0;
    std::size_t size = Data.size();
    for(std::size_t i = 0; i < size - 1; ++i){
        for(std::size_t j = i + 1; j < size; ++j){
            if(Data[i] > Data[j]){
                ++cnt;
            }
        }
    }
    return cnt;
}

template<class T>
void Mearge<T>::show()
{
    for(auto &it:Data){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

#endif // MEARGE_H
