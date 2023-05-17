/*
** EPITECH PROJECT, 2023
** B-AIA-200-TLS-2-1-n4s-louis.huget
** File description:
** start_n4s
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "n4s.h"

void check_if_end(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (strncmp(tab[i], "Track Cleared", 13) == 0 ||
        strncmp(tab[15], "0.0", 9) == 0) {
            printf("END_SIMULATION\n");
            exit(0);
        }
    }
}

char *exec(char *cmd)
{
    write(1, cmd, strlen(cmd));
    char *rslt;
    size_t size = 0;
    getline(&rslt, &size, stdin);
    if (rslt == NULL || strstr(rslt, "KO") != NULL) {
        if (rslt)
            free(rslt);
        exit(84);
    }
    return rslt;
}

char **insert_idar_tab(char *str)
{
    char **idar_tab = malloc(sizeof(char *) * (strlen(str) + 1));
    strtok(str, ":");
    int i = 0;

    while (str) {
        idar_tab[i] = strdup(str);
        i++;
        str = strtok(NULL, ":");
    }
    return idar_tab;
}
