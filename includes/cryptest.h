#ifndef CRYPTEST_H
#define CRYPTEST_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define KEYSIZE 32 

int		g_mes_len;

char	*get_key(char *file);
char	*get_mes(char *file);
void	put_str(char *str);
void	put_enc(char *key, char *mes, char *file);

#endif
