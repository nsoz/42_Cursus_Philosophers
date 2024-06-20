#include "philo.h"

void    ft_table_prepair(philo_arg *arguments)
{
    pthread_t   philo[arguments->philo_count];
    pthread_mutex_t   forks[arguments->philo_count];
    philo_id    philo_data[arguments->philo_count];
    int         exst;

    exst = -1;
    while (++exst < arguments->philo_count)
        pthread_mutex_init(&forks[exst], NULL);
    exst = -1;
    while (++exst < arguments->philo_count)
    {

        philo_data[exst].id = exst;
        philo_data[exst].eaten = 0;
        philo_data[exst].args = arguments;
        philo_data[exst].left_fork = &forks[exst];
        philo_data[exst].right_fork = &forks[(exst + 1) % arguments->philo_count];
        pthread_create(&philo[exst], NULL, ft_routine, &philo_data[exst]);
    }
    exst = -1;
    while (++exst < arguments->philo_count)
        pthread_join(philo[exst], NULL);
    exst = -1;
    while (++exst < arguments->philo_count)
        pthread_mutex_destroy(&forks[exst]);
}

int main(int ac, char **av)
{
    philo_arg arguments;

    arguments.eat_repeat = -1;
    if (ac == 6 || ac == 5)
    {
        arguments.eat_cal = 0;
        arguments.philo_count = ft_atoi(av[1]);
        arguments.death_time = ft_atoi(av[2]);
        arguments.eat_time = ft_atoi(av[3]);
        arguments.sleep_time = ft_atoi(av[4]);
        if (ac == 6)
            arguments.eat_repeat = ft_atoi(av[5]);
        ft_table_prepair(&arguments);
    }
    else
        printf("wrong number of arguments\n");
}
