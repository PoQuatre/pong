/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:50:19 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 22:59:45 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libgen.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ansi.h"
#include "game.h"
#include "libft.h"
#include "term.h"
#include "timer.h"
#include "types.h"

static volatile sig_atomic_t	g_stop = 0;

void	sigint_handler(int sig)
{
	(void) sig;
	g_stop = 1;
}

t_bool	print_errno(char *prog_name)
{
	ft_putstr_err(prog_name);
	ft_putstr_err(": error: ");
	ft_putstr_err(strerror(errno));
	return (1);
}

t_bool	start_game(char *prog_name, t_term **term, t_game_state **game_state)
{
	*term = init_term();
	if (!*term && print_errno(prog_name))
		return (0);
	*game_state = init_game_state();
	if (!*game_state && print_errno(prog_name))
		return (0);
	set_echo_off(*term);
	set_canon_off(*term);
	enter_fullscreen();
	return (1);
}

void	stop_game(t_term *term, t_game_state *game_state)
{
	exit_fullscreen();
	restore_term(term);
	free(term);
	free(game_state->ball_position);
	free(game_state->ball_velocity);
	free(game_state);
}

int	main(int ac, char **av)
{
	t_term			*term;
	t_game_state	*state;
	double			start;
	double			end;

	(void) ac;
	signal(SIGINT, sigint_handler);
	if (!start_game(basename(av[0]), &term, &state))
		return (1);
	start = get_time_in_seconds();
	while (!g_stop)
	{
		end = get_time_in_seconds();
		printf("Time between iterations: %.9f seconds\n", end - start);
		update_game_state(state, end - start);
		draw_game_state(state, end - start);
		flush_term_stdin(term);
		sleep(1);
		start = end;
	}
	stop_game(term, state);
	return (0);
}
