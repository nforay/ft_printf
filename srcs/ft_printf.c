/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:09:48 by nforay            #+#    #+#             */
/*   Updated: 2020/02/23 18:52:15 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	parse(const char c)
{
	(void) c;
}

int		ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	j;
	//t_args	*args;

	va_list params;
	va_start(params, format);
	i = 0;
	j = 0;
	//args = NULL;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			j++;
			i++;
			continue;
		}
		if (format[i] && format[(i + 1 )] == '%')
		{
			ft_putchar_fd('%', 1);
			i += 2;
		}
		if (format[i] && (format[(i + 1)] == 'd' || format[(i + 1)] == 'i'))
		{
			//args->d = (int)va_arg(params, int);
			ft_putnbr_fd((int)va_arg(params, int), 1);
			i += 2;
		}
		if (format[i] && format[(i + 1)] == 'c')
		{
			ft_putchar_fd((int)va_arg(params, int), 1);
			i += 2;
		}
		if (format[i] && format[(i + 1)] == 's')
		{
			ft_putstr_fd((char*)va_arg(params, char*), 1);
			i += 2;
		}
	}
	va_end(params);
	return (j);
}

