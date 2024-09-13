/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:12:43 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 04:45:03 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#ifdef _WIN32
# include <windows.h>
#else
# include <termios.h>
#endif

#include "term.h"
#include "types.h"

#ifdef _WIN32

t_term	*init_term(void)
{
	t_term	*term;

	term = malloc(sizeof(t_term));
	if (!term)
		return (NULL);
	term->handle = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(term->handle, &term->original);
	term->current = term->original;
	return (term);
}

void	set_term_bit(t_term *term, DWORD bit, t_bool state)
{
	if (state)
		term->current |= bit;
	else
		term->current &= ~bit;
	SetConsoleMode(term->handle, term->current);
}

#else

t_term	*init_term(void)
{
	t_term	*term;

	term = malloc(sizeof(t_term));
	if (!term)
		return (NULL);
	tcgetattr(1, term);
	return (term);
}

void	set_term_bit(t_term *term, tcflag_t bit, t_bool state)
{
	if (state)
		term->c_lflag |= bit;
	else
		term->c_lflag &= ~bit;
	tcsetattr(1, TCSANOW, term);
}

#endif
