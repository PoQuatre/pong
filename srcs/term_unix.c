/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_unix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:12:43 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 20:34:42 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termios.h>

#include "libft.h"
#include "term.h"
#include "types.h"

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

void	restore_term(t_term *term)
{
	int	c;

	c = ft_getchar();
	while (c != -1)
		c = ft_getchar();
	set_echo_on(term);
	set_canon_on(term);
}
