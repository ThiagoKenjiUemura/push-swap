/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:52:41 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/10/21 20:08:48 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	input_number(const char *str)
{
	long	n;
	int		i;
	int		num;

	if (!str || *str == '\0')
		error_exit();
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!isdigit(str[i]))
		error_exit();
	while (str[i])
	{
		if (!isdigit(str[i]))
			error_exit();
		i++;
	}
	n = atol(str);
	if (n < -2147483648 || n > 2147483647)
		error_exit();
	num = n;
	return (num);
}

int	fill_stack_args(char **args, t_list **a)
{
	int		i;
	int		num;
	t_list	*new_node;

	i = 0;
	while (args[i])
	{
		num = input_number(args[i]);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			error_exit();
		new_node->number = num;
		new_node->next = NULL;
		lst_add_back(a, new_node);
		i++;
	}
	return (i);
}

int	input(int argc, char **argv, t_list **a)
{
	int		i;
	int		total_size;
	char	**split_args;

	i = 1;
	total_size = 0;
	while (i < argc)
	{
		split_args = split(argv[i], ' ');
		if (!split_args || !*split_args)
		{
			free_split(split_args);
			error_exit();
		}
		total_size += fill_stack_args(split_args, a);
		free_split(split_args);
		i++;
	}
	return (total_size);
}

