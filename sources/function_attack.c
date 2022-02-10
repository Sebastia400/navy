/*
** EPITECH PROJECT, 2021
** func. attack
** File description:
** functions needed to attack
*/

#include "./../includes/libraries.h"

void wait_attack (t_variables **var)
{
    int i = 0;
    int *position_recived = malloc(sizeof(int) * 2);
    int n = 0;

    my_putstr("Waiting for enemy's attack...\n");
    while (global_var->signal_count < 16 && n++ != 10000)
        usleep(1000);
    if (global_var->signal_count < 16 && n >= 2000)
        (*var)->valuereturn = 84;
    else {
        i = bit_to_nbr(global_var->signal_bit);
        position_recived = nbr_to_pos(i);
        draw_enemy_attack(var, position_recived);
    }
}

void draw_enemy_attack (t_variables **var, int *info_attack)
{
    int i = info_attack[0] - 1;
    int j = info_attack[1] - 1;

    if ((*var)->shipsmap[j][i] >= '1' && (*var)->shipsmap[j][i] <= '8') {
        (*var)->shipsmap[j][i] = 'x';
        (*var)->my_counter_num_ships--;
        kill(global_var->user2_pid, SIGUSR2);
        print_result_attack(info_attack, 1);
    } else {
        (*var)->shipsmap[j][i] = 'o';
        kill(global_var->user2_pid, SIGUSR1);
        print_result_attack(info_attack, 0);
    }
}

void draw_my_attack (t_variables **var, int *info_attack)
{
    int i = info_attack[0] - 1;
    int j = info_attack[1] - 1;
    int x = 0;

    global_var->signal_count = 0;
    send_position(info_attack);
    while (global_var->signal_count == 0 && x++ != 2000)
        usleep(1000);
    if (global_var->signal_bit[0] && x < 2000) {
        (*var)->shipsenemymap[j][i] = 'x';
        (*var)->enemy_counter_num_ships--;
        print_result_attack(info_attack, 1);
    } else if (x < 2000) {
        (*var)->shipsenemymap[j][i] = 'o';
        print_result_attack(info_attack, 0);
    } else
        (*var)->valuereturn = 84;
    global_var->signal_count = 0;
}

void external_func_attack(t_variables *var, char *buffer, size_t bufsize)
{
    int input_ok = 0;
    int *info_attack = malloc(sizeof(int) * 2);
    int i = 0;

    while (!input_ok && i++ != 2000) {
        my_putstr("Attack: ");
        getline(&buffer, &bufsize, stdin);
        if (buffer[0] >= 65 && buffer[0] <= 72
        && buffer[1] >= 48 && buffer[1] <= 56)
            input_ok = 1;
        else
            my_putstr("Wrong position\n");
        usleep(1000);
    }
    if (i < 2000) {
        info_attack[0] = buffer[0] - 64;
        info_attack[1] = buffer[1] - 48;
        draw_my_attack (&var, info_attack);
    }
    free(info_attack);
}

void func_attack(t_variables *var)
{
    char *buffer;
    size_t bufsize = 32;
    int input_ok = 0;
    int *info_attack = malloc(sizeof(int) * 2);

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        my_putstr("Unable to allocate buffer");
        var->valuereturn = 84;
    }
    if (var->valuereturn == 0)
        external_func_attack(var, buffer, bufsize);
}