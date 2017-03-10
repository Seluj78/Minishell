# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlasne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 10:25:59 by jlasne            #+#    #+#              #
#    Updated: 2017/03/10 11:10:25 by jlasne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	main.c\
		path_parser.c\
		path_parser_helper.c\
		echo.c\
		cmd_exec.c\
		disp_help.c\
		cmds_env.c\
		cmd_cd.c\
		sig_handler.c\
		ft_strmjoin.c\
		help_funcs.c\
		what_cmd.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -g3 -Wall -Wextra -Werror #-fsanitize=address

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
	make re

.PHONY : all re clean fclean test
