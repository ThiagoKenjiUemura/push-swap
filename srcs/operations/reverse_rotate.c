/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:10:32 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/22 09:55:55 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_r(t_list **stack)
{
	t_list	*last_node;
	t_list	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = *stack;
	prev = NULL;
	while (last_node->next)
	{
		prev = last_node;
		last_node = last_node -> next;
	}
	last_node->next = *stack;
	*stack = last_node;
	prev->next = NULL;
}

void	rra(t_list **a)
{
	rev_r(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rev_r(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rev_r(a);
	rev_r(b);
	write(1, "rrr\n", 4);
}
