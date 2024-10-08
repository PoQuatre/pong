/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:22:47 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/18 11:40:12 by mle-flem         ###   ########.fr       */
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
int		ft_clamp(int val, int min, int max);

#endif
