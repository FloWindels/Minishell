/*
** EPITECH PROJECT, 2024
** my_find_prime_sup
** File description:
** Return the smallest prime number than greater or equal to nb
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int count = nb;

    if (nb <= 1){
        return 2;
    }
    while (my_is_prime(nb) != 1) {
        nb++;
    }
    return nb;
}
