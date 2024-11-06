/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:59:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/06 16:50:53 by dicarval         ###   ########.fr       */
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
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				nbr_tt_eat;
	int				dead_philo;
	int				*id;
	pthread_mutex_t	message;
	pthread_mutex_t	*forks;
	pthread_t		*philo;
}				philo_t;


#endif
