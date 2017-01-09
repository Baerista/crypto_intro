#include "cryptest.h"

char	*get_key(char *file)
{
	int		fd;
	int		bytes_read;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		put_str("error opening key file");
		return (NULL);
	}

	str = (char*)malloc(sizeof(char) * (KEYSIZE));
	bytes_read = read(fd, str, KEYSIZE);

	if (bytes_read != KEYSIZE)
	{
		put_str("key file has too few bytes");
		free(str);
		close(fd);
		return (NULL);
	}
	
	close(fd);
	return (str);
}
