/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:34:13 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/05 16:51:29 by dicarval         ###   ########.fr       */
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

int	stop_eat(void)
{
	unsigned int	i;
	unsigned int	j;

	if (data()->nbr_tt_eat == 0)
		return (1);
	i = 0;
	j = 0;
	while (i < data()->nbr_philo)
	{
		if (get_uint(&data()->i_tt_eat[i]) == (data()->nbr_tt_eat))
			j++;
		i++;
	}
	if (j == (data()->nbr_philo))
	{
		set_uint(&mutex()->var_uint, &data()->stop_eat, 0);
		return (0);
	}
	else
		return (1);
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
			if ((alive_protcl()) && \
			elapsed_time_meals(get_last_meal(i)) > data()->tt_die)
			{
				set_uint(&mutex()->is_alive, &data()->alive, 0);
				print_message(i, 5);
				break ;
			}
			i++;
		}
		if (!(alive_protcl()))
			break ;
		if (!(data()->stop_eat))
			break ;
	}
	return (NULL);
}
