/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:06:11 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/13 04:45:19 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# ifdef _WIN32
#  include <windows.h>
# else
#  include <termios.h>
# endif

typedef unsigned char	t_bool;

# ifdef _WIN32

typedef struct s_term
{
	HANDLE	handle;
	DWORD	original;
	DWORD	current;
}	t_term;

# else

typedef struct termios	t_term;

# endif

#endif
