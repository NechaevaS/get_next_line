#include <stdio.h>
#include "libft.h" 

void ft_print_mem(unsigned char *str, size_t size)
{

	while (size)
	{
		printf("%02x ", *str);
		str++;
		size--;
	}
}
