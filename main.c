#include "main.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int	pflen;

	if (ac != 2)
		return (EXIT_FAILURE);
	ft_printf("p1 %.6s\n", "abcd");
	pflen = printf("p1 %.6s\n", "abcd");
	printf("DEBUG | printf return = %d\n", pflen);
	return (EXIT_SUCCESS);
}
