/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:22:47 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/14 14:08:08 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_getchar(void);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
void	ft_putnbr(int nb);
void	ft_putnbr_err(int nb);
char	*ft_itoa(int nb, char *dest);
char	*ft_strcat(char *dest, char *src);
char	*ft_strrev(char *str);

#endif
