# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 18:42:53 by thiagouemur       #+#    #+#              #
#    Updated: 2025/10/22 09:46:29 by tkenji-u         ###   ########.fr        #
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
	   srcs/libft/ft_atol.c \
	   srcs/libft/ft_bzero.c \
	   srcs/libft/ft_calloc.c \
	   srcs/libft/ft_isdigit.c \
	   srcs/libft/ft_memcpy.c \
	   srcs/libft/ft_memmove.c \
	   srcs/libft/ft_memset.c \
	   srcs/libft/ft_split.c \
	   srcs/libft/ft_strdup.c \
	   srcs/libft/ft_strlcpy.c \
	   srcs/libft/ft_strlen.c \
	   srcs/libft/ft_substr.c \
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