/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:34:13 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/04 13:13:59 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Calculates the elapsed time since the last meal*/
unsigned long	elapsed_time_meals(unsigned long last_meal)
{
	unsigned long	elapsed;
	unsigned long	now;

	now = get_current_time();
	elapsed = (now - last_meal);
	return (elapsed);
}

int	alive_protcl(void)
{
	int	condition;

	condition = 0;
	pthread_mutex_lock(&mutex()->is_alive);
	if (data()->alive)
		condition = 1;
	pthread_mutex_unlock(&mutex()->is_alive);
	return (condition);
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
			if (!(stop_eat()))
				break ;
			if ((alive_protcl()) && get_uint(&data()->stop_eat) && \
			elapsed_time_meals(get_last_meal(i)) > data()->tt_die)
			{
				set_uint(&mutex()->is_alive, &data()->alive, 0);
				print_message(i, 5);
				break ;
			}
			i++;
		}
		if (!(alive_protcl()) || !get_uint(&data()->stop_eat))
			break ;
	}
	return (NULL);
}
