/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:59:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/04 10:33:46 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

/*Philo Struct*/
typedef struct s_philo
{
	unsigned int	nbr_philo;
	unsigned long	tt_die;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned int	nbr_tt_eat;
	unsigned int	stop_eat;
	unsigned int	alive;
	unsigned int	*i_tt_eat;
	unsigned int	*id;
	unsigned long	*last_meal;
	pthread_t		*philo;
	pthread_t		eat_monit;
}				t_philo;

/*Mutexes Struct*/
typedef struct s_mutex
{
	pthread_mutex_t	message;
	pthread_mutex_t	*forks;
	pthread_mutex_t	curr_time;
	pthread_mutex_t	var_uint;
	pthread_mutex_t	is_alive;
	pthread_mutex_t	last_meal;
}				t_mutex;

/*Philo struct function*/
t_philo				*data(void);

/*Mutexes struct function*/
t_mutex				*mutex(void);

/*Monitorization if all philosophers are alive*/
void				*alive(void *arg);

/*Checking the alive variable, avoiding threads conflicts*/
int					alive_protcl(void);

/*Checking input and allocation of memory*/
void				av_allocation(char **av);
void				number_max(char *av, int i);
unsigned long long	ft_atoull(const char *str);

/*Program message print*/
void				print_message(int id, int message_code);

/*Access current time*/
unsigned long		get_current_time(void);

/*Reading the variable, avoiding threads conflicts*/
unsigned int		get_uint(unsigned int *var);

/*Writing the variable, avoiding threads conflicts*/
void				set_uint(pthread_mutex_t *mutex, unsigned int *where, \
unsigned int value);

/*Reading the last_meal variable, avoiding threads conflicts*/
unsigned long		get_last_meal(unsigned int i);

/*Eating action*/
void				eat(unsigned int id, unsigned int lock);

/*Sleep and thinking action*/
void				sleep_think(unsigned int id, unsigned int lock);

/*Checking number of times that philosophers have eat*/
int					stop_eat(void);

/*Mutexes initialization*/
void				mutex_init(void);
/*Mutexes elimination*/
void				mutex_destroy(void);

/*Error handle*/
void				error_hand(int error_code);

void				ft_free(void);

#endif
