#ifndef WIDEPYRAMID_H
#define WIDEPYRAMID_H

#include <cstdlib>

/*
 * Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков
 * пирамиду.
 * Формат входных данных:
 * На вход подается количество кубиков N.
 * Формат выходных данных:
 * Вывести число различных пирамид из N кубиков.
 * */


size_t getnumb_pyr(size_t numb_rem_cub, size_t right_board,
                   size_t **table);

#endif // WIDEPYRAMID_H
