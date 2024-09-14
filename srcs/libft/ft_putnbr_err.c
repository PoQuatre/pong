/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:10:58 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/14 01:13:29 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putnbr_err(int nb)
{
	long	l_nb;

	l_nb = nb;
	if (l_nb < 0)
	{
		write(2, "-", 1);
		l_nb = -l_nb;
	}
	if (l_nb >= 10)
		ft_putnbr_err(l_nb / 10);
	write(2, &"0123456789"[l_nb % 10], 1);
}
