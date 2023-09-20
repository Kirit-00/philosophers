/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:51:18 by maltun            #+#    #+#             */
/*   Updated: 2023/09/20 03:21:08 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_data *philo, char **av)
{
	
}

int	main(int ac, char **av)
{
	t_data	*philo;

	if (av && ac != 5 && ac != 6)
	{
		write(0, "invalid args\n", 13);
		return (2);
	}
	philo = ft_calloc(sizeof(t_data), 1);
	init_args(philo, av);
	return (0);
}