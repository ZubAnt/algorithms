#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <vector>
#include <array>
#include <string>
#include <typeinfo>

#include "Fibonacci/fibonacci.h"
#include "GreedyAlgorithms/gralg.h"
#include "Huffman_code/huffman.h"

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

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen (seed);
    std::uniform_int_distribution<int> dist (10, 99);

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

    string str;
    string out;
    std::getline (std::cin, str);
    Huffman<char, int> obj;
    std::cout << obj.string_to_code(str) << std::endl;

//    my_priority_queue<char, int> test;

//    test.InsertWithPriority('a', 80);
//    test.InsertWithPriority('a', 52);
//    test.InsertWithPriority('a', 85);
//    test.InsertWithPriority('a', 55);
//    test.InsertWithPriority('a', 18);
//    test.InsertWithPriority('a', 40);
//    test.InsertWithPriority('a', 36);
//    test.InsertWithPriority('a', 77);
//    test.InsertWithPriority('a', 77);
//    test.InsertWithPriority('a', 77);
//    test.InsertWithPriority('a', 77);

//    test.show_all_data();
//    std::cout << "=============\n";
//    std::cout << "depth = " << test.get_depth() << std::endl;
//    test.show_all_data();

    return 0;
}













