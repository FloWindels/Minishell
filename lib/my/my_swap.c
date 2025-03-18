/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** Swap content of two integers
*/

void my_swap(int *a, int *b)
{
    int stock;

    stock = *a;
    *a = *b;
    *b = stock;
}
