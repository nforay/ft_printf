#include "main.h"
#include "libft.h"

int		ft_strnequ(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		error(char *input, t_state_machine *machine)
{
/*
 * DO ERROR CONV
 * */
	printf("cur = '%c' | state = ERROR\n", *input);
	machine->state = LETTER;
	machine->flag = 0;
	return (1);
}

void	print_conv(char c, t_state_machine *machine)				//cspdiuxX
{
	int	len;

	if (machine->flag & (D_CONV | I_CONV))							//INTEGERS	d i
	{
		machine->args.d = (int)va_arg(machine->params, int);
		ft_putnbr_fd(machine->args.d, 1);
		if (DEBUG)
			ft_putchar_fd('|', 1);
		len = ft_strlen(ft_itoa(machine->args.d));
		if ((machine->fwidth != 0) && (len < machine->fwidth))
			machine->len += machine->fwidth;
		else
			machine->len += len;
		machine->fwidth = 0;
	}
	else if (machine->flag & S_CONV)								//STRINGS	s
	{
		machine->args.s = (char *)va_arg(machine->params, char *);
		if (machine->args.s == 0)
			machine->args.s = "(null)";
		len = ft_strlen(machine->args.s);
			machine->len += len;
		if (machine->fwidth > 0)
		{
			if ((machine->fwidth != 0) && (len < machine->fwidth))
				{
					len = (machine->fwidth - len);
					machine->len += len;
				}
			while (len--)
				ft_putchar_fd(' ', 1);
		}
		ft_putstr_fd(machine->args.s, 1);
	}
}

int		conv(char *input, t_state_machine *machine)
{
	static char	*str_conv = ALLCONV;
	int			i;

	i = 0;
	while (i < NB_CONV)
	{
		if (ft_strnequ(input, str_conv + i, 1) == TRUE)
		{
			machine->flag |= (1 << i) << 12;
			print_conv(input[0], machine);  //DO CONV
			if (DEBUG)
				printf("cur = '%c' | state = CONV\n", *input);
			machine->state = LETTER;
			machine->flag = 0;
			machine->preci = 0;
			machine->fwidth = 0;
			return (1);
		}
		i++;
	}
	machine->state = ERROR;
	return (0);
}

void	extract_aste(t_state_machine *machine)
{
	if (machine->flag & POINT)
		machine->preci = (int)va_arg(machine->params, int);
	else
		machine->fwidth = (int)va_arg(machine->params, int);
	machine->flag &= ~ASTER;
	if (DEBUG) {
		if (machine->flag & POINT)
		{
			printf("Precision: %d\n", machine->preci);
		}
		else
		{
			printf("Field Width: %d\n", machine->fwidth);
		}
	}
}

int		flag(char *input, t_state_machine *machine)
{
	static char	*str_flag[NB_FLAG] = {FLAG_HH, FLAG_LL, FLAG_MINUS, FLAG_ZERO,
		FLAG_ASTER, FLAG_HASH, FLAG_SPACE, FLAG_PLUS, FLAG_H,
		FLAG_L, FLAG_POINT};
	int			i;
	int			size;

	i = 0;
	while (i < NB_FLAG)
	{
		size = i < 2 ? 2 : 1;
		if (ft_strnequ(input, str_flag[i], size) == TRUE)
		{
			if (DEBUG)
				printf("cur = '%s' | state = FLAG\n", str_flag[i]);
			machine->flag |= (1 << i);
			if (machine->flag & ASTER)
				extract_aste(machine);
			return (size);
		}
		if (!(machine->flag & POINT) && (input[0] > '0' && input[0] <= '9')
				&& (machine->fwidth = ft_atoi(input)))
		{
			if (DEBUG)
				printf("Field Width : len = %d\n", machine->fwidth);
			return (ft_strlen(ft_itoa(machine->fwidth)));
		}
		if ((machine->flag & POINT) && (input[0] >= '0' && input[0] <= '9')
				&& (machine->preci = ft_atoi(input)))
		{
			if (DEBUG)
				printf("Precision : len = %d\n", machine->preci);
			return (ft_strlen(ft_itoa(machine->preci)));
		}
		i++;
	}
	machine->state = CONV;
	return (0);
}

void	add_to_buff(char c, t_state_machine *machine)
{
	if (machine->len == 4096)
	{
		machine->len = 0;
		ft_bzero(&machine->buffer, 4096);
	}
	machine->buffer[machine->len] = c;
	machine->len++;
}

int		letter(char *input, t_state_machine *machine)
{
	if (*input == '%')
		machine->state = FLAG;
	else
	{
		add_to_buff(*input, machine);
		ft_putchar_fd(*input, 1);
		if (DEBUG)
			ft_putchar_fd('|', 1);
		if (DEBUG)
			printf("cur = '%c' | state = LETTER\n", *input);
	}
	return (1);
}

int		ft_printf(char *format, ...)
{
	static t_function	process[4] = {letter, flag, conv, error};
	t_state_machine		machine;
	int					ret;

	va_start(machine.params, format);
	machine.state = LETTER;
	machine.len = 0;
	machine.flag = 0;
	ft_bzero(&machine.buffer, 4096);
	while (format != NULL && *format != '\0')
	{
		if ((ret = process[machine.state](format, &machine)) >= 0)
			format += ret;
	}
	va_end(machine.params);
	printf("DEBUG | ft_printf return = %d\n", machine.len);
	return (machine.len);
}

int		main(int ac, char **av)
{
	int	pflen;

	if (ac != 2)
		return (EXIT_FAILURE);
	ft_printf(av[1], 10, 15, "hello\n");
	pflen = printf(av[1], 10, 15, "hello\n");
	printf("DEBUG | printf return = %d\n", pflen);
	return (EXIT_SUCCESS);
}
