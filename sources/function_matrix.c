/*
** EPITECH PROJECT, 2021
** function main
** File description:
** functions realted with the saving the map and the ships
*/

#include "./../includes/libraries.h"

void draw_ships(t_variables *var, char **shipsmap, int *info_ship)
{
    int i = info_ship[1] - 1;
    int j = info_ship[2] - 1;
    int k = 0;

    if (info_ship[3] == 0) {
        i += 1;
        j -= 1;
    }
    while (k < info_ship[0]) {
        if (info_ship[3] == 1)
            i++;
        else
            j++;
        if (shipsmap[j][i] != '.') {
            my_putstr("Wrong ships positions");
            var->valuereturn = 83;
        }
        shipsmap[j][i] = info_ship[0] + 48;
        k++;
    }
}

void external_save_cordinates(t_variables *var, char *buffer, int len)
{
    var->valuereturn = 0;
    check_pos_info(var, buffer);
    if (buffer[2] < buffer[5]) {
        if (((buffer[5] - 65) - (buffer[2] - 65)) != buffer[0] - 49) {
            my_putstr("Wrong ships positions");
            var->valuereturn = 82;
        }
        var->hor_ver = 1;
    } else if (buffer[2] > buffer[5]){
        if (((buffer[6] - 48) - (buffer[3] - 48)) != buffer[0] - 49) {
            my_putstr("Wrong ships positions");
            var->valuereturn = 81;
        }
        var->hor_ver = 0;
    } else if ((buffer[0] - 48) != (len + 2)) {
        my_putstr("Wrong ships positions");
        var->valuereturn = 84;
    }
    check_ship_length(var, buffer);
}

int save_cordinates(t_variables *var)
{
    char buffer[8];
    int i = 0;
    int file = open(var->filename, O_RDONLY);
    int *info_ship = malloc(sizeof(int) * 5);

    for (i = 0; i < 4 && var->valuereturn != 84; i++) {
        read(file, buffer, 8);
        external_save_cordinates(var, buffer, i);
        if (var->valuereturn != 0)
            return (var->valuereturn);
        info_ship[0] = buffer[0] - 48;
        info_ship[1] = buffer[2] - 65;
        info_ship[2] = buffer[3] - 48;
        info_ship[3] = var->hor_ver;
        draw_ships(var, var->shipsmap, info_ship);
    }
    free (info_ship);
    close(file);
    return (var->valuereturn);
}

char **matrix_copy(char **matrixdest, char **map)
{
    int i = 0;

    while (i < 8) {
        matrixdest[i] = my_strdup(map[i]);
        i++;
    }
    return (matrixdest);
}

void create_matrix (char **map)
{
    int i = 0;
    int j = 0;

    while (i < 8) {
        map[i] = malloc(sizeof(char)*9);
        j = 0;
        while (j < 8) {
            map[i][j] = '.';
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
}