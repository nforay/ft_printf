/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:53:10 by nforay            #+#    #+#             */
/*   Updated: 2019/12/05 19:59:32 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-214748364", 10);
		n = 8;
	}
	else if (n < 0)
	{
		putchar('-', fd);
		n = -n;
	}
	if (n <= 9 && n >= 0)
		putchar(n + 48, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		putchar(n % 10 + 48, fd);
	}
}
