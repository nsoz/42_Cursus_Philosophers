#include "philo.h"

int ft_eaten_count(philo_id *data)
{
    if (data->eaten == data->args->eat_repeat)
        data->args->eat_cal++;
    return(data->args->eat_cal);
}

void check_death(philo_id *philo_data)
{
    struct timeval current_time;
    long elapsed_time;
    int i;

    i = 0;
    gettimeofday(&current_time, NULL);
    while (i < philo_data->args->philo_count)
    {
        elapsed_time = (current_time.tv_sec - philo_data[i].last_meal.tv_sec) * 1000 + 
                            (current_time.tv_usec - philo_data[i].last_meal.tv_usec) / 1000;
        if (elapsed_time >= philo_data->args->death_time)
        {
            printf("Philosopher %d died\n", philo_data->id);
            exit(0);  // Tüm threadleri sonlandır
        }
        i++;
    }
}

void ft_unlock_forks(philo_id *philo_data)
{
    pthread_mutex_unlock(philo_data->left_fork);
    pthread_mutex_unlock(philo_data->right_fork);
    printf("Philosopher %d is put down the fork\n", philo_data->id);
}

void ft_lock_forks(philo_id *philo_data)
{
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    
    right_fork = philo_data->right_fork;
    left_fork = philo_data->left_fork;
    if (philo_data->id % 2 == 0)
    {
        pthread_mutex_lock(left_fork);
        pthread_mutex_lock(right_fork);
    }
    if (philo_data->id % 2 != 0)
    {
         pthread_mutex_lock(right_fork);
         pthread_mutex_lock(left_fork);
    }
    printf("Philosopher %d is pıck up the forks\n", philo_data->id);
}

void ft_routine_processes(philo_id *philo_data)
{
    while (1)
    {
        printf("Philosopher %d is thinking...\n", philo_data->id);
        ft_lock_forks(philo_data);
        printf("Philosopher %d is eating...\n", philo_data->id);
        gettimeofday(&philo_data->last_meal, NULL); 
        philo_data->eaten++;
        if (ft_eaten_count(philo_data) == philo_data->args->philo_count)
        {
            ft_unlock_forks(philo_data);
            printf("all of them eat %d times\n", philo_data->args->eat_repeat);
            break ;
        }
        usleep(philo_data->args->eat_time);
        ft_unlock_forks(philo_data);
        printf("Philosopher %d is sleeping...\n", philo_data->id);
        usleep(philo_data->args->sleep_time);
        check_death(philo_data);
    }
}

void *ft_routine(void *data)
{
    philo_id *philo_data;
    philo_data = data;
    ft_routine_processes(philo_data);
    return (NULL);
}