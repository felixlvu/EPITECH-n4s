/*
** EPITECH PROJECT, 2023
** B-AIA-200-TLS-2-1-n4s-louis.huget
** File description:
** mouv_manage
*/

#include <stddef.h>
#include <stdio.h>
#include "n4s.h"

void turn_right(int mid)
{
    char *buffer = NULL;
    if (mid >= 0 && mid <= 400) {
        dprintf(1, "%s\n", "wheels_dir:-0.5");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (mid > 400 && mid <= 600) {
        dprintf(1, "%s\n", "wheels_dir:-0.2");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (mid > 600 && mid <= 800) {
        dprintf(1, "%s\n", "wheels_dir:-0.05");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (mid > 800 && mid <= 1000) {
        dprintf(1, "%s\n", "wheels_dir:-0.01");
        getline(&buffer, &(size_t) {0}, stdin);
    }
}

void turn_left(int mid)
{
    char *buffer = NULL;
    if (mid >= 0 && mid <= 400) {
        dprintf(1, "%s\n", "wheels_dir:0.5");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (mid > 400 && mid <= 600) {
        dprintf(1, "%s\n", "wheels_dir:0.2");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (mid > 600 && mid <= 800) {
        dprintf(1, "%s\n", "wheels_dir:0.05");
        getline(&buffer, &(size_t) {0}, stdin);
    }
    if (mid > 800 && mid <= 1000) {
        dprintf(1, "%s\n", "wheels_dir:0.01");
        getline(&buffer, &(size_t) {0}, stdin);
    }
}
