/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:59:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/15 11:55:58 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
#define PHILO

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

typedef struct	philo_s
{
	int				nbr_philo;
	unsigned long	tt_die;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned long	nbr_tt_eat;
	int				*id;
	int				alive;
	struct timeval	*last_meal;
	pthread_mutex_t	message;
	pthread_mutex_t	*forks;
	pthread_t		*philo;
	pthread_t		eat_monit;
}				philo_t;


#endif
