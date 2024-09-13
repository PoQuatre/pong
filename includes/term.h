/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:58:10 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 21:31:37 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H

# ifdef _WIN32
#  include <windows.h>
# else
#  include <termios.h>
# endif

# include "types.h"

t_term	*init_term(void);

# ifdef _WIN32

void	set_term_bit(t_term *term, DWORD bit, t_bool state);

#  define TERM_ECHO ENABLE_ECHO_INPUT
#  define TERM_CANON ENABLE_LINE_INPUT

# else

void	set_term_bit(t_term *term, tcflag_t bit, t_bool state);

#  define TERM_ECHO ECHO
#  define TERM_CANON ICANON

# endif

void	flush_term_stdin(t_term *term);
void	restore_term(t_term *term);

void	set_echo_on(t_term *term);
void	set_echo_off(t_term *term);
void	set_canon_on(t_term *term);
void	set_canon_off(t_term *term);

#endif
