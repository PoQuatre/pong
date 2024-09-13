/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:27:45 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 00:29:07 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>

#include "term.h"

void	set_echo_on(t_term *term)
{
	set_term_bit(term, ECHO, 1);
}

void	set_echo_off(t_term *term)
{
	set_term_bit(term, ECHO, 0);
}

void	set_canon_on(t_term *term)
{
	set_term_bit(term, ICANON, 1);
}

void	set_canon_off(t_term *term)
{
	set_term_bit(term, ICANON, 0);
}
