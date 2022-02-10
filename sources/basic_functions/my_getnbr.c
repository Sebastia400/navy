/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** function that returns a nbr from str
*/

#include <limits.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int nb = 0;

    while (str[i] != '\0') {
        if (nb > INT_MAX || nb < INT_MIN)
            return (0);
        if (str[i] == '-')
            neg *= -1;
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - 48;
        } if (nb > 0 && (str[i] < '0' || str[i] > '9'))
            return (nb * neg);
        i++;
    }
    return (nb * neg);
}

int my_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}

int my_ischar(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (0);
    return (1);
}