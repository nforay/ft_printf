#include "main.h"
#include "libft.h"

void	print_width(t_state_machine *m)
{
	if (m->fwidth > 0)
	{
		if ((m->fwidth != 0) && (ft_strlen(m->args.s) < m->fwidth))
			m->len += (m->fwidth - ft_strlen(m->args.s));
		while (m->fwidth--)
		{
			ft_putchar_fd(' ', 1);
			m->len++;
		}
	}
}

void	print_conv(t_state_machine *m)
{
	if (m->flag & (MINUS + C_CONV))
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
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar_fd('-', 1);
		m->len++;
	}
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
	if (m->args.s == 0)
		m->args.s = "(null)";
	print_width(m);
	if (m->flag & POINT)
		while (m->preci-- && *m->args.s)
		{
			ft_putchar_fd(*m->args.s++, 1);
			m->len++;
		}
	else
		ft_putstr_fd(m->args.s, 1);
}

void	print_conv_int(t_state_machine *m)
{
	size_t	len;

	m->args.d = (int)va_arg(m->params, int);
	if (m->flag & ZERO && m->args.d == 0)
		return ;
	ft_putnbr_fd(m->args.d, 1);
	len = ft_strlen(ft_itoa(m->args.d));
	if ((m->fwidth != 0) && (len < m->fwidth))
		m->len += m->fwidth;
	else
		m->len += len;
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
		ft_putnbr_base(m, m->args.xmaj, "0123456789ABCDEF");
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
		m->fwidth = (int)va_arg(m->params, int);
	m->flag &= ~ASTER;
}
