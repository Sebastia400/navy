/*
** EPITECH PROJECT, 2021
** function main
** File description:
** func principal main
*/

#include "./../includes/libraries.h"

void free_all(t_variables *var, char **map)
{
    free(map);
    free(global_var->signal_bit);
    free(var->shipsenemymap);
    free(var->shipsmap);
}

void printhelp(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n");
    my_putstr("     navy_positions: file representing the positions of");
    my_putstr(" the ships.\n");
}

void my_pid()
{
    global_var->user1_pid = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(global_var->user1_pid);
    my_putstr("\n\n");
}