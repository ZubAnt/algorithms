#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "gralg.h"

/*
 * По данным n отрезкам необходимо найти множество точек минимального размера,
 * для которого каждый из отрезков содержит хотя бы одну из точек.
 * В первой строке дано число 1 ≤ n ≤ 100 отрезков.
 * Каждая из последующих nn строк содержит по два числа 0 ≤ l ≤ r ≤ 10^9,
 * задающих начало и конец отрезка.
 * Выведите оптимальное число m точек и сами m точек.
 * Если таких множеств точек несколько, выведите любое из них.
 */

static bool comp_by_end(std::array<int, 2> &a, std::array<int, 2> &b){
    return a[1] < b[1];
}

void first_case(std::vector<std::array<int, 2>> &v_pair,
                                    std::vector<int> &v_out){

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
