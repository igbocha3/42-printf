/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:51:21 by igbocha3          #+#    #+#             */
/*   Updated: 2022/02/28 10:08:59 by igbocha3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Значение указателя

#include "ft_printf.h"

void	ft_put_px(unsigned long long p)
{
	if (p >= 16)
		ft_put_px(p / 16);
	ft_put_c("0123456789abcdef"[p % 16]);
}

int	ft_put_p(unsigned long long p)
{
	ft_put_s("0x");
	ft_put_px(p);
	return (ft_len_x(p));
}
