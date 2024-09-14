/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:06:11 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/14 01:47:26 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# ifdef _WIN32
#  include <windows.h>
# else
#  include <termios.h>
# endif

typedef unsigned char	t_bool;

# ifdef _WIN32

typedef struct s_term
{
	HANDLE			h_stdin;
	HANDLE			h_stdout;
	DWORD			original;
	DWORD			current;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	old_cols;
	unsigned int	old_rows;
}	t_term;

# else

typedef struct s_term
{
	struct termios	*termios;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	old_cols;
	unsigned int	old_rows;
}	t_term;

# endif

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_game_state
{
	int			player_score;
	int			enemy_score;
	int			player_position;
	int			player_velocity;
	int			enemy_position;
	int			enemy_velocity;
	t_vector	*ball_position;
	t_vector	*ball_velocity;
}	t_game_state;

#endif
