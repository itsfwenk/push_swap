# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fli <fli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 10:09:37 by fli               #+#    #+#              #
#    Updated: 2024/07/09 17:46:28 by fli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g3 ###

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./includes/

MANDATORY = ./src/

CFILES = instructions_a.c \
		 instructions_b.c \
		 instructions.c \
		 instructions_wrap.c \
		 list_manip.c \
		 lst_update.c \
		 parsing.c \
		 push_swap_utils.c \
		 push_swap.c \
		 sorting.c \
		 sorting2.c \
		 supercalculator.c \
		 optimization.c \
		 temp_file.c \

BFILES = bonus.c

SRC_MANDATORY = $(addprefix $(MANDATORY), $(CFILES))

SRC_BONUS = $(addprefix $(BONUS), $(BFILES))

LIBFT = ./libft/

NAME = push_swap

BONUS = ./bonus/

LIB = libft.a

OBJ = $(SRC_MANDATORY:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ) $(LIB) -o $(NAME)

$(LIB):
	make -C $(LIBFT)
	cp ./libft/libft.a $(LIB)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(LIB)
	rm -f $(OBJ_BONUS)
	make -C $(LIBFT) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(LIB) $(OBJ_BONUS)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ_BONUS) $(LIB) -o $(NAME)

.PHONY: all clean fclean re bonus
