#ifndef FIBONACCI_H
#define FIBONACCI_H

class Fibonacci final{
public:
    static int get(int n);                      // n-тое число Фибоначи
    static int get_last_digit(int n);           // последняя цифра n-того числа Фибоначи
    static int get_remainder(int64_t n, int m); // остаток от деления n-того числа Фибоначи на m
};

#endif // FIBONACCI_H
