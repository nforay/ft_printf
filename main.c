#include "main.h"
#include "libft.h"

int		main(void)
{
	int	pflen;
	int	ftpflen;

	ftpflen = ft_printf("%.6i\n", -3);
	pflen = printf("%.6i\n", -3);
	printf("DEBUG | ft_printf return = %d\n", ftpflen);
	printf("DEBUG | printf return = %d\n", pflen);
	//(void)pflen;
	//(void)ftpflen;
	return (EXIT_SUCCESS);
}
