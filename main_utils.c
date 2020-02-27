#include "main.h"
#include "libft.h"

void	print_conv(char c, t_state_machine *m)			//cspdiuxX
{
	if (m->flag & C_CONV)								//CHAR		c
		print_conv_chr(m);
	else if (m->flag & S_CONV)							//STRINGS	s
		print_conv_str(m);
	else if (m->flag & P_CONV)							//POINTEUR	p
		print_conv_ptr(m);
	else if (m->flag & (D_CONV | I_CONV))				//INTEGERS	d	i
		print_conv_int(m);
	else if (m->flag & (U_CONV | X_CONV | XMAJ_CONV))	//UNSIGNED	u	x	X
		print_conv_uns(m);
}

void	print_conv_str(t_state_machine *m)
{
	int	len;

	m->args.s = (char *)va_arg(m->params, char *);
	if (m->args.s == 0)
		m->args.s = "(null)";
	if (m->fwidth > 0)
	{
		if ((m->fwidth != 0) && (len < m->fwidth))
			{
				len = (m->fwidth - len);
				m->len += len;
			}
		while (len--)
		{
			ft_putchar_fd(' ', 1);
			m->len++;
		}
	}
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
	int	len;

	m->args.d = (int)va_arg(m->params, int);
	ft_putnbr_fd(m->args.d, 1);
	if (DEBUG)
		ft_putchar_fd('|', 1);
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
}

void	print_conv_ptr(t_state_machine *m)
{
}

void	extract_aste(t_state_machine *m)
{
	if (m->flag & POINT)
		m->preci = (int)va_arg(m->params, int);
	else
		m->fwidth = (int)va_arg(m->params, int);
	m->flag &= ~ASTER;
	if (DEBUG)
	{
		if (m->flag & POINT)
			printf("Precision: %d\n", m->preci);
		else
			printf("Field Width: %d\n", m->fwidth);
	}
}
