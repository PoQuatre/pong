/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:12:43 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/18 07:57:04 by mle-flem         ###   ########.fr       */
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
	term->h_stdin = GetStdHandle(STD_INPUT_HANDLE);
	term->h_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(term->h_stdin, &term->original);
	term->current = term->original;
	term->cols = 0;
	term->rows = 0;
	return (term);
}

void	set_term_bit(t_term *term, DWORD bit, t_bool state)
{
	if (state)
		term->current |= bit;
	else
		term->current &= ~bit;
	SetConsoleMode(term->h_stdin, term->current);
}

void	flush_term_stdin(t_term *term)
{
	FlushConsoleInputBuffer(term->h_stdin);
}

void	restore_term(t_term *term)
{
	flush_term_stdin(term);
	SetConsoleMode(term->h_stdin, term->original);
}

t_bool	update_term(t_term *term)
{
	CONSOLE_SCREEN_BUFFER_INFO	csbi;
	DWORD						stdin_size;

	GetNumberOfConsoleInputEvents(term->h_stdin, &stdin_size);
	term->stdin_size = stdin_size;
	GetConsoleScreenBufferInfo(term->h_stdout, &csbi);
	term->old_cols = term->cols;
	term->old_rows = term->rows;
	term->cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	term->rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return (1);
}
