/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:36:34 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/05 18:36:37 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*data(void)
{
	static t_philo	data;

	return (&data);
}

t_mutex	*mutex(void)
{
	static t_mutex	mutexes;

	return (&mutexes);
}
