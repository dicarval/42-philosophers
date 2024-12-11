/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:13:46 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/11 10:10:39 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(unsigned int id, unsigned int lock)
{
	if (get_uint(&data()->stop_eat) && (alive_protcl()) && lock == 1)
	{
		print_message(id, SLEEP);
		usleep((data()->tt_sleep) * 1000);
	}
	if (get_uint(&data()->stop_eat) && (alive_protcl()) && lock == 1)
	{
		print_message(id, THINK);
		usleep(500);
	}
}

void	eat(unsigned int id, unsigned int lock)
{
	if (get_uint(&data()->stop_eat) && (alive_protcl()) && lock == 1)
	{
		pthread_mutex_lock(&mutex()->last_meal);
		data()->last_meal[id] = get_current_time();
		pthread_mutex_unlock(&mutex()->last_meal);
		pthread_mutex_lock(&mutex()->var_uint);
		(data()->i_tt_eat[id])++;
		pthread_mutex_unlock(&mutex()->var_uint);
		print_message(id, EAT);
		usleep((data()->tt_eat) * 1000);
	}
}
