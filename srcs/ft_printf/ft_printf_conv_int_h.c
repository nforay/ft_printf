#include "main.h"
#include "libft.h"

static int		get_intlen_h(short int n, int len)
{
	if (n < -32767)
		return (5);
	if (n <= 0)
		n = -n;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	print_int(short int n, t_state_machine *m)
{
	if (n < -32767)
	{
		ft_putstr_fd("3276", m->fd);
		m->fwidth -= 18;
		m->len += 18;
		n = 7;
	}
	if (n <= 9 && n >= 0)
	{
		ft_putchar_fd(n + 48, m->fd);
		m->len++;
		m->fwidth--;
	}
	else
	{
		print_int(n / 10, m);
		ft_putchar_fd(n % 10 + 48, m->fd);
		m->len++;
		m->fwidth--;
	}
}

static void	print_nbr_fd(short int n, int size, t_state_machine *m)
{
	if (n < 0)
		n *= -1;
	while ((m->preci - size) > 0)
	{
		ft_putchar_fd('0', 1);
		m->len++;
		m->preci--;
		m->fwidth--;
	}
	print_int(n, m);
}

static void	print_width_int(t_state_machine *m)
{
	if (m->flag & (PLUS + SPACE) && m->args.hd >= 0)
		m->fwidth--;
	if (!(m->flag & MINUS))
		while (m->fwidth && (m->fwidth - 1 > m->preci))
		{
			ft_putchar_fd(m->flag & ZERO ? '0' : ' ', 1);
			m->len++;
			m->fwidth--;
		}
	if (m->fwidth - m->preci > 0 && !(m->flag & MINUS))
	{
		if (m->args.hd < 0 && m->flag & ZERO)
			ft_putchar_fd('0', m->fd);
		else if (m->flag & ZERO)
			ft_putchar_fd((m->args.hd < 0) ? '-' : '0', m->fd);
		else
			ft_putchar_fd((m->args.hd < 0) ? '-' : ' ', m->fd);
		m->fwidth--;
		m->len++;
	}
	if (m->flag & MINUS && m->args.hd < 0)
	{
		ft_putchar_fd('-', m->fd);
		m->fwidth--;
		m->len++;
	}
}

static void	print_width_int_empty(t_state_machine *m)
{
	if (m->flag & (PLUS + SPACE))
	{
		m->fwidth--;
		if (m->flag & MINUS)
		{
			ft_putchar_fd((m->flag & PLUS) ? '+' : ' ', m->fd);
			m->len++;
		}
	}
	while (m->fwidth > 0)
	{
		ft_putchar_fd(' ', 1);
		m->len++;
		m->fwidth--;
	}
	if (!(m->flag & MINUS) && m->flag & (PLUS + SPACE) && m->args.hd >= 0)
	{
		ft_putchar_fd((m->flag & PLUS) ? '+' : ' ', m->fd);
		m->len++;
	}
}

static void	print_hash(t_state_machine *m)
{
	if (m->flag & ZERO)
	{
		if (m->flag & (PLUS + SPACE) && m->args.hd >= 0)
		{
			ft_putchar_fd((m->flag & PLUS) ? '+' : ' ', m->fd);
			m->len++;
		}
		print_width_int(m);
	}
	else
	{
		print_width_int(m);
		if (m->flag & (PLUS + SPACE) && m->args.hd >= 0)
		{
			ft_putchar_fd((m->flag & PLUS) ? '+' : ' ', m->fd);
			m->len++;
		}
	}
}

void	print_conv_int_h(t_state_machine *m)
{
	int	size;

	m->args.hd = (short int)va_arg(m->params, int);
	if (!(m->args.hd) && m->flag & POINT && (!(m->preci) || m->preci == -1))
	{
		print_width_int_empty(m);
		return ;
	}
	size = get_intlen_h(m->args.hd, 1);
	if (m->flag & ZERO && (m->flag & POINT || m->flag & MINUS))
		m->flag &= ~ZERO;
	m->preci = (m->preci < size ? size : m->preci);
	m->fwidth = (m->fwidth < m->preci ? m->preci : m->fwidth);
	if ((m->fwidth == m->preci) && m->args.hd < 0)
		m->fwidth = m->preci + 1;
	if (m->args.hd < 0 && m->flag & ZERO)
	{
		ft_putchar_fd('-', m->fd);
		m->len++;
		m->fwidth--;
	}
	print_hash(m);
	print_nbr_fd(m->args.hd, size, m);
	while (m->fwidth > 0)
	{
		ft_putchar_fd(' ', 1);
		m->len++;
		m->fwidth--;
	}
}
