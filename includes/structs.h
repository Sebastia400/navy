/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_

    typedef struct s_variables {
        int posx;
        int posy;
        int direcction;
        int my_counter_num_ships;
        int enemy_counter_num_ships;
        int hor_ver;
        int argc;
        int valuereturn;
        int *info_ship;
        char *filename;
        char **shipsmap;
        char **shipsenemymap;
        char **argv;
    } t_variables;

    typedef struct t_var {
        int user1_pid;
        int user2_pid;
        int signal_count;
        int *signal_bit;
    } s_var;

    typedef struct func_poiner {
        char op;
        void (*ptr)(char *filepath);
    } calculator;

    typedef struct s_node {
        int data;
        struct s_node *nextPtr;
    } t_node;

#endif
