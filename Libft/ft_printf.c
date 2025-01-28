/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 05:44:10 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/17 17:55:13 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_terminal(va_list args, char func)
{
	int	count;

	count = 0;
	if (func == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (func == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (func == 'd' || func == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (func == 'u')
		count += ft_putuns(va_arg(args, unsigned int));
	else if (func == 'x' || func == 'X')
		count += ft_putitox(va_arg(args, unsigned int), func);
	else if (func == 'p')
		count += ft_putvoid(va_arg(args, void *));
	else if (func == '%')
		count += write (1, "%", 1);
	return (count);
}

int	ft_printf(const char *func, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, func);
	count = 0;
	i = 0;
	while (func[i])
	{
		if (func[i] == '%' && ft_strchr("csdiuxXp%", (func[i + 1])))
		{
			i++;
			count += ft_terminal(args, func[i]);
		}
		else
			count += ft_putchar(func[i]);
		i++;
	}
	va_end(args);
	return (count);
}
