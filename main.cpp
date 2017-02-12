#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <vector>
#include <array>
#include <string>
#include <typeinfo>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <queue>

#include "Fibonacci/fibonacci.h"
#include "GreedyAlgorithms/gralg.h"
#include "Huffman_code/huffman.h"
#include "Heap/heap.h"
#include "BinarySearch/binarysearch.h"

using namespace std;

void print_v_pair(const vector<array<double, 2>> &v){

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
        std::cout << *it << std::endl;
    }
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


//    int n, W,ci, wi;
//    vector<array<double, 2>> v_inp;

//    cin >> n >> W;
//    for(int i = 0; i < n; ++i){
//        cin >> ci >> wi;
//        v_inp.push_back({static_cast<double>(ci),
//                         static_cast<double>(wi)});
//    }

//    double cost = second_case(W, v_inp);
//    cout << fixed << setprecision(3) << cost << endl;

    /// ========================================================================

//    int n;
//    vector<int> v_out;
//    cin >> n;
//    third_case(n, v_out);
//    cout << v_out.size() << endl;
//    print_v(v_out);

    /// ========================================================================

//    int len = 64;
//    std::string test_str;

//    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";

//    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//    std::default_random_engine gen (seed);
//    std::uniform_int_distribution<int> dist (0, sizeof(alphanum) - 1);

//    for (int i = 0; i < len; ++i) {

//        test_str += alphanum[dist(gen)];
//    }

//    std::cout << test_str << std::endl << std::endl;
//    Huffman<char, int> obj_to_code;
//    std::cout << obj_to_code.string_to_code(test_str) << std::endl;

    /// ========================================================================

//    int numb_data, len_code;
//    std::string data;
//    std::string code;
//    Huffman<char, int> obj_from_code;

//    fstream inp_stream("out.txt", std::fstream::in);

//    inp_stream >> numb_data >> len_code;

//    for(int i = 0; i < numb_data; i++){
//        inp_stream >> data >> code;
//        obj_from_code.push_back_DataWithCode(data.front(), code);
//    }

//    inp_stream >> code;

//    std::cout << std::endl << "code:   " << test_str
//              << std::endl << "decode: " << obj_from_code.code_to_string(code) << std::endl;
    /// ========================================================================

//    std::priority_queue<int> mypq;
//    std::vector<int> v;
//    int n;
//    cin >> n;
//    int x;
//    std::string inp;
//    std::string Insert("Insert");
//    std::string ExtractMax("ExtractMax");

//    for(int i = 0; i < n; ++i){
//        cin >> inp;

//        if(inp == Insert){
//            cin >> x;
//            mypq.push(x);
//        }
//        else{
//            v.push_back(mypq.top());
//            mypq.pop();
//        }
//    }
//    print_v(v);

    /// ========================================================================

//    heap obj;
//    std::vector<int> v;
//    int n;
//    cin >> n;
//    int x;
//    std::string inp;
//    std::string Insert("Insert");
//    std::string ExtractMax("ExtractMax");

//    for(int i = 0; i < n; ++i){
//        cin >> inp;

//        if(inp == Insert){
//            cin >> x;
//            obj.Insert(x);
//        }
//        else{
//            v.push_back(obj.ExtractMax());
//        }
//    }
//    print_v(v);

    /// ========================================================================

//    std::vector<int> v1 = {8, -3, 2, -4, -4, 1, -10};
//    std::vector<int> v2 = {3,20,4,30,21,30,5,31,60,30,31,31};
//    std::vector<int> v3 = {2,4,5,12,5,6};
//    std::vector<int> v4 = {3,20,4,30,21,30,5,31,60,30,21,31};

//    heap h1(v1);
//    heap h2(v2);
//    heap h3(v3);
//    heap h4(v4);

//    if(h1.IsMaxHeap()){
//        std::cout << "True" << std::endl;
//    }
//    if(h2.IsMinHeap()){
//        std::cout << "True" << std::endl;
//    }
//    if(h3.IsMinHeap()){
//        std::cout << "True" << std::endl;
//    }
//    if(h4.IsMinHeap()){
//        std::cout << "True" << std::endl;
//    }

    /// ========================================================================


    int n1, n2;
    int x;
    std::vector<int> v;

    std::cin >> n1;

    for(int i = 0; i < n1 ; ++i){
        std::cin >> x;
        v.push_back(x);
    }

    BinarySearch obj(v);
    std::cin >> n2;

    for(int i = 0; i < n2; ++i){
        std::cin >> x;
        std::cout << obj.get_index(x) << " ";
    }

    return 0;
}
