#include "cryptest.h"

int		main(int argc, char **argv)
{
	char	*key = NULL;
	char	*mes = NULL;
	char	*out = NULL;


	if (argc != 4)
		put_str("usage: cryptext <key file> <message file> <output file>");
	else
	{
		key = get_key(argv[1]);
		if (key)
		{
			mes = get_mes(argv[2]);
			if (mes)
			{
				out = argv[3];
				put_enc(key, mes, out); 
				free(mes);
			}
			free(key);
		}
	}
	return (0);
}
