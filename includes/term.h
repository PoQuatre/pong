/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:58:10 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 00:14:09 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H

# include <termios.h>

# include "types.h"

t_term	*init_term(void);
void	set_term_bit(t_term *term, tcflag_t bit, t_bool state);

void	set_echo_on(t_term *term);
void	set_echo_off(t_term *term);
void	set_canon_on(t_term *term);
void	set_canon_off(t_term *term);

#endif
