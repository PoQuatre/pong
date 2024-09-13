/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:27:45 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 04:44:30 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term.h"

void	set_echo_on(t_term *term)
{
	set_term_bit(term, TERM_ECHO, 1);
}

void	set_echo_off(t_term *term)
{
	set_term_bit(term, TERM_ECHO, 0);
}

void	set_canon_on(t_term *term)
{
	set_term_bit(term, TERM_CANON, 1);
}

void	set_canon_off(t_term *term)
{
	set_term_bit(term, TERM_CANON, 0);
}
