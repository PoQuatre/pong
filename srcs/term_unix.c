/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_unix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:12:43 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 21:24:21 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termios.h>

#include "term.h"
#include "types.h"

t_term	*init_term(void)
{
	t_term	*term;

	term = malloc(sizeof(t_term));
	if (!term)
		return (NULL);
	tcgetattr(0, term);
	return (term);
}

void	set_term_bit(t_term *term, tcflag_t bit, t_bool state)
{
	if (state)
		term->c_lflag |= bit;
	else
		term->c_lflag &= ~bit;
	tcsetattr(0, TCSANOW, term);
}

void	restore_term(t_term *term)
{
	tcflush(0, TCIFLUSH);
	set_echo_on(term);
	set_canon_on(term);
}
