/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:34:29 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/10/17 16:36:43 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		error_exit();
	while (stack -> next != NULL)
		stack = stack -> next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack *last_node;
	
	if(*stack == NULL)
	{
		*stack = new_node;
		error_exit();
	}
	last_node = stack_last(*stack);
	last_node -> next = new_node;
	new_node ->prev = last_node;
}

void	stack_add_front(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		error_exit();
	if (!stack)
	{
		*stack = new_node;
		error_exit();
	}
	
	new_node -> next = *stack;
	(*stack) -> prev = new_node;
	*stack = new_node;
}

t_stack	*stack_new(int value)
{
	t_stack *new_node;
	
	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node -> value = value;
	NEW_NODE -> index = 0;
	new_node -> prev = NULL;
	new_node -> next = NULL;
	return (new_node);
}
