/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:32:44 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 22:45:32 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "types.h"

t_game_state	*init_game_state(void);
void			update_game_state(t_term *term, t_game_state *state,
					double delta);
void			draw_game_state(t_term *term, t_game_state *state,
					double delta);

#endif
