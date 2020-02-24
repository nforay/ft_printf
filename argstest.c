#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int	main(void)
{
	printf("expected: |test%d\n", 2);
	ft_printf("result:   |test%d\ntest%i\n%s%d%%\n%c\n", 2, 3, "test", 4, 'a');
}
