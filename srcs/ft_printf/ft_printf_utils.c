#include "main.h"
#include "libft.h"

int			intlen(int n, int len)
{
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void		print_nbr_fd(int n, t_state_machine *m)
{
	if (n == -2147483648)
	{
		write(m->fd, "-214748364", 10);
		n = 8;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', m->fd);
		n = -n;
	}
	while (m->preci && intlen(m->args.d, (m->args.d < 0 ? 0 : 1)) <= m->preci--)
	{
		ft_putchar_fd('0', 1);
		m->len++;
	}
	if (n <= 9 && n >= 0)
		ft_putchar_fd(n + 48, m->fd);
	else
	{
		print_nbr_fd(n / 10, m);
		ft_putchar_fd(n % 10 + 48, m->fd);
	}
}

void	print_width(t_state_machine *m)
{
	if (m->fwidth)
	{
		if ((m->flag & S_CONV) && m->args.s && ((int)ft_strlen(m->args.s) <= m->fwidth))
			if (m->flag & POINT && m->preci < (int)ft_strlen(m->args.s))
				m->fwidth = (m->fwidth - m->preci);
			else
				m->fwidth = (m->fwidth - (int)ft_strlen(m->args.s));
		else if ((m->flag & S_CONV) && m->args.s && ((int)ft_strlen(m->args.s) > m->fwidth))
			if (m->flag & POINT)
				m->fwidth = (m->fwidth - m->preci);
			else
				m->fwidth = 0;
		else if (m->flag & C_CONV)
			m->len += (m->fwidth - 1);
		else if (m->flag & PER_CONV)
			m->fwidth--;
		while (m->fwidth > 0 && m->fwidth--)
		{
			ft_putchar_fd(m->flag & ZERO && !(m->flag & MINUS) ? '0' : ' ', 1);
			m->len++;
		}
	}
}

void	print_perc(t_state_machine *m)
{
	if (m->flag & PER_CONV)
	{
		if (!(m->flag & MINUS))
			print_width(m);
		ft_putchar_fd('%', 1);
		m->len++;
		if (m->flag & MINUS)
			print_width(m);
	}
}

void	print_conv(t_state_machine *m)
{
	if (!(m->flag & MINUS) && (m->flag & C_CONV))
		print_width(m);
	if (m->flag & C_CONV)
		print_conv_chr(m);
	else if (m->flag & S_CONV)
		print_conv_str(m);
	else if (m->flag & P_CONV)
		print_conv_ptr(m);
	else if (m->flag & (D_CONV | I_CONV))
		print_conv_int(m);
	else if (m->flag & (U_CONV | X_CONV | XMAJ_CONV))
		print_conv_uns(m);
}

void	ft_putnbr_base(t_state_machine *m, unsigned int nbr, char *base)
{
	if (nbr / 16 != 0)
		ft_putnbr_base(m, (nbr / 16), base);
	write(1, base + (nbr % 16), 1);
	m->len++;
}

void	ft_put_pointer(t_state_machine *m, unsigned long nbr, char *base)
{
	if (nbr / 16 != 0)
		ft_put_pointer(m, (nbr / 16), base);
	write(1, base + (nbr % 16), 1);
	m->len++;
}

void	print_conv_str(t_state_machine *m)
{
	m->args.s = (char *)va_arg(m->params, char *);
	if (!(m->args.s))
		m->args.s = "(null)";
	if (!(m->flag & MINUS) && (m->fwidth > 0))
		print_width(m);
	if (m->flag & POINT)
		while (m->preci > 0 && m->preci-- && *m->args.s)
		{
			ft_putchar_fd(*m->args.s++, 1);
			if (m->fwidth != 0)
				m->fwidth--;
			m->len++;
		}
	else
	{
		ft_putstr_fd(m->args.s, 1);
		m->len += ft_strlen(m->args.s);
	}
	if (m->flag & MINUS)
		print_width(m);
}

void	print_conv_int(t_state_machine *m)
{
	size_t	len;

	m->args.d = (int)va_arg(m->params, int);
	if (m->flag & POINT && m->args.d == 0)
		return ;
	len = intlen(m->args.d, 0);
	if (!(m->flag & MINUS))
	{
		m->fwidth -= len;
		print_width(m);
	}
	m->len += len;
	print_nbr_fd(m->args.d, m);
	if (!(m->flag & MINUS) || m->fwidth == (int)len)
		return ;
	if (m->flag & MINUS && (int)len < m->fwidth)
	{
		m->fwidth -= len;
		print_width(m);
	}
	m->fwidth = 0;
}

void	print_conv_chr(t_state_machine *m)
{
	m->args.c = (int)va_arg(m->params, int);
	ft_putchar_fd(m->args.c, 1);
	m->len++;
}

void	print_conv_uns(t_state_machine *m)
{
	m->args.x = (unsigned int)va_arg(m->params, unsigned int);
	if (m->flag & HASH)
	{
		ft_putstr_fd("0x", 1);
		m->len += 2;
	}
	if (m->flag & X_CONV)
		ft_putnbr_base(m, m->args.x, "0123456789abcdef");
	else if (m->flag & XMAJ_CONV)
		ft_putnbr_base(m, m->args.x, "0123456789ABCDEF");
	else
		ft_putnbr_fd(m->args.x, 1);
}

void	print_conv_ptr(t_state_machine *m)
{
	m->args.p = (unsigned long)va_arg(m->params, unsigned long);
	ft_putstr_fd("0x", 1);
	m->len += 2;
	ft_put_pointer(m, m->args.p, "0123456789abcdef");
}

void	extract_aste(t_state_machine *m)
{
	if (m->flag & POINT)
		m->preci = (int)va_arg(m->params, int);
	else
	{
		m->fwidth = (int)va_arg(m->params, int);
		if (m->fwidth < 0)
		{
			m->fwidth *= -1;
			m->flag |= MINUS;
		}
	}
	if (m->preci < 0)
		m->preci = 0;
	m->flag &= ~ASTER;
}
