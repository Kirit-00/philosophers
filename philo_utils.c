/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 03:11:28 by maltun            #+#    #+#             */
/*   Updated: 2023/09/25 20:07:29 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count)
{
	void	*start;
	void	*ret;

	ret = malloc(count);
	start = ret;
	if (!ret)
		return (0);
	while (count--)
		*(unsigned char *)ret++ = 0;
	return (start);
}

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	neg;
	long	i;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

t_time	ft_get_time(void)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	ft_error_exit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		write(2, &str[i++], 1);
	write(2, "\n", 1);
	exit(2);
}
