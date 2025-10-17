# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 18:42:53 by thiagouemur       #+#    #+#              #
#    Updated: 2025/10/17 13:26:45 by tkenji-u         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I includes -I libft/
LIBFT_DIR = libft/
LIBFT_A = $(LIBFT_DIR)libft.a

SRCS =	srcs/main.c \
		srcs/parsing/check_args.c \
		srcs/parsing/init_stack_a.c \
		srcs/operations/swap.c \
		srcs/operations/push.c \
		srcs/operations/rotate.c \
		srcs/operations/reverse_rotate.c \
		srcs/utils/list_utils.c \
		srcs/algorithm/sort.c

OBJS = $(SRCS:srcs/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "push_swap compiled successfully!"

%.o: srcs/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled: $< -> $@"

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@echo "Object files removed."

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "Everything clean."

re: fclean all

.PHONY: all clean fclean re