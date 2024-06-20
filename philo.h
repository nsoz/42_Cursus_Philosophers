#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct
{
    int eat_cal;
    int philo_count;
    int death_time;
    int eat_time;
    int sleep_time;
    int eat_repeat;
} philo_arg;

typedef struct
{
    int id;
    int eaten;
    philo_arg *args;
    struct timeval last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} philo_id;

int ft_atoi(char *str);
void *ft_routine(void *data);

# endif