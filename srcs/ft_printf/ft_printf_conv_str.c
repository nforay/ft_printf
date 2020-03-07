#include "main.h"
#include "libft.h"

void	print_width_str(t_state_machine *m)
{
	int	strlen;

	strlen = !(m->args.s) ? 6 : (int)ft_strlen(m->args.s);
	if (strlen <= m->fwidth)
		if (m->flag & POINT && m->preci < strlen)
			m->fwidth = (m->fwidth - m->preci);
		else
			m->fwidth = (m->fwidth - strlen);
	else if (strlen > m->fwidth)
		m->fwidth = (m->flag & POINT) ? m->fwidth - m->preci : 0;
	while (m->fwidth > 0 && m->fwidth--)
	{
		if (m->flag & ZERO && !(m->flag & MINUS))
			ft_putchar_fd('0', m->fd);
		else
			ft_putchar_fd(' ', m->fd);
		m->len++;
	}
}

void	print_conv_str(t_state_machine *m)
{
	m->preci = (m->preci < 0 ? 0 : m->preci);
	m->args.s = (char *)va_arg(m->params, char *);
	if (!(m->args.s))
		m->args.s = "(null)";
	if (!(m->flag & MINUS) && (m->fwidth > 0))
		print_width_str(m);
	if (m->flag & POINT && m->args.s)
		while (m->preci > 0 && m->preci-- && *m->args.s)
		{
			ft_putchar_fd(*m->args.s++, 1);
			if (m->fwidth != 0)
				m->fwidth--;
			m->len++;
		}
	else
	{
		m->len += ft_strlen(m->args.s);
		ft_putstr_fd(m->args.s, 1);
	}
	if (m->flag & MINUS && (m->fwidth > 0))
		print_width_str(m);
}
