/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:50:19 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 20:30:18 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ansi.h"
#include "term.h"
#include "timer.h"
#include "types.h"

static volatile sig_atomic_t	g_stop = 0;

void	sigint_handler(int sig)
{
	(void) sig;
	g_stop = 1;
}

int	main(void)
{
	t_term			*term;
	double			start;
	double			end;

	signal(SIGINT, sigint_handler);
	term = init_term();
	set_echo_off(term);
	set_canon_off(term);
	enter_fullscreen();
	start = get_time_in_seconds();
	while (!g_stop)
	{
		end = get_time_in_seconds();
		printf("Time between iterations: %.9f seconds\n", end - start);
		sleep(1);
		start = end;
	}
	exit_fullscreen();
	restore_term(term);
	free(term);
	return (0);
}
