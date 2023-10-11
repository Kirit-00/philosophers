/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:44:43 by maltun            #+#    #+#             */
/*   Updated: 2023/09/25 20:04:34 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int	philo_number;
	int	philo_ttd;
	int	philo_tte;
	int	philo_tts;
	int	each_time_tte;
	int	use_each_time;
}	t_data;

int		ft_atoi(char *str);
void	*ft_calloc(size_t count);
int		ft_isnumeric(char *str);
void	ft_error_exit(char *str);

#endif