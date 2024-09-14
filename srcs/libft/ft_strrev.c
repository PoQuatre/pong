/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:07:30 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/14 15:44:02 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*ptr;
	char	*ptr1;
	char	tmp;

	ptr = str;
	ptr1 = str;
	while (*ptr)
		ptr++;
	ptr--;
	while (ptr1 < ptr)
	{
		tmp = *ptr;
		*ptr-- = *ptr1;
		*ptr1++ = tmp;
	}
	return (str);
}
