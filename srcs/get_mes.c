#include "cryptest.h"

static char	*append(char	*str1, char *str2, int n_bytes)
{
	char	*temp;
	int		i1, i2, i3;

	temp = (char*)malloc(sizeof(char) * g_mes_len);
	i1 = 0;
	i2 = 0;
	i3 = 0;

	while (i1 < (g_mes_len - n_bytes))
		temp[i3++] = str1[i1++];
	while (i2 < n_bytes)
		temp[i3++] = str2[i2++];

	free(str1);
	return (temp);
}

char	*get_mes(char *file)
{
	int		fd;
	int		bytes_read;
	char	*str;
	char	*temp;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		put_str("error opening message file");
		return (NULL);
	}

	str = (char*)malloc(sizeof(char) * (KEYSIZE));
	temp = (char*)malloc(sizeof(char) * (KEYSIZE));

	g_mes_len = 0;
	while ((bytes_read = read(fd, temp, KEYSIZE)))
	{
		if (bytes_read == -1)
		{
			put_str("error reading from message file");
			free(str);
			free(temp);
			close(fd);
			return (NULL);
		}
		g_mes_len += bytes_read;
		str = append(str, temp, bytes_read);
	}

	free(temp);
	close(fd);
	if (g_mes_len == 0)
	{
		put_str("message file empty");
		free(str);
		return (NULL);
	}
	return (str);		
}
