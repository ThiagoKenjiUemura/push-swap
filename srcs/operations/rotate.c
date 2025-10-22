/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:11:02 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/22 09:55:41 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	*stack = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	ra(t_list **a)
{
	r(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	r(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	r(a);
	r(b);
	write(1, "rr\n", 3);
}
