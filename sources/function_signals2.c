/*
** EPITECH PROJECT, 2021
** func. signals2
** File description:
** functions needed to signal part 2
*/

#include "./../includes/libraries.h"

void nbr_to_bit(int nbr)
{
    int bit[17] = {32768, 16384, 8192, 4096, 2048, 1024, 512,
    256, 128, 64, 32, 16, 8, 4, 2, 1};
    int i = 0;

    while (i < 17) {
        if (nbr >= bit[i]) {
            kill(global_var->user2_pid, SIGUSR2);
            nbr -= bit[i];
        } else {
            kill(global_var->user2_pid, SIGUSR1);
        }
        i++;
        usleep(50000);
    }
}

int bit_to_nbr(int *nbr)
{
    int bit[17] = {32768, 16384, 8192, 4096, 2048, 1024, 512,
    256, 128, 64, 32, 16, 8, 4, 2, 1};
    int i = 0;
    int result = 0;

    while (i < 17) {
        result += bit[i] * nbr[i];
        i++;
    }
    free(global_var->signal_bit);
    global_var->signal_bit = malloc(sizeof(int) * 16);
    global_var->signal_count = 0;
    return result;
}

void send_position(int *position)
{
    int nbr_pos = pos_to_nbr(position);
    nbr_to_bit(nbr_pos);
}

void connect(t_variables *var, int i)
{
    if (var->argc < 3) {
        my_putstr("waiting for enemy connection...\n\n");
        while (global_var->signal_count < 16 && i++ != 2000)
            usleep(10000);
        global_var->user2_pid = bit_to_nbr(global_var->signal_bit);
        kill(global_var->user2_pid, SIGUSR2);
        my_putstr("enemy connected\n\n");
    } else if (var->argc >= 3) {
        if (check_if_nbr(var->argv[1]))
            var->valuereturn = 84;
        else {
            i = 0;
            global_var->user2_pid = my_getnbr(var->argv[1]);
            nbr_to_bit(global_var->user1_pid);
            while (global_var->signal_count == 0 && i++ != 5)
                usleep(1000000);
            result_connection(var, i);
            global_var->signal_count = 0;
        }
    }
}