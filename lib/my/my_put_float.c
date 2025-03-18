/*
** EPITECH PROJECT, 2024
** my_put_float
** File description:
** print a float
*/

#include "my.h"

int my_put_float(double n, int pre)
{
    long fristNum = (long)n;
    long reminder;
    long nbcara;

    nbcara = my_put_nbr(fristNum);
    my_putchar('.');
    nbcara++;
    n = my_round(n * pre, 1);
    reminder = (long)n % pre;
    if (reminder < 10) {
        pre = pre / 10;
        while (pre != 1) {
            my_putchar('0');
            nbcara++;
            pre = pre / 10;
        }
    }
    nbcara = my_put_nbr(reminder);
    return nbcara;
}
