/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:53:23 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/18 11:29:40 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"
#include "libft.h"
#include "types.h"

void	draw_separator(t_term *term)
{
	int		i;
	char	ansi[32];

	i = 0;
	ansi[0] = '\0';
	ft_strcat(ansi, "[0;");
	ft_itoa(term->cols / 2, &ansi[ft_strlen(ansi)]);
	ft_strcat(ansi, "H");
	ft_putstr(ansi);
	while (i++ < term->rows)
		ft_putstr("[90m╏[0m[B[D");
}

void	draw_ball(t_game_state *state)
{
	char	ansi[32];

	ansi[0] = '\0';
	ft_strcat(ansi, "[");
	ft_itoa(state->ball_pos.y, &ansi[ft_strlen(ansi)]);
	ft_strcat(ansi, ";");
	ft_itoa(state->ball_pos.x, &ansi[ft_strlen(ansi)]);
	ft_strcat(ansi, "H[37m██[0m");
	ft_putstr(ansi);
}
