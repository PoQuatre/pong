/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_unix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:12:43 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/18 07:57:00 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>

#include "term.h"
#include "types.h"

t_term	*init_term(void)
{
	t_term	*term;

	term = malloc(sizeof(t_term));
	if (!term)
		return (NULL);
	term->cols = 0;
	term->rows = 0;
	term->termios = malloc(sizeof(struct termios));
	if (!term->termios)
		return (NULL);
	tcgetattr(0, term->termios);
	return (term);
}

void	set_term_bit(t_term *term, tcflag_t bit, t_bool state)
{
	if (state)
		term->termios->c_lflag |= bit;
	else
		term->termios->c_lflag &= ~bit;
	tcsetattr(0, TCSANOW, term->termios);
}

void	flush_term_stdin(t_term *term)
{
	(void) term;
	tcflush(0, TCIFLUSH);
}

void	restore_term(t_term *term)
{
	flush_term_stdin(term);
	set_echo_on(term);
	set_canon_on(term);
}

t_bool	update_term(t_term *term)
{
	struct winsize	w;
	int				stdin_size;

	ioctl(0, FIONREAD, &stdin_size);
	term->cols = stdin_size;
	ioctl(0, TIOCGWINSZ, &w);
	term->old_cols = term->cols;
	term->old_rows = term->rows;
	term->cols = w.ws_col;
	term->rows = w.ws_row;
	return (1);
}
