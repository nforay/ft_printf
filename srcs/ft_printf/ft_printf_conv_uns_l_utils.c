/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_uns_l_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:06:30 by nforay            #+#    #+#             */
/*   Updated: 2020/03/09 19:12:56 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_conv_base_l(t_state_machine *m, int len,
			unsigned long int nbr, char *base)
{
	if (nbr / ft_strlen(base) != 0)
		len = (ft_conv_base_l(m, len, (nbr / ft_strlen(base)), base));
	return (++len);
}

void	ft_printf_putnbr_base_l(t_state_machine *m, unsigned long int nbr,
			char *base)
{
	if (nbr / 16 != 0)
		ft_printf_putnbr_base_l(m, (nbr / 16), base);
	write(1, base + (nbr % 16), 1);
	m->len++;
}

void	ft_printf_width_uns_l(t_state_machine *m, int len)
{
	int	written;

	written = (m->preci >= len ? m->preci : len);
	if (m->flag & HASH && m->args.lux)
		m->fwidth -= 2;
	while (m->fwidth > written)
	{
		ft_putchar_fd((m->flag & ZERO &&
			!(m->flag & MINUS + POINT)) ? '0' : ' ', 1);
		m->len++;
		written++;
	}
	if (m->flag & ZERO)
		m->flag &= ~ZERO;
}
