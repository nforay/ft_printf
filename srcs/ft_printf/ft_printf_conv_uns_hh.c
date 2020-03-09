#include "main.h"
#include "libft.h"

static int	ft_conv_base(t_state_machine *m, int len, unsigned char nbr, char *base)
{
	if (nbr / ft_strlen(base) != 0)
		len = (ft_conv_base(m, len, (nbr / ft_strlen(base)), base));
	return (++len);
}

static void	ft_putnbr_base(t_state_machine *m, unsigned char nbr, char *base)
{
	if (nbr / 16 != 0)
		ft_putnbr_base(m, (nbr / 16), base);
	write(1, base + (nbr % 16), 1);
	m->len++;
}

static void	print_width_uns(t_state_machine *m, int len)
{
	int	written;

	written = (m->preci >= len ? m->preci : len);
	if (m->flag & HASH && m->args.hhux)
		m->fwidth -= 2;
	while (m->fwidth > written)
	{
		ft_putchar_fd((m->flag & ZERO && !(m->flag & MINUS + POINT)) ? '0' : ' ', 1);
		m->len++;
		written++;
	}
	if (m->flag & ZERO)
		m->flag &= ~ZERO;
}

static void	ft_putunsnbr_fd(t_state_machine *m, unsigned char n, int fd)
{
	if (n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
		m->len++;
	}
	else
	{
		ft_putunsnbr_fd(m, n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
		m->len++;
	}
}

static void	print_hash(t_state_machine *m, int strlen)
{
	if (m->flag & (HASH) && m->args.hhux && !(m->flag & MINUS) && m->flag & POINT)
	{
		print_width_uns(m, strlen);
		ft_putstr_fd((m->flag & XMAJ_CONV) ? "0X" : "0x", m->fd);
		m->len += 2;
	}
	else if (m->flag & HASH && m->args.hhux)
	{
		ft_putstr_fd((m->flag & XMAJ_CONV) ? "0X" : "0x", m->fd);
		m->len += 2;
		if (!(m->flag & MINUS))
			print_width_uns(m, strlen);
	}
	else
	{
		if (!(m->flag & MINUS))
			print_width_uns(m, strlen);
	}
}

void	print_conv_uns_hh(t_state_machine *m)
{
	int	strlen;

	m->preci = (m->preci < 0 ? 0 : m->preci);
	strlen = 0;
	m->args.hhux = (unsigned char)va_arg(m->params, int);
	if (!(m->args.hhux) && m->preci == 0 && m->flag & POINT && m->fwidth == 0)
		return ;
	strlen = ft_conv_base(m, 0, m->args.hhux, (m->flag & U_CONV) ? B_TEN : B_HEX);
	print_hash(m, strlen);
	if (m->flag & POINT && strlen < m->preci)
		while ((m->preci - strlen) > 0)
		{
			ft_putchar_fd('0', m->fd);
			strlen++;
			m->len++;
		}
	if (!(m->args.hhux) && m->preci == 0 && m->flag & POINT)
	{
		ft_putchar_fd(' ', m->fd);
		m->len++;
	}
	else if (m->flag & X_CONV)
		ft_putnbr_base(m, m->args.hhux, B_HEX);
	else if (m->flag & XMAJ_CONV)
		ft_putnbr_base(m, m->args.hhux, B_MHEX);
	else if (m->flag & U_CONV)
		ft_putunsnbr_fd(m, m->args.hhux, m->fd);
	if (m->flag & MINUS)
		print_width_uns(m, strlen);
}
