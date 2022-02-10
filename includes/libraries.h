/*
** EPITECH PROJECT, 2021
** Lib_pushswap
** File description:
** pushlib
*/

#ifndef LIBRARIES_H_
    #define LIBRARIES_H_

    #include "./structs.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
    #include <fcntl.h>
    #include <signal.h>
    #define _GNU_SOURCE

extern s_var *global_var;

void wait_attack(t_variables **var);
void draw_enemy_attack(t_variables **var, int *info_attack);
void draw_my_attack(t_variables **var, int *info_attack);
void external_func_attack(t_variables *var, char *buffer, size_t bufsize);
void func_attack(t_variables *var);
void draw_ships(t_variables *var, char **shipsmap, int *info_ship);
void external_save_cordinates(t_variables *var, char *buffer, int len);
int save_cordinates(t_variables *var);
char **matrix_copy(char **matrixdest, char **map);
void create_matrix (char **map);
void killfunction(char *name);
void sigusr1(int num);
void sigusr2(int num);
int pos_to_nbr(int *pos);
int *nbr_to_pos(int nbr);
void nbr_to_bit(int nbr);
int bit_to_nbr(int *nbr);
void send_position(int *position);
void connect(t_variables *var, int i);
void print_map(char **map);
void print_result_attack (int *info_attack, int attack);
void printmaps(t_variables **var);
void print_result_battle(t_variables **var);
void result_connection(t_variables *var, int i);
int my_getnbr(char const *str);
void my_putstr(char const *str);
int my_strlen(char const *str);
long my_put_nbr(long nb);
void my_putchar(char c);
int my_getnbr(char const *str);
char *my_strdup(char *str);
int my_strcmp(const char *s1, const char *s2);
void free_all(t_variables *var, char **map);
void printhelp(void);
int my_isdigit(char c);
int my_ischar(char c);
int check_if_nbr(char *str);
void check_ship_length(t_variables *var, char *str);
void check_pos_info(t_variables *var, char *str);

#endif