/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:17:12 by juhyelee          #+#    #+#             */
/*   Updated: 2023/12/12 23:29:57 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_T
# define MUTEX_T

# include "data.h"
# include <stdlib.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mutex;
typedef t_mutex			t_fork;

t_fork	*set_forks(const size_t size);
t_mutex	*set_mutex(void);
void	clear_forks(t_fork *forks, const size_t size);

#endif
