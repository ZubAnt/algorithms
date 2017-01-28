#include <iostream>
#include "Fibonacci/fibonacci.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    int n;
    std::cin >> n;
    cout << Fibonacci::get(n) << endl;
    return 0;
}

