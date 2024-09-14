/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:23:57 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/14 01:11:25 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

int	ft_getchar(void)
{
	unsigned char	c;
	long			ret;

	ret = read(0, &c, 1);
	if (ret != 1)
		return (-1);
	return (c);
}
