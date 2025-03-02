/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:15:49 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/02 22:00:41 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

int	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("time : %d\n", tv.tv_usec / 200000);
	return (tv.tv_usec / 200000);
}

void	init_fps(t_fps *fps)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	fps->last_frame_time = tv.tv_sec + tv.tv_usec / 1000000.0;
	fps->delta_time = 0.0;
	fps->current_fps = 0.0;
}

void	update_fps(t_fps *fps)
{
	struct timeval	tv;
	double			current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec + tv.tv_usec / 1000000.0;
	fps->delta_time = current_time - fps->last_frame_time;
	fps->last_frame_time = current_time;
}
