/*
** EPITECH PROJECT, 2021
** func. signals 1
** File description:
** functions needed to signal part 1
*/

#include "./../includes/libraries.h"

void killfunction(char *name)
{
    kill(my_getnbr(name), SIGQUIT);
}

void sigusr1(int num)
{
    global_var->signal_bit[global_var->signal_count] = 0;
    global_var->signal_count++;
}

void sigusr2(int num)
{
    global_var->signal_bit[global_var->signal_count] = 1;
    global_var->signal_count++;
}

int pos_to_nbr(int *pos)
{
    int result = 0;
    result = pos[0] + ((pos[1] - 1) * 8);
    return result;
}

int *nbr_to_pos(int nbr)
{
    int *result = malloc(nbr * sizeof(int) * 2);
    result[0] = nbr % 8;
    if (result[0] == 0)
        result[0] = 8;
    result[1] = nbr / 8;
    if (nbr % 8 != 0)
        result[1]++;
    return (result);
}
