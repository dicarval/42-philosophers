/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:34:13 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/18 17:44:00 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	elapsed_time_meals(struct timeval last_meal)
{
	unsigned long	elapsed;
	struct timeval	now;

	gettimeofday(&now, NULL);
	elapsed = (now.tv_sec * 1000L + now.tv_usec / 1000) - \
	(last_meal.tv_sec * 1000L + last_meal.tv_usec / 1000);
	printf("%lu\n", elapsed);
	usleep(100);
	return (elapsed);
}

void	*alive(void *arg)
{
	unsigned int	i;

	(void)arg;
	while (1)
	{
		i = 0;
		while (i < data()->nbr_philo)
		{
			if (data()->alive && \
			elapsed_time_meals(data()->last_meal[i]) > data()->tt_die)
			{
				print_message(i, 5);
				data()->alive = 0;
			}
			i++;
		}
		if (!data()->alive)
			break ;
		if (data()->i_tt_eat == (data()->nbr_tt_eat))
			break ;
	}
	return (NULL);
}
