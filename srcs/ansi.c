/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:04:02 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/12 23:06:42 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ansi.h"

void	clear_screen(void)
{
	write(1, (char []){0x1b, '[', 'H'}, 3);
}

void	enter_fullscreen(void)
{
	write(1, (char []){0x1b, '[', '?', '1', '0', '4', '9', 'h'}, 8);
	clear_screen();
}

void	exit_fullscreen(void)
{
	write(1, (char []){0x1b, '[', '?', '1', '0', '4', '9', 'l'}, 8);
}
