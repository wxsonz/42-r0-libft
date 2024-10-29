#include "libft.h"
#include <stdio.h>

char	ft_toup(unsigned int i, char c)
{
	if (((unsigned)c | 32) - 'a' < 26)
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*a;
	char	*b;

	a = "abcdefghijklmnopqrstuvwxyz";
	b = ft_strmapi(a, ft_toup);
	printf("a = %s\n", a);
	printf("b = %s\n", b);
	return (0);
}
