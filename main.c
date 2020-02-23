#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int	main(void)
{
	printf("expected: |test%d\n", 2);
	ft_printf("result:   |test%d\ntest%d\n%d\n", 2, 3, 4);
}
