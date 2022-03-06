/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:47:52 by igbocha3          #+#    #+#             */
/*   Updated: 2022/02/28 10:07:46 by igbocha3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Записывает в поток stdout свои аргументы в соответствии с форматной строкой

#include "ft_printf.h"

static void	specifier(char str, int *len, va_list arg)
{
	if (str == 'd' || str == 'i')
		*len = *len + ft_put_d(va_arg(arg, int)) - 2;
	else if (str == 'c')
	{
		ft_put_c(va_arg(arg, int));
		*len = *len - 1;
	}
	else if (str == 's')
		*len = *len + ft_put_s(va_arg(arg, char *)) - 2;
	else if (str == 'p')
		*len = *len + ft_put_p(va_arg(arg, unsigned long long));
	else if (str == 'x' || str == 'X')
		*len = *len + ft_put_x(va_arg(arg, unsigned int), str) - 2;
	else if (str == 'u')
		*len = *len + ft_put_u(va_arg(arg, unsigned int)) - 2;
	else if (str == '%')
	{
		*len = *len - 1;
		ft_put_c('%');
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	if (!*str)
		return (0);
	while (str[len])
		len++;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] != '\0')
				specifier(str[i++], &len, arg);
		}
		if (str[i] != '%' && str[i])
			ft_put_c(str[i++]);
	}
	va_end(arg);
	return (len);
}
