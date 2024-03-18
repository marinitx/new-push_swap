# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 13:00:17 by mhiguera          #+#    #+#              #
#    Updated: 2024/03/17 14:02:22 by mhiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/push_swap.c ./src/check.c ./src/sort.c ./src/moves_a.c ./src/utils.c ./src/moves_b.c ./src/moves_ab.c ./src/radix.c
		
OBJS = $(SRC:.c=.o)
C = gcc
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
NAME = push_swap
RM = rm -rf

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

all: $(NAME)
	@$(RM) $(OBJS)

.SILENT: $(OBJS)

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR) --silent
	@gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(LIBFT)
	@make clean -C $(LIBFT_DIR) --silent

fclean:	clean
	@make fclean -C $(LIBFT_DIR) --silent
	@$(RM) $(NAME) $(OBJS)

re:	fclean all
	
.PHONY:	all clean fclean re