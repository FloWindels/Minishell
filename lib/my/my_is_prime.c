/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** Return if a number is a prime number
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb <= 1){
        return 0;
    }
    for (int count = 2; count <= nb / 2; count++) {
        if (nb % count == 0) {
            return 0;
        }
    }
    return 1;
}
