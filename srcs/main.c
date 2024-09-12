/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:50:19 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/12 23:06:05 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "ansi.h"

void	sigint_handler(int sig)
{
	(void) sig;
	exit_fullscreen();
	exit(0);
}

int	main(void)
{
	enter_fullscreen();
	signal(SIGINT, sigint_handler);
	write(1, "Hello world!", 12);
	while (1)
		sleep(1);
	return (0);
}
