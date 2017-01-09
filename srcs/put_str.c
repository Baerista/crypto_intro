#include "cryptest.h"

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}
