#include "main.h"
#include "libft.h"

int		get_intlen(int n, int len)
{
	if (n <= 0)
		n = -n;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	print_int(int n, t_state_machine *m)
{
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

void	print_nbr_fd(int n, t_state_machine *m)
{
	int	size;

	size = get_intlen(m->args.d, 1);
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

void	print_width_int(t_state_machine *m)
{
	if (!(m->flag & MINUS))
		while (m->fwidth && (m->fwidth - 1 > m->preci))
		{
			ft_putchar_fd(m->flag & ZERO ? '0' : ' ', 1);
			m->len++;
			m->fwidth--;
		}
	if (m->fwidth - m->preci > 0 && !(m->flag & MINUS))
	{
		if (m->args.d < 0 && m->flag & ZERO)
			ft_putchar_fd('0', m->fd);
		else if (m->flag & ZERO)
			ft_putchar_fd((m->args.d < 0) ? '-' : '0', m->fd);
		else
			ft_putchar_fd((m->args.d < 0) ? '-' : ' ', m->fd);
		m->fwidth--;
		m->len++;
	}
	if (m->flag & MINUS && m->args.d < 0)
	{
		ft_putchar_fd('-', m->fd);
		m->fwidth--;
		m->len++;
	}
}

void	print_width_int_empty(t_state_machine *m)
{
	while (m->fwidth)
	{
		ft_putchar_fd(' ', 1);
		m->len++;
		m->fwidth--;
	}
}

void	print_conv_int(t_state_machine *m)
{
	int	size;

	m->args.d = (int)va_arg(m->params, int);
	if (!(m->args.d) && m->flag & POINT && (!(m->preci) || m->preci == -1))
	{
		print_width_int_empty(m);
		return ;
	}
	size = get_intlen(m->args.d, 1);
	if (m->flag & ZERO && (m->flag & POINT || m->flag & MINUS))
		m->flag &= ~ZERO;
	m->preci = (m->preci < size ? size : m->preci);
	m->fwidth = (m->fwidth < m->preci ? m->preci : m->fwidth);
	if ((m->fwidth == m->preci) && m->args.d < 0)
		m->fwidth = m->preci + 1;
	if (m->args.d < 0 && m->flag & ZERO)
	{
		ft_putchar_fd('-', 1);
		m->len++;
		m->fwidth--;
	}
	print_width_int(m);
	print_nbr_fd(m->args.d, m);
	while (m->fwidth > 0)
	{
		ft_putchar_fd(' ', 1);
		m->len++;
		m->fwidth--;
	}
}
