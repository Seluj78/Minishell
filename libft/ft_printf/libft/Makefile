# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlasne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:34:13 by jlasne            #+#    #+#              #
#    Updated: 2016/12/15 14:42:29 by jlasne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#================================COLORS========================================#

# Reset

reset=\033[0m       # Text Reset


# Regular Colors

Black=\033[0;30m        # Black
Red=\033[0;31m          # Red
Green=\033[0;32m        # Green
Yellow=\033[0;33m       # Yellow
Blue=\033[0;34m         # Blue
Purple=\033[0;35m       # Purple
Cyan=\033[0;36m         # Cyan
White=\033[0;37m        # White


# Bold

BBlack=\033[1;30m       # Black
BRed=\033[1;31m         # Red
BGreen=\033[1;32m       # Green
BYellow=\033[1;33m      # Yellow
BBlue=\033[1;34m        # Blue
BPurple=\033[1;35m      # Purple
BCyan=\033[1;36m        # Cyan
BWhite=\033[1;37m       # White


# Underline

UBlack=\033[4;30m       # Black
URed=\033[4;31m         # Red
UGreen=\033[4;32m       # Green
UYellow=\033[4;33m      # Yellow
UBlue=\033[4;34m        # Blue
UPurple=\033[4;35m      # Purple
UCyan=\033[4;36m        # Cyan
UWhite=\033[4;37m       # White

#=================================MAKEFILE=====================================#

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -g

SRC = ft_bzero.c\
	  ft_memset.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_strlen.c\
	  ft_strwlen.c\
	  ft_strdup.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strlcat.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_atoi.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_putnbr_fd.c\
	  ft_putnbr.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_strjoin.c\
	  ft_strclr.c\
	  ft_memalloc.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_memdel.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_itoa.c\
	  ft_strsub.c\
	  ft_power.c\
	  ft_split_whitespaces.c\
	  ft_cat.c\
	  ft_atoi_base.c\
	  ft_atoi_nbase.c\
	  ft_itoa_base.c\
	  ft_itoa_base_l.c\
	  ft_itoa_base_ll.c\
	  ft_itoa_base_uint.c\
	  ft_nblen.c\
	  ft_nblen_l.c\
	  ft_nblen_ll.c\
	  ft_putnbr_l.c\
	  ft_putnbr_ll.c\
	  ft_strisdigit.c\
	  ft_binlen.c\
	  ft_charwlen.c\
	  ft_putnwstr.c\
	  ft_putnwchar.c\
	  ft_putwchar.c\
	  ft_putnstr.c

OBJ = $(SRC:.c=.o)

INC = ./includes

all: $(NAME)


### TODO : Pretty makefile

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c
	gcc -c $(FLAGS) -I $(INC) $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
