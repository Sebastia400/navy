/*
** EPITECH PROJECT, 2021
** func. print
** File description:
** functions needed to print
*/

#include "./../includes/libraries.h"

void print_map(char **map)
{
    int i = 0;
    int j = 0;

    my_putstr(" |A B C D E F G H\n\0");
    my_putstr("-+---------------\n\0");
    while (map[i] != NULL) {
        my_put_nbr(i + 1);
        my_putchar('|');
        j = 0;
        while (map[i][j] != '\0') {
            my_putchar(map[i][j]);
            if (map[i][j + 1] == '\0')
                my_putchar('\n');
            else
                my_putchar(' ');
            j++;
        }
        i++;
    }
    my_putchar('\n');
}

void print_result_attack (int *info_attack, int attack)
{
    if (attack == 1) {
        my_putchar(info_attack[0] + 64);
        my_putchar(info_attack[1] + 48);
        my_putstr(": hit\n\n");
    } else {
        my_putchar(info_attack[0] + 64);
        my_putchar(info_attack[1] + 48);
        my_putstr(": missed\n\n");
    }
}

void printmaps(t_variables **var)
{
    if ((*var)->valuereturn == 0) {
        my_putstr("my positions:\n");
        print_map((*var)->shipsmap);
        my_putstr("enemy's positions:\n");
        print_map((*var)->shipsenemymap);
    }
}

void print_result_battle(t_variables **var)
{
    if ((*var)->my_counter_num_ships == 0 &&
    (*var)->enemy_counter_num_ships != 0) {
        my_putstr("Enemy won\n");
        (*var)->valuereturn = 1;
    } else if ((*var)->enemy_counter_num_ships == 0 &&
    (*var)->my_counter_num_ships != 0) {
        my_putstr("I won\n");
        (*var)->valuereturn = 0;
    } else if ((*var)->my_counter_num_ships == 0 &&
    (*var)->enemy_counter_num_ships == 0)
        my_putstr("Tie\n");
}

void result_connection(t_variables *var, int i)
{
    if (i == 5) {
        my_putstr("timeout or worng pid\n");
        var->valuereturn = 0;
    } else
        my_putstr("successfully connected\n");
}
