#include "main.h"
#include "libft.h"
# include <stdio.h>
#include <limits.h>

int		main(void)
{
	int	pflen;
	int	ftpflen;
	long long int	*test;
	long long int 	*testa;

	ftpflen = ft_printf("42%n42\n", &test);
	pflen = printf("42%n42\n", &testa);
	ft_printf("ft_printf %%n = %lld\n", test);
	printf("printf %%n = %lld\n", testa);
	printf("DEBUG | ft_printf return = %d\n", ftpflen);
	printf("DEBUG | printf return = %d\n", pflen);
	//(void)pflen;
	//(void)ftpflen;
	return (EXIT_SUCCESS);
}
