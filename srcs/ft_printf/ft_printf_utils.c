#include "main.h"
#include "libft.h"

int			intlen(int n, int len)
{
	if (n <= 0)
		n = -n;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	print_perc(t_state_machine *m)
{
	if (!(m->flag & MINUS) && m->fwidth > 1)
		while (m->fwidth > 1 && m->fwidth--)
		{
			ft_putchar_fd((m->flag & ZERO) ? '0' : ' ', m->fd);
			m->len++;
		}
	ft_putchar_fd('%', 1);
	m->fwidth--;
	m->len++;
	if (m->flag & MINUS && m->fwidth > 0)
		while (m->fwidth > 0 && m->fwidth--)
		{
			ft_putchar_fd(' ', m->fd);
			m->len++;
		}
}

void	print_conv_nolength(t_state_machine *m)
{
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
	else if (m->flag & PER_CONV)
		print_perc(m);
}

void	print_conv_hh(t_state_machine *m)
{
	if (m->flag & C_CONV)
		print_conv_chr(m);
	else if (m->flag & S_CONV)
		print_conv_str(m);
	else if (m->flag & P_CONV)
		print_conv_ptr(m);
	else if (m->flag & (D_CONV | I_CONV))
		print_conv_int_hh(m);
	else if (m->flag & (U_CONV | X_CONV | XMAJ_CONV))
		print_conv_uns(m);
	else if (m->flag & PER_CONV)
		print_perc(m);
}

void	print_conv_ll(t_state_machine *m)
{
	if (m->flag & C_CONV)
		print_conv_chr(m);
	else if (m->flag & S_CONV)
		print_conv_str(m);
	else if (m->flag & P_CONV)
		print_conv_ptr(m);
	else if (m->flag & (D_CONV | I_CONV))
		print_conv_int_ll(m);
	else if (m->flag & (U_CONV | X_CONV | XMAJ_CONV))
		print_conv_uns(m);
	else if (m->flag & PER_CONV)
		print_perc(m);
}

void	print_conv_h(t_state_machine *m)
{
	if (m->flag & C_CONV)
		print_conv_chr(m);
	else if (m->flag & S_CONV)
		print_conv_str(m);
	else if (m->flag & P_CONV)
		print_conv_ptr(m);
	else if (m->flag & (D_CONV | I_CONV))
		print_conv_int_h(m);
	else if (m->flag & (U_CONV | X_CONV | XMAJ_CONV))
		print_conv_uns(m);
	else if (m->flag & PER_CONV)
		print_perc(m);
}

void	print_conv_l(t_state_machine *m)
{
	if (m->flag & C_CONV)
		print_conv_chr(m);
	else if (m->flag & S_CONV)
		print_conv_str(m);
	else if (m->flag & P_CONV)
		print_conv_ptr(m);
	else if (m->flag & (D_CONV | I_CONV))
		print_conv_int_l(m);
	else if (m->flag & (U_CONV | X_CONV | XMAJ_CONV))
		print_conv_uns(m);
	else if (m->flag & PER_CONV)
		print_perc(m);
}

void	print_conv(t_state_machine *m)
{
	if (m->flag & HH)
		print_conv_hh(m);
	else if (m->flag & LL)
		print_conv_ll(m);
	else if (m->flag & H)
		print_conv_h(m);
	else if (m->flag & L)
		print_conv_l(m);
	else
		print_conv_nolength(m);
}

void	print_conv_chr(t_state_machine *m)
{
	(void)m;
	m->args.c = va_arg(m->params, int);
	while (!(m->flag & MINUS) && m->fwidth > 1)
	{
		ft_putchar_fd(' ', m->fd);
		m->fwidth--;
		m->len++;
	}
	ft_putchar_fd(m->args.c, 1);
	m->fwidth--;
	m->len++;
	while (m->flag & MINUS && m->fwidth > 0)
	{
		ft_putchar_fd(' ', m->fd);
		m->fwidth--;
		m->len++;
	}
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
		m->flag = m->flag & ~POINT;
	m->flag &= ~ASTER;
}
