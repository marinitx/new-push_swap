# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 13:00:17 by mhiguera          #+#    #+#              #
#    Updated: 2024/02/04 13:01:20 by mhiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ../src/push_swap.c ../src/check.c ../src/sort.c ../src/moves_a.c
		
OBJS = $(SRC:.c=.o)
C = gcc
FLAGS = -Wall -Wextra -Werror #-g  -fsanitize=address
NAME = push_swap
RM = rm -rf

LIBFT_DIR = libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR) --silent
	@gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(LIBFT_A)
	@make -C $(LIBFT_DIR) clean --silent

fclean:	clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent

re:	fclean
	@make all
	
.PHONY:	all clean fclean re