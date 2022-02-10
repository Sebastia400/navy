/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** function that can display int values
*/

#include "./../../includes/libraries.h"

long my_put_nbr(long nb)
{
    long n;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            n = (nb % 10);
            nb = (nb - n) / 10;
            my_put_nbr(nb);
            my_putchar(48 + n);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
    return (0);
}