#include "widepyramid.h"
#include <cstdlib>

/*
 * Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков
 * пирамиду.
 * Формат входных данных:
 * На вход подается количество кубиков N.
 * Формат выходных данных:
 * Вывести число различных пирамид из N кубиков.
 * */


// сумма убывающей арифметической прогрессии от N до 1 с шагом 1
static size_t sum_ar_pr(size_t n){
    return ((n + 1) * n) / 2;
}

static size_t get_start_index(size_t numb_rem_cub){

    size_t ind = numb_rem_cub / 2 + 1;
    for(; ind > 0; --ind){
        if(sum_ar_pr(ind) < numb_rem_cub){
            ind += 1;
            break;
        }
    }
    return ind;
}

size_t getnumb_pyr(size_t numb_rem_cub, size_t right_board, size_t **table) // numb_remaining_cubes - количество оставшихся кубиков
{
    size_t cnt = 0;
    if(numb_rem_cub <= 2){
        if (table[numb_rem_cub][right_board] == 0){
            table[numb_rem_cub][right_board] = 1;
        }
        return 1;
    }

    size_t ind = get_start_index(numb_rem_cub);

    for(; ind <= right_board && ind <= numb_rem_cub; ++ind){

        size_t ostatok = numb_rem_cub - ind;

        if (table[ostatok][ind - 1] == 0){
            table[ostatok][ind - 1] = getnumb_pyr(ostatok, ind - 1, table);
        }

        cnt += table[ostatok][ind - 1];

    }
    return cnt;
}
