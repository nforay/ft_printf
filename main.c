#include "main.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int	pflen;
	int	ftpflen;
	(void)av;

	if (ac != 2)
		return (EXIT_FAILURE);
	ftpflen = ft_printf("%%\n");
	pflen = printf("%%\n");
	printf("DEBUG | ft_printf return = %d\n", ftpflen);
	printf("DEBUG | printf return = %d\n", pflen);
	return (EXIT_SUCCESS);
}
