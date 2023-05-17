/*
** EPITECH PROJECT, 2023
** B-AIA-200-TLS-2-1-n4s-louis.huget
** File description:
** mouv_manage
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "n4s.h"

void manage_angle(char **tab)
{
    float middle = atof(tab[18]);
    float right = atof(tab[34]);
    float left = atof(tab[3]);

    if ((right - left) > 0)
        turn_right(middle);
    else
        turn_left(middle);
}

void manage_speed_low(float radar, char *buffer)
{
    if (radar >= 600 && radar < 700) {
        dprintf(1, "%s", "CAR_FORWARD:0.3\n");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (radar < 600 && radar > 200) {
        dprintf(1, "%s", "CAR_FORWARD:0.2\n");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (radar <= 200) {
        dprintf(1, "%s", "CAR_FORWARD:0.01\n");
        getline(&buffer, &(size_t) {0}, stdin);
    }
}

void manage_speed_high(char **tab)
{
    char *buffer = NULL;
    float radar = atof(tab[18]);

    if (radar >= 1000) {
        dprintf(1, "%s", "CAR_FORWARD:0.8\n");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (radar >= 900 && radar < 1000) {
        dprintf(1, "%s", "CAR_FORWARD:0.6\n");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (radar >= 700 && radar < 900) {
        dprintf(1, "%s", "CAR_FORWARD:0.5\n");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    manage_speed_low(radar, buffer);
}

int start_n4s(int arc, char **arv)
{
    char *str = NULL;
    char **tab = NULL;
    int index = 0;

    exec("START_SIMULATION\n");
    exec("CAR_FORWARD:0.7\n");
    while (1) {
        str = exec("GET_INFO_LIDAR\n");
        tab = insert_idar_tab(str);
        dprintf(2, "%s\n", tab[15]);
        index++;
        check_if_end(tab);
        manage_speed_high(tab);
        manage_angle(tab);
    }
    exec("END_SIMULATION\n");
    return 0;
}
