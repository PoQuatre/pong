/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:53:20 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/14 15:55:52 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ansi.h"
#include "game.h"
#include "game_utils.h"
#include "types.h"

t_game_state	*init_game_state(void)
{
	t_game_state	*state;

	state = malloc(sizeof(t_game_state));
	if (!state)
		return (NULL);
	state->player_score = 0;
	state->enemy_score = 0;
	state->player_position = 0;
	state->enemy_position = 0;
	state->ball_position = malloc(sizeof(t_vector));
	state->ball_velocity = malloc(sizeof(t_vector));
	if (!state->ball_position || !state->ball_velocity)
		return (NULL);
	state->ball_position->x = -1;
	state->ball_position->y = -1;
	state->ball_velocity->x = 0;
	state->ball_velocity->y = 0;
	return (state);
}

void	setup_game_state(t_term *term, t_game_state *state)
{
	state->player_position = term->rows / 2;
	state->enemy_position = state->player_position;
	state->ball_position->x = term->cols / 2;
	state->ball_position->y = state->player_position;
	state->ball_velocity->x = 1;
	state->ball_velocity->y = 1;
}

void	update_game_state(t_term *term, t_game_state *state, double delta)
{
	if (state->ball_position->x == -1 && state->ball_position->y == -1)
		setup_game_state(term, state);
	state->ball_position->x += state->ball_velocity->x;
	state->ball_position->y += state->ball_velocity->y;
	(void) delta;
}

void	draw_game_state(t_term *term, t_game_state *state, double delta)
{
	(void) state;
	(void) delta;
	clear_screen();
	draw_separator(term);
}
