/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_uns_h_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:50:17 by nforay            #+#    #+#             */
/*   Updated: 2020/03/09 18:54:48 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_conv_base_h(t_state_machine *m, int len,
			unsigned short int nbr, char *base)
{
	if (nbr / ft_strlen(base) != 0)
		len = (ft_conv_base_h(m, len, (nbr / ft_strlen(base)), base));
	return (++len);
}

void	ft_printf_putnbr_base_h(t_state_machine *m,
			unsigned short int nbr, char *base)
{
	if (nbr / 16 != 0)
		ft_printf_putnbr_base_h(m, (nbr / 16), base);
	write(1, base + (nbr % 16), 1);
	m->len++;
}

void	ft_printf_width_uns_h(t_state_machine *m, int len)
{
	int	written;

	written = (m->preci >= len ? m->preci : len);
	if (m->flag & HASH && m->args.hux)
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
