/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:43:46 by igbocha3          #+#    #+#             */
/*   Updated: 2022/02/28 10:00:28 by igbocha3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_put_c(char c);
int		ft_put_s(char *s);
int		ft_put_p(unsigned long long p);
int		ft_put_d(int d);
int		ft_put_u(unsigned int u);
int		ft_put_x(long long int x, char c);
int		ft_len_d(long long d);
int		ft_len_x(unsigned long long d);
int		ft_printf(const char *str, ...);

#endif