/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:50:19 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 04:37:19 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "ansi.h"
#include "term.h"
#include "types.h"

static volatile sig_atomic_t	g_stop = 0;

void	sigint_handler(int sig)
{
	(void) sig;
	g_stop = 1;
}

int	main(void)
{
	t_term	*term;

	signal(SIGINT, sigint_handler);
	term = init_term();
	set_echo_off(term);
	set_canon_off(term);
	enter_fullscreen();
	while (!g_stop)
		sleep(1);
	exit_fullscreen();
	free(term);
	return (0);
}
