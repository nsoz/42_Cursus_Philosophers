#include "philo.h"

int ft_is_digit(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            return(0);
    return (1);
}

int ft_atoi(char *str)
{
    int ret;
    int i;

    ret = 0;
    i = -1;
    if (!str || !ft_is_digit(str))
        return (-1);
    while (str[++i] != '\0')
    {
        ret *= 10;
        ret += str[i] - '0';
    }
    return(ret);
}
