/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:53:13 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/14 15:58:53 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb, char *dest)
{
	char	*ptr;
	int		tmp_nb;

	ptr = dest;
	tmp_nb = nb;
	if (nb == 0)
		*ptr++ = '0';
	else
	{
		while (nb)
		{
			tmp_nb = nb;
			nb /= 10;
			*ptr++ = "9876543210123456789"[9 + (tmp_nb - nb * 10)];
		}
	}
	if (tmp_nb < 0)
		*ptr++ = '-';
	*ptr = '\0';
	ft_strrev(dest);
	return (dest);
}
