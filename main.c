#include "main.h"
#include "libft.h"

int		main(void)
{
	int	pflen;
	int	ftpflen;

	ftpflen = ft_printf("%-32.00s\n", "abc");
	pflen = printf("%-32.00s\n", "abc");
	printf("DEBUG | ft_printf return = %d\n", ftpflen);
	printf("DEBUG | printf return = %d\n", pflen);
	//(void)pflen;
	//(void)ftpflen;
	return (EXIT_SUCCESS);
}
