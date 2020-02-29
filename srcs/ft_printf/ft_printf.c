#include "main.h"
#include "libft.h"

static int		error(char *input, t_state_machine *machine)
{
	(void)input;
	machine->state = LETTER;
	machine->flag = 0;
	return (1);
}

static int		conv(char *input, t_state_machine *machine)
{
	static char	*str_conv = ALLCONV;
	int			i;

	i = 0;
	while (i < NB_CONV)
	{
		if (ft_strncmp(input, str_conv + i, 1) == FALSE)
		{
			machine->flag |= (1 << i) << 12;
			print_conv(machine);
			if (machine->flag & PER_CONV)
			{
				ft_putchar_fd('%', 1);
				machine->len++;
			}
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

static int		flag(char *input, t_state_machine *machine)
{
	static char	*str_flag[NB_FLAG] = {F_HH, F_LL, F_MINUS, F_ZERO,
		F_ASTER, F_HASH, F_SPACE, F_PLUS, F_H, F_L, F_POINT};
	int			i;

	i = 0;
	while (i < NB_FLAG)
	{
		if (!(machine->flag & POINT) && (input[0] > '0' && input[0] <= '9')
				&& (machine->fwidth = ft_atoi(input)))
			return (ft_strlen(ft_itoa(machine->fwidth)));
		if ((machine->flag & POINT) && (ft_isdigit(input[0]))
				&& (machine->preci = ft_atoi(input)))
			return (ft_strlen(ft_itoa(machine->preci)));
		if (ft_strncmp(input, str_flag[i], (i < 2 ? 2 : 1)) == FALSE)
		{
			machine->flag |= (1 << i);
			if (machine->flag & ASTER)
				extract_aste(machine);
			return (i < 2 ? 2 : 1);
		}
		i++;
	}
	machine->state = CONV;
	return (0);
}

static int		letter(char *input, t_state_machine *machine)
{
	if (*input == '%')
		machine->state = FLAG;
	else
	{
		ft_putchar_fd(*input, 1);
		machine->len++;
	}
	return (1);
}

int				ft_printf(char *format, ...)
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
	return (machine.len);
}