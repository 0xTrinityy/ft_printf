/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:48:02 by tbelleng          #+#    #+#             */
/*   Updated: 2022/11/29 18:45:47 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	which_var(va_list args, const char type)
{
	int	i;

	i = 0;
	if (type == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (type == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (type == '%')
		i += ft_putchar('%');
	else if (type == 'd')
		i += ft_putnbr(va_arg(args, int));
	else if (type == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		i += ft_unsignb(va_arg(args, unsigned int));
	else if (type == 'x')
		i += ft_hexalow(va_arg(args, int));
	else if (type == 'X')
		i += ft_hexaup(va_arg(args, int));
	else if (type == 'p')
		i += ft_adress(va_arg(args, long unsigned int));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, str);
	i = 0;
	printed = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			printed += which_var(args, str[i + 1]);
			i++;
		}
		else
			printed += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
