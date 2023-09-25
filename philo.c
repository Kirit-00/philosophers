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

	i = 1;
	while (i < ac)
	{
		if (!ft_isnumeric(av[i]))
			ft_error_exit("Error : malformed argument");
		i++;
	}
	philo->philo_number = ft_atoi(av[1]);
	philo->philo_ttd = ft_atoi(av[2]);
	philo->philo_tte = ft_atoi(av[3]);
	philo->philo_tts = ft_atoi(av[4]);
	philo->each_time_tte = ft_atoi(av[5]);
}

void	ft_print_args(t_data *philo)
{
	printf("philo_number  %d\n", philo->philo_number);
	printf("philo_ttd     %d\n", philo->philo_ttd);
	printf("philo_tte     %d\n", philo->philo_tte);
	printf("philo_tts     %d\n", philo->philo_tts);
	printf("each_time_tte %d\n", philo->each_time_tte);
}

int	main(int ac, char **av)
{
	t_data	*philo;

	if (av && ac != 5 && ac != 6)
		ft_error_exit("Error : missing or more arguments");
	philo = ft_calloc(sizeof(t_data));
	init_args(philo, av, ac);
	ft_print_args(philo);
	return (0);
}
