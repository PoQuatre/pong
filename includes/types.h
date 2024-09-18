/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:06:11 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/18 07:55:35 by mle-flem         ###   ########.fr       */
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
	HANDLE	h_stdin;
	HANDLE	h_stdout;
	DWORD	original;
	DWORD	current;
	int		stdin_size;
	int		cols;
	int		rows;
	int		old_cols;
	int		old_rows;
}	t_term;

# else

typedef struct termios	t_termios;

typedef struct s_term
{
	t_termios	*termios;
	int			stdin_size;
	int			cols;
	int			rows;
	int			old_cols;
	int			old_rows;
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
	int			player_pos;
	int			enemy_pos;
	int			ball_color;
	t_vector	ball_pos;
	t_vector	ball_vel;
}	t_game_state;

#endif
