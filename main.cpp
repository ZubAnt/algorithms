#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <array>
#include "Fibonacci/fibonacci.h"
#include "GreedyAlgorithms/gralg.h"

using namespace std;

void print_v_pair(const vector<array<int, 2>> &v){

    for(auto it = v.cbegin();it != v.cend(); ++it){
        cout << (*it)[0] << " ";
    }
    cout << endl;
    for(auto it = v.cbegin();it != v.cend(); ++it){
        cout << (*it)[1] << " ";
    }
    cout << endl;
}

void print_v(const vector<int> &v){
    for(auto it = v.cbegin();it != v.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
//    int n;
//    std::cin >> n;
//    cout << Fibonacci::get(n) << endl;

    /// ========================================================================
//    int n, l, r;
//    vector<array<int, 2>> v_inp;
//    vector<int> v_out;

//    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//    std::default_random_engine gen (seed);
//    std::uniform_int_distribution<int> dist (10, 99);

////    for(int i = 0; i < 30; ++i){
////        v_inp.push_back({dist(gen), dist(gen)});
////    }

//    cin >> n;

//    for(int i = 0; i < n; ++i){
//        cin >> l >> r;
//        v_inp.push_back({l, r});
//    }

//    first_case(v_inp, v_out);
//    cout << v_out.size() << endl;
//    print_v(v_out);

    /// ========================================================================

    return 0;
}

