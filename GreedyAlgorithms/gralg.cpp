#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "gralg.h"

/*
 * По данным n отрезкам необходимо найти множество точек минимального размера,
 * для которого каждый из отрезков содержит хотя бы одну из точек.
 * В первой строке дано число 1 ≤ n ≤ 100 отрезков.
 * Каждая из последующих n строк содержит по два числа 0 ≤ l ≤ r ≤ 10^9,
 * задающих начало и конец отрезка.
 * Выведите оптимальное число m точек и сами m точек.
 * Если таких множеств точек несколько, выведите любое из них.
 */

static bool comp_by_end(std::array<int, 2> &a, std::array<int, 2> &b){
    return a[1] < b[1];
}

void first_case(std::vector<std::array<int, 2>> &v_pair, std::vector<int> &v_out){

    if(v_pair.empty()){

        throw std::logic_error("empty input vector");
    }
    std::sort(v_pair.begin(), v_pair.end(), comp_by_end);

    int rigth_border = (*v_pair.begin())[1];
    v_out.push_back(rigth_border);

    for(auto it = v_pair.begin(); it != v_pair.end(); ++it){
        if((*it)[0] > rigth_border){
            rigth_border = (*it)[1];
            v_out.push_back(rigth_border);
        }
    }
}

/*
 * Первая строка содержит количество предметов 1 ≤ n ≤ 10^3 и вместимость рюкзака 0 ≤ W ≤ 2⋅10^6.
 * Каждая из следующих n строк задаёт стоимость 0 ≤ ci ≤ 2⋅10^6 и
 * объём 0< wi ≤ 2⋅10^6 предмета (n, W, ci, wi — целые числа).
 * Выведите максимальную стоимость частей предметов (от каждого предмета можно отделить любую часть,
 * стоимость и объём при этом пропорционально уменьшатся), помещающихся в данный рюкзак,
 * с точностью не менее трёх знаков после запятой.
 */

static bool comp_by_cost(std::array<double, 2> &a, std::array<double, 2> &b){
    return (a[0] / a[1]) > (b[0] / b[1]);
}

double second_case(int W, std::vector<std::array<double, 2> > &v_pair)
{
    if(v_pair.empty()){

        throw std::logic_error("empty input vector");
    }

    double curr_W = 0.0;
    double all_W = static_cast<double>(W);
    double ret_cost = 0.0;

    std::sort(v_pair.begin(), v_pair.end(), comp_by_cost);

    for(auto it = v_pair.begin(); it != v_pair.end(); ++it){

        if(curr_W + (*it)[1] <= all_W){

            curr_W += (*it)[1];
            ret_cost += (*it)[0];
        }
        else{

            ret_cost += (*it)[0] * (all_W - curr_W) / (*it)[1];
            break;
        }
    }

    return ret_cost;
}

/*
 * По данному числу 1 ≤ n ≤ 10^9 найдите максимальное число k,
 * для которого n можно представить как сумму k различных натуральных слагаемых.
 * Выведите в первой строке число k, во второй — k слагаемых.
 */

void third_case(int n, std::vector<int> &v_out){

    int cur_summ = 0;   // текущая сумма
    int sur = n;        // отсавшееся число для разложения
    int i = 1;

    while (cur_summ != n) {

        if(sur > i * 2){            // sur >= i + (i + 1)

            cur_summ += i;
            v_out.push_back(i);
            sur = n - cur_summ;
            ++i;
        }
        else{

            cur_summ += sur;
            v_out.push_back(sur);
        }
    }
}
