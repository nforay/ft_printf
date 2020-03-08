#include "main.h"
#include "libft.h"
#include <limits.h>

int		main(void)
{
	int	pflen;
	int	ftpflen;

	ftpflen = ft_printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", 0, 0, 0, 0, 0, 0, 0);
	pflen = printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", 0, 0, 0, 0, 0, 0, 0);
	printf("DEBUG | ft_printf return = %d\n", ftpflen);
	printf("DEBUG | printf return = %d\n", pflen);
	//(void)pflen;
	//(void)ftpflen;
	return (EXIT_SUCCESS);
}
