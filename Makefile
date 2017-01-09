NAME = cryptest
COMPILE = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE_DIR = ./srcs/
SOURCE_CODE = main.c get_key.c get_mes.c put_str.c put_enc.c
SRCS =$(addprefix $(SOURCE_DIR), $(SOURCE_CODE))
OBJECTS = $(SRCS:.c=.o) 
INCLUDES = -I ./includes/

.PHONY: all clean fclean re

test: 
	$(COMPILE) $(FLAGS) -fsanitize=address $(SRCS) $(INCLUDES) -o $(NAME)

all: $(NAME)

$(NAME): 
	$(COMPILE) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
