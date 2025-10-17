/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:20:31 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/10/17 18:44:55 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *first_node;
	t_stack *second_node;

	if(!stack || !*stack || !(*stack)-> next)
		return;
	first_node = *stack;
	second_node = first_node -> next;
	first_node -> next = second_node-> next;
	if(second_node -> next != NULL)
		second_node -> next -> prev = first_node;
	second_node -> prev = NULL;
	second_node ->next = first_node;
	first_node -> prev = second_node;
	*stack = second_node;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}
void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
