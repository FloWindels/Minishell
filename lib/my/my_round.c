/*
** EPITECH PROJECT, 2024
** my_round
** File description:
** round the number
*/

double my_round(double n, int pres)
{
    double dot;
    double rest;

    n = n * pres;
    dot = (long)n;
    rest = n - dot;
    if (rest <= 0.5)
        return dot / pres;
    else {
        dot++;
        dot = dot / pres;
    }
    return dot;
}
