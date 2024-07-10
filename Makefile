# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fli <fli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 10:09:37 by fli               #+#    #+#              #
#    Updated: 2024/07/10 18:35:21 by fli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g3 ###

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./includes/

MANDATORY = ./src/

BONUS = ./bonus/

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


BFILES = checker.c \
		 get_next_line_bonus.c \
		 get_next_line_utils_bonus.c \
		 instructions_a.c \
		 instructions_b.c \
		 instructions.c \
		 instructions_wrap.c \
		 list_manip.c \
		 lst_update.c \
		 parsing.c \
		 push_swap_utils.c \
		 sorting.c \
		 sorting2.c \
		 supercalculator.c \
		 optimization.c \
		 temp_file.c \

SRC_MANDATORY = $(addprefix $(MANDATORY), $(CFILES))

SRC_BONUS = $(addprefix $(BONUS), $(BFILES))

LIBFT = ./libft/

NAME = push_swap

NAME_BONUS = checker

LIB = libft.a

OBJ = $(SRC_MANDATORY:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ) $(LIB) -o $(NAME)

$(NAME_BONUS): $(LIB) $(OBJ_BONUS)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ_BONUS) $(LIB) -o $(NAME_BONUS)

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
	rm -f $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
