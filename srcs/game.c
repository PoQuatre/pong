/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:53:20 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 22:58:59 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "game.h"
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
	state->player_velocity = 0;
	state->enemy_position = 0;
	state->enemy_velocity = 0;
	state->ball_position = malloc(sizeof(t_vector));
	state->ball_velocity = malloc(sizeof(t_vector));
	if (!state->ball_position || !state->ball_velocity)
		return (NULL);
	return (state);
}

void	update_game_state(t_game_state *state, double delta)
{
	(void) state;
	(void) delta;
}

void	draw_game_state(t_game_state *state, double delta)
{
	(void) state;
	(void) delta;
}
