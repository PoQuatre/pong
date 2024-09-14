/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:16:14 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/14 01:27:31 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "errors.h"
#include "libft.h"
#include "types.h"

t_bool	print_errno(char *prog_name)
{
	int	err;

	err = errno;
	ft_putstr_err(prog_name);
	ft_putstr_err(": error: ");
	ft_putstr_err(strerror(err));
	return (1);
}

t_bool	print_errno_func(char *prog_name, char *func_name)
{
	int	err;

	err = errno;
	ft_putstr_err(prog_name);
	ft_putstr_err(": ");
	ft_putstr_err(func_name);
	ft_putstr_err(" failed (");
	ft_putnbr_err(err);
	ft_putstr_err("): ");
	ft_putstr_err(strerror(err));
	return (1);
}
