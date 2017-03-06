# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlasne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 10:25:59 by jlasne            #+#    #+#              #
#    Updated: 2017/03/06 10:19:32 by jlasne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	main.c\
		path_parser.c
		#env.c\
		cmd_parser.c\
		break_str_to_tab_sep.c\
		ft_add_to_array.c\
		ft_free_array.c\
		ft_arraylen.c\
		ft_remove_from_array.c#

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -g -Wall -Wextra -Werror #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o : $(SRC_PATH)/%.c
		    $(CC) -o $@ -c $< $(FLAGS)

$(LIBFT):
		make -C ./libft/

clean:
		rm -rf $(OBJ)
			make clean -C ./libft/

fclean: clean
		rm -rf $(NAME)
			make fclean -C ./libft/

re: fclean all

test:
	make
	cat tests/test_exit.txt | ./minishell
	cat tests/test_errors.txt | ./minishell
	@#cat tests/test_env.txt | ./minishell#
	cat tests/test_cmd.txt | ./minishell

.PHONY : all re clean fclean
