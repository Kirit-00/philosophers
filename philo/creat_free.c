/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:01:36 by maltun            #+#    #+#             */
/*   Updated: 2023/10/26 16:46:38 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_philo(t_philo *philo, char **av)
{
	int	i;

	i = 0;
	while (i < (ft_atoll(av[1])))
	{
		pthread_create(&philo[i].thread, NULL, &ft_life_philo, &philo[i]);
		i++;
		usleep(100);
	}
	while (1)
	{
		if (ft_philo_check(philo))
			break ;
	}
	i = 0;
	while (i < (ft_atoll(av[1])))
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

void	ft_init_args(t_philo *philo, int ac, char *av[])
{
	int	*dead;
	int	i;

	i = 0;
	dead = ft_calloc(sizeof(int));
	while (i < ft_atoll(av[1]))
	{
		philo[i].id = i;
		philo[i].total_philo = ft_atoll(av[1]);
		philo[i].die_time = ft_atoll(av[2]);
		philo[i].eat_time = ft_atoll(av[3]);
		philo[i].sleep_time = ft_atoll(av[4]);
		if (ac == 6)
			philo[i].eat_i = ft_atoll(av[5]);
		else
			philo[i].eat_i = -1;
		philo[i].eat_last = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].total_eaten = 0;
		philo[i].dead_check = dead;
		i++;
	}
}

void	create_mutex(t_philo *philo, pthread_mutex_t *forks, \
		pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philo->total_philo)
	{
		philo[i].left_fork_mutex = &forks[i];
		philo[i].right_fork_mutex = &forks[(i + 1) % philo->total_philo];
		i++;
	}
	i = 0;
	while (i < philo->total_philo)
	{
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		philo[i].death = death;
		i++;
	}
	pthread_mutex_init(philo->death, NULL);
}

void	ft_free(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philo->total_philo)
	{
		pthread_mutex_destroy(philo[i].left_fork_mutex);
		pthread_mutex_destroy(philo[i].right_fork_mutex);
		i++;
	}
	pthread_mutex_destroy(philo->death);
	pthread_mutex_destroy(forks);
	free(death);
	free(philo->dead_check);
	free(philo);
}
