NAME = pipex
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC =	pipex.c \
		paths.c \
		childs.c \
		utils/ft_strlen.c \
		utils/ft_memcpy.c \
		utils/ft_split.c \
		utils/ft_strdup.c \
		utils/ft_strlcpy.c \
		utils/ft_substr.c \
		utils/ft_strncmp.c \
		utils/ft_strjoin.c \
		utils/ft_pexit.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c

OBJ = ${SRC:%.c=%.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re