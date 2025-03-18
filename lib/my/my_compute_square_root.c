/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** Return square root of a number
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int root = 0;

    while (my_compute_power_rec(root, 2) < nb) {
        root++;
    }
    if (my_compute_power_rec(root, 2) == nb) {
        return root;
    } else {
        return 0;
    }
}
