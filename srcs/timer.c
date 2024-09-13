/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:23:05 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 04:34:52 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef _WIN32
# include <windows.h>
#else
# include <time.h>
#endif

#include "timer.h"

#ifdef _WIN32

double	get_time_in_seconds(void)
{
	LARGE_INTEGER	freq;
	LARGE_INTEGER	counter;

	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&counter);
	return ((double) counter.QuadPart / freq.QuadPart);
}

#else

double	get_time_in_seconds(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec + ts.tv_nsec * 1e-9);
}

#endif
