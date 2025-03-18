/*
** EPITECH PROJECT, 2024
** my_compute_power_rec
** File description:
** Return power of a number
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int res;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    res = nb * my_compute_power_rec(nb, p - 1);
    return res;
}
