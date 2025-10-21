# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 18:42:53 by thiagouemur       #+#    #+#              #
#    Updated: 2025/10/21 20:37:59 by thiagouemur      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I includes
CPPFLAGS = $(INCLUDES)

VPATH = srcs srcs/parsing srcs/libft srcs/operations srcs/algorithm

SRCS =	srcs/main.c \
       srcs/parsing/check_args.c \
       srcs/libft/list_utils.c \
	   srcs/libft/atol.c \
	   srcs/libft/bzero.c \
	   srcs/libft/calloc.c \
	   srcs/libft/isdigit.c \
	   srcs/libft/memcpy.c \
	   srcs/libft/memmove.c \
	   srcs/libft/memset.c \
	   srcs/libft/split.c \
	   srcs/libft/strdup.c \
	   srcs/libft/strlcpy.c \
	   srcs/libft/strlen.c \
	   srcs/libft/substr.c \
	   srcs/operations/aux_operations.c \
       srcs/operations/swap.c \
       srcs/operations/push.c \
       srcs/operations/rotate.c \
       srcs/operations/reverse_rotate.c \
       srcs/algorithm/aux_sorted.c \
       srcs/algorithm/sorted.c \
	
OBJS = $(notdir $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "push_swap compiled successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

clean:
	@rm -f $(OBJS)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Everything clean."

re: fclean all

.PHONY: all clean fclean re