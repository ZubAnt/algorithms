#include "mearge.h"
#include <memory>
#include <iostream>

void MeargeSort(std::vector<int> &Data)
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

                if(Data[LeftBorder + LeftIter] < Data[MidBorder + RightIter]){

                    SortedBlocksData[LeftIter + RightIter] = Data[LeftBorder + LeftIter];
                    ++LeftIter;
                }
                else{

                    SortedBlocksData[LeftIter + RightIter] = Data[MidBorder + RightIter];
                    ++RightIter;
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
