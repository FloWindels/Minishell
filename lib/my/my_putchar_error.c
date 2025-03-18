/*
** EPITECH PROJECT, 2024
** emacs
** File description:
** my_putchar
*/
#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
