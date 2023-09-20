#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int	philo_number;
	int	philo_ttd;
	int	philo_tte;
	int	philo_tts;
	int	each_time_tte;
}	t_data;

int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);

#endif