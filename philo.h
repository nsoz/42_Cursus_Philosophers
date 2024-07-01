#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				must_eat;
	int				number_of_philo;
	int				total_eaten;
	int				*check_dead;
	t_time			time_to_die;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	t_time			start_time;
	t_time			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int		ft_args_checker(int ac, char **av);
int		ft_check_death(t_philo *philo);
int		ft_wait_time(t_philo *philo, t_time wait_time);
long	ft_atol(const char *str);
t_time	ft_get_time(void);
void	*ft_routine(void *args);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_threads_start(t_philo *philo);
void	ft_initialization(t_philo *philo, int ac, char **av);
void	ft_philo_print(t_philo *philo, char *status, int kill);
void	ft_mutex_init(t_philo *philo, pthread_mutex_t *forks, \
			pthread_mutex_t *death);

#endif
