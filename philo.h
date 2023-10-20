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

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define MUTEX pthread_mutex_t

typedef unsigned long long t_time;

typedef struct s_data
{
	int			id;
	int			philo_number;
	t_time		philo_ttd;
	t_time		philo_tte;
	t_time		philo_tts;
	int			each_time_tte;
	int			total_eaten;
	int			*check_dead;
	t_time		start_time;
	t_time		last_eat_time;
	pthread_t	thread;
	MUTEX		*death;
	MUTEX		*left_fork_mutex;
	MUTEX		*right_fork_mutex;
}	t_data;


int					ft_philo_isdeath(t_data *philo);
void				ft_philo_print(t_data *philo, char *message, int kill);
unsigned long long	ft_get_time(void);
long				ft_atol(char *str);
void				*ft_calloc(size_t count);
int					ft_isnumeric(char *str);
void				ft_error_exit(char *str);

#endif