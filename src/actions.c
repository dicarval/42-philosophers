/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:13:46 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/26 14:20:23 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(unsigned int id, unsigned int lock)
{
	if (!alive_protcl() && lock == 1)
	{
		print_message(id, 3);
		usleep((data()->tt_sleep) * 1000);
		print_message(id, 4);
		usleep(1000);
	}
}

void	eat(unsigned int id, unsigned int lock)
{
	if (!alive_protcl() && lock == 1)
	{
		pthread_mutex_lock(&mutex()->last_meal);
		data()->last_meal[id] = get_current_time();
		pthread_mutex_unlock(&mutex()->last_meal);
		print_message(id, 2);
		usleep((data()->tt_eat) * 1000);
	}
}
