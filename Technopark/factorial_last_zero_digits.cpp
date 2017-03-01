#include "factorial_last_zero_digits.h"
#include <stdexcept>

static std::size_t numb_occur(int64_t n, int64_t occur);

int64_t factorial_last_zero_digits(int64_t n)
{
    std::size_t count_2 = 0;
    std::size_t count_5 = 0;
    for(int64_t i = 2; i <= n; ++i){
        if(i % 2 == 0){
            count_2 += numb_occur(i, 2);
        }
        if(i % 5 == 0){
            count_5 += numb_occur(i, 5);
        }
    }

    return std::min(count_2, count_5);
}

static std::size_t numb_occur(int64_t n, int64_t occur){

    if(n <= 0){
        throw std::invalid_argument("\"n\" must be positive");
    }
    std::size_t cnt_occur = 0;
    while(n != 0 && n % occur == 0){
        ++cnt_occur;
        n /= occur;
    }
    return cnt_occur;
}
