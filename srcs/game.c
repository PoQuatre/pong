/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:53:20 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/18 11:35:10 by mle-flem         ###   ########.fr       */
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
	state->player_pos = 0;
	state->enemy_pos = 0;
	state->ball_pos.x = -1;
	state->ball_pos.y = -1;
	state->ball_vel.x = 0;
	state->ball_vel.y = 0;
	return (state);
}

void	setup_game_state(t_term *term, t_game_state *state)
{
	state->player_pos = term->rows / 2;
	state->enemy_pos = term->rows / 2;
	state->ball_pos.x = term->cols / 2;
	state->ball_pos.y = term->rows / 2;
	state->ball_vel.x = 1;
	state->ball_vel.y = 1;
}

void	update_game_state(t_term *term, t_game_state *state, double delta)
{
	if (state->ball_pos.x == -1 && state->ball_pos.y == -1)
		setup_game_state(term, state);
	state->ball_pos.x += state->ball_vel.x;
	state->ball_pos.y += state->ball_vel.y;
	(void) delta;
}

void	draw_game_state(t_term *term, t_game_state *state, double delta)
{
	(void) state;
	(void) delta;
	clear_screen();
	draw_separator(term);
}
