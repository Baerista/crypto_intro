#include "cryptest.h"

void	put_enc(char *key, char *mes, char *out)
{
	int		fd;
	int		mes_index;
	int		key_index;
	char	c;

	fd = open(out, O_WRONLY|O_CREAT, 0666);
	if (fd == -1)
		put_str("error opening or creating the output file for writing");
	else
	{
		mes_index = 0;
		key_index = 0;
		while (mes_index < g_mes_len)
		{
			c = mes[mes_index] ^ key[key_index];
			write(fd, &c, 1);
			mes_index++;
			key_index++;
			if (key_index == KEYSIZE)
				key_index = 0;
		}
		close(fd);
	}
}
