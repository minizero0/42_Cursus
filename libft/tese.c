#include "libft.h"
#include <stdio.h>
int	main(void)
{
	char *str;

	str = "hello";
	ft_bzero(str, 2);
	printf("%s", str);
}
