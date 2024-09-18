/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:53:12 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/14 21:53:55 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_clamp(int val, int min, int max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}
