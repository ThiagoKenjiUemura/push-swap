/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:19 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/10/17 17:15:03 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *initialize_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*new_node;
	long	number;
	int		i;

	stack_a = NULL;
	i = 1;

	while (i < argc)
	{
		is_valid_number_format(argv[i]);
		number = ft_atol_safe(argv[i]);
		is_in_int_range(number);
		new_node = stack_new((int)number);
		if (!new_node)
		{
			free_stack(&stack_a);
			error_exit();
		}
		stack_add_back(&stack_a, new_node);
		i++;
	}
	if(has_duplicates(stack_a))
	{
		free(&stack_a);
		error_exit();
	}
	return (stack_a);
}