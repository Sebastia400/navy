/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** Copy a string.
*/

#include <unistd.h>
#include <stdlib.h>
#include "./../../includes/libraries.h"

char *my_strdup(char *str)
{
    char *result = malloc(my_strlen(str) + 1);
    int i = 0;

    while (str[i] != '\0') {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}