/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:12:43 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 21:22:22 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <windows.h>

#include "term.h"
#include "types.h"

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

void	restore_term(t_term *term)
{
	FlushConsoleInputBuffer(term->handle);
	SetConsoleMode(term->handle, term->original);
}
