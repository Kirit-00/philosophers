/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:51:18 by maltun            #+#    #+#             */
/*   Updated: 2023/09/25 20:07:17 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_data *philo, char **av, int ac)
{
	int	i;
	int	*check_dead;

	i = 0;
	while (++i < ac)
		if (!ft_isnumeric(av[i]))
			ft_error_exit("Error : malformed argument");
	i = 0;
	check_dead = ft_calloc(sizeof(int));
	while (i < ft_atol(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].philo_number = ft_atol(av[1]);
		philo[i].philo_ttd = ft_atol(av[2]);
		philo[i].philo_tte = ft_atol(av[3]);
		philo[i].philo_tts = ft_atol(av[4]);
		if (ac == 6)
			philo[i].each_time_tte = ft_atol(av[5]);
		else
			philo[i].each_time_tte = -1;
		philo[i].start_time = ft_get_time();
		philo[i].total_eaten = 0;
		philo[i].last_eat_time = ft_get_time();
		philo[i].check_dead = check_dead;
		i++;
	}
}

void	init_mutex(t_data *philo, MUTEX *forks, MUTEX *death)
{
	long long	i;

	i = 0;
	while (i < philo->philo_number)
	{
		philo[i].right_fork_mutex = &forks[i];
		if (i == philo->philo_number)
			philo[i].left_fork_mutex = &forks[0];
		else
			philo[i].left_fork_mutex = &forks[i + 1];
		i++;
	}
	i = 0;
	while (i < philo->philo_number)
	{
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		philo[i].death = death;
		i++;
	}
	pthread_mutex_init(philo->death, NULL);
}

void	ft_philo_print(t_data *philo, char *message, int kill)
{
	pthread_mutex_lock(philo->death);
	if (!*philo->check_dead)
	{
		printf("%llu %d %s\n", (ft_get_time() - philo->start_time), philo->id, message);
		if (kill)
			*philo->check_dead = 1;
	}
	pthread_mutex_unlock(philo->death);
	ft_philo_isdeath(philo);
}

int	ft_philo_isdeath(t_data *philo)
{
	if (philo->total_eaten == philo->each_time_tte)
		return (1);
	pthread_mutex_lock(philo->death);
	if (*philo->check_dead && printf("bura2\n"))
	{
		pthread_mutex_unlock(philo->death);
		return (1);
	}
	pthread_mutex_unlock(philo->death);
	if (ft_get_time() - philo->last_eat_time > philo->philo_ttd)
	{
		ft_philo_print(philo, "died", 1);
		return (1);
	}
	return (0);
}

int	ft_philo_wait(t_data *philo, t_time wait_time)
{
	t_time	start;

	start = ft_get_time();
	while (ft_get_time() - start < wait_time)
	{
		if (ft_philo_isdeath(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

void	ft_philo_think(t_data *philo)
{
	if (ft_philo_isdeath(philo))
		return ;
	ft_philo_print(philo, "is thinking", 0);
}

void	ft_philo_sleep(t_data *philo)
{
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	if (ft_philo_isdeath(philo))
		return ;
	ft_philo_print(philo, "is sleeping", 0);
	ft_philo_wait(philo, philo->philo_tts);
}

void	ft_philo_eat(t_data *philo)
{
	if (ft_philo_isdeath(philo))
		return ;
	pthread_mutex_lock(philo->left_fork_mutex);
	pthread_mutex_lock(philo->right_fork_mutex);
	ft_philo_print(philo, "has taken a fork", 0);
	ft_philo_print(philo, "has taken a fork ", 0);
	ft_philo_print(philo, "is eating", 0);
	pthread_mutex_lock(philo->death);
	philo->total_eaten++;
	philo->last_eat_time = ft_get_time();
	pthread_mutex_unlock(philo->death);
	ft_philo_wait(philo, philo->philo_tte);
	if (ft_philo_isdeath(philo))
		return ;
}

void	*ft_life_philo(void *arg)
{
	t_data	*philo;

	philo = (t_data *)arg;
	if (philo->philo_number == 1 && !ft_philo_isdeath(philo))
	{
		if (pthread_mutex_lock(philo->left_fork_mutex))
			return (NULL);
		ft_philo_print(philo, " has taken a fork", 0);
		while (!ft_philo_isdeath(philo))
		{
		}
		pthread_mutex_unlock(philo->left_fork_mutex);
	}
	else
	{
		while (1)
		{
			if (ft_philo_isdeath(philo))
				break ;
			ft_philo_eat(philo);
			ft_philo_sleep(philo);
			ft_philo_think(philo);
		}
		return (NULL);
	}
	return (NULL);
}


void	init_threads(t_data *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_number)
	{
		pthread_create(&philo[i].thread, NULL, &ft_life_philo, &philo[i]);
		i++;
		usleep(100);
	}
	i = 0;
	while (i < philo->philo_number)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	while ((*philo).check_dead == 0)
		ft_philo_isdeath(philo);
}

void	ft_free(t_data *philo, MUTEX *forks, MUTEX *death)
{
	int	i;

	i = 0;
	while (i < philo->philo_number)
	{
		pthread_mutex_destroy(philo[i].left_fork_mutex);
		pthread_mutex_destroy(philo[i].right_fork_mutex);
		i++;
	}
	pthread_mutex_destroy(philo->death);
	pthread_mutex_destroy(forks);
	free(death);
	free(philo->check_dead);
	free(philo);
}

int	main(int ac, char **av)
{
	t_data	*philo;
	MUTEX	*forks;
	MUTEX	*death;

	if (av && ac != 5 && ac != 6)
		ft_error_exit("Error : missing or more arguments");
	philo = ft_calloc(sizeof(t_data) * ft_atol(av[1]));
	forks = ft_calloc(sizeof(MUTEX) * ft_atol(av[1]));
	death = ft_calloc(sizeof(MUTEX));
	init_args(philo, av, ac);
	init_mutex(philo, forks, death);
	init_threads(philo);
	ft_free(philo, forks, death);
	return (0);
}
