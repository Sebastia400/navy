/*
** EPITECH PROJECT, 2021
** function main
** File description:
** func principal main
*/

#include "./../includes/libraries.h"

s_var *global_var = NULL;

int principal_program (t_variables *var)
{
    int *position_recived = malloc(sizeof(int) * 2);

    printmaps(&var);
    while (var->my_counter_num_ships != 0 &&
    var->enemy_counter_num_ships != 0 && var->valuereturn == 0) {
        if (var->argc == 3) {
            wait_attack(&var);
            func_attack(var);
            printmaps(&var);
        } else {
            func_attack(var);
            wait_attack(&var);
            printmaps(&var);
        }
    }
    free (position_recived);
    print_result_battle(&var);
    return (var->valuereturn);
}

void initialize_var (t_variables *var, int argc, char **argv)
{
    var->argc = argc;
    var->argv = argv;
    var->valuereturn = 0;
    var->shipsmap = malloc(sizeof(char *) * 9);
    var->shipsenemymap = malloc(sizeof(char *) * 9);
    var->my_counter_num_ships = 14;
    var->enemy_counter_num_ships = 14;
    global_var->user1_pid = getpid();
    global_var->signal_bit = malloc(sizeof(int) * 17);
    my_putstr("my_pid: ");
    my_put_nbr(global_var->user1_pid);
    my_putstr("\n\n");
}

void fs_open_file(t_variables *var)
{
    if (var->argc == 2)
        var->filename = var->argv[1];
    else if (var->argc == 3) {
        global_var->user2_pid = my_getnbr(var->argv[1]);
        var->filename = var->argv[2];
    }
    if (open(var->filename, O_RDONLY) == -1)
        var->valuereturn = 84;
}

void main2(int argc, char **argv, t_variables *var)
{
    char **map = malloc(sizeof(char *) * 9);
    int i = 0;

    initialize_var(var, argc, argv);
    signal(SIGUSR1, &sigusr1);
    signal(SIGUSR2, &sigusr2);
    fs_open_file(var);
    if (var->valuereturn == 0) {
        connect(var, i);
        create_matrix(map);
        var->shipsmap = matrix_copy(var->shipsmap, map);
        var->shipsenemymap = matrix_copy(var->shipsenemymap, map);
    }
    if (var->valuereturn == 0)
        save_cordinates(var);
    if (var->valuereturn == 0)
        principal_program(var);
    free_all(var, map);
}

int main(int argc, char **argv)
{
    t_variables *var = malloc(sizeof(t_variables));
    global_var = malloc(sizeof(s_var));

    if (argc == 2 || argc == 3) {
        if (my_strcmp(argv[1], "-h") == 0)
            printhelp();
        else
            main2(argc, argv, var);
    } else {
        free(var);
        return (84);
    }
    free(var);
    return (var->valuereturn);
}