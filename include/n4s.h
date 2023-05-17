/*
** EPITECH PROJECT, 2023
** B-AIA-200-TLS-2-1-n4s-louis.huget
** File description:
** n4s
*/

#ifndef N4S_H_
    #define N4S_H_

typedef struct n4s_s {
    char lidar_capture[100];
} n4s_t;

    int start_simulation(void);
    void turn_right(int mid);
    void turn_left(int mid);
    void manage_angle(char **tab);
    void manage_speed_high(char **tab);
    int start_n4s(int ac, char **av);
    void check_if_end(char **tab);
    char *exec(char *cmd);
    char **insert_idar_tab(char *str);

#endif /* !N4S_H_ */
