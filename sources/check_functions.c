/*
** EPITECH PROJECT, 2021
** function main
** File description:
** func principal main
*/

#include "./../includes/libraries.h"

int check_if_nbr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        i++;
    }
    return (0);
}

void check_ship_length(t_variables *var, char *str)
{
    if ((str[2] == str[5] && str[3] == str[6]) ||
    (str[2] != str[5] && str[3] != str[6]))
        var->valuereturn = 84;
    if (str[2] > 'H' && str[5] > 'H')
        var->valuereturn = 84;
}

void check_pos_info(t_variables *var, char *str)
{
    if (my_isdigit(str[0]) != 0 || my_isdigit(str[3]) != 0
    || my_isdigit(str[6]) != 0)
        var->valuereturn = 84;
    if (str[1] != ':' || str[4] != ':')
        var->valuereturn = 84;
    if (my_ischar(str[2]) != 0 || my_ischar(str[5]) != 0)
        var->valuereturn = 84;
}
