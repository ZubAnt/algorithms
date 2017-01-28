#include <cassert>
#include <iostream>
#include <vector>

#include "fibonacci.h"


int Fibonacci::get(int n)
{
    assert(n >= 0);
    if(n > 1){
        int f[n+1];
        f[0] = 0;
        f[1] = 1;
        for(int i = 2; i < n + 1; ++i) {

            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
    return n;
}

int Fibonacci::get_last_digit(int n){

    assert(n >= 0);
    if(n > 1){
        int f[n+1];
        f[0] = 0;
        f[1] = 1;
        for(int i = 2; i < n + 1; ++i) {

            f[i] = (f[i-1] + f[i-2]) % 10;
        }
        return f[n];
    }
    return n;
}

int Fibonacci::get_remainder(int64_t n, int m){

    assert(n >= 1);
    assert(m >= 2);

    int64_t mod_0 = 0;  //остаток от деления 0-ого числа Фибоначчи на m (0 % m = 0, m >= 2)
    int64_t mod_1 = 1;  //остаток от деления 1-ого числа Фибоначчи на m (1 % m = 1, m >= 2)
    int64_t mod_2 = (mod_0 + mod_1) % m;
    int64_t mod_3 = (mod_1 + mod_2) % m;

    int search_len = m * m + 1;     // в m^2+1 найдется хотя бы один период Пизано
    int pisano_period = 0;

    std::vector<int64_t> mod = {mod_0, mod_1, mod_2, mod_3};

    for(int i = 2; i < search_len; ++i){

        if(mod[i] == mod_0 && mod[i+1] == mod_1){
            pisano_period = i;
            break;
        }

        mod.push_back((mod[i] + mod[i+1]) % m);
    }

    return mod[n % pisano_period];
}
