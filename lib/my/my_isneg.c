/*
** EPITECH PROJECT, 2024
** emacs
** File description:
** my_isneg
*/
#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else if (n >= 0)
        my_putchar('P');
}
