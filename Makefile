# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 13:00:17 by mhiguera          #+#    #+#              #
#    Updated: 2024/03/25 18:15:23 by mhiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/push_swap.c ./src/check.c ./src/sort.c ./src/moves_a.c ./src/utils.c ./src/moves_b.c ./src/moves_ab.c ./src/listing.c ./src/index.c ./src/libft.c
FT_PRINTF = ./ft_printf

OBJS = $(SRC:.c=.o)
C = gcc
FLAGS = -Wall -Wextra -Werror ##-g3 -fsanitize=address
NAME = push_swap
RM = rm -rf

FT_PRINTF_DIR = ./ft_printf/
FT_PRINTF_A = libftprintf.a
FT_PRINTF = -L$(FT_PRINTF_DIR) $(FT_PRINTF_DIR)$(FT_PRINTF_A)

all: $(NAME)
	@$(RM) $(OBJS)

.SILENT: $(OBJS) $(FT_PRINTF)

$(NAME): $(OBJS)
	@make -C $(FT_PRINTF_DIR)
	@gcc $(FLAGS) $(OBJS) $(FT_PRINTF_DIR)$(FT_PRINTF_A) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(FT_PRINTF)
	@make clean -C $(FT_PRINTF_DIR)

fclean:	clean
	@make fclean -C $(FT_PRINTF_DIR)
	@$(RM) $(NAME) $(OBJS)

re:	fclean all
	
.PHONY:	all clean fclean re