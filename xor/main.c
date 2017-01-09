#include <unistd.h>
#include <fcntl.h>
//#include <stdlib.h>

void	putc(char c)
{
	write(1, &c, 1);
}

void	puts(char *str)
{
	while (*str)
		putc(*(str++));
	putc('\n');
}

int		main(int argc, char **argv)
{
	char	*str1;
	char	*str2;

	if (argc != 3)
		puts("usage: xor <string1> <string2>");
	else
	{
		str1 = argv[1];
		str2 = argv[2];

		while (*str1 && *str2)
		{
//			putc(*str1);
//			putc(*str2);
//			putc(',');
			putc((*str1 ^ *str2));
//			putc('/');
			str1++;
			str2++;
		}
		putc('\n');
	}
	return (0);
}
