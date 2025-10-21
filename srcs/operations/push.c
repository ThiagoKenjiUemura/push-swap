/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:47:05 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/10/21 20:32:41 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*node_to_move;

	node_to_move = *b;
	*b = node_to_move->next;
	node_to_move->next = *a;
	*a = node_to_move;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*node_to_move;
	
	node_to_move = *a;
	*a = node_to_move->next;
	node_to_move->next = *b;
	*b = node_to_move;
	write(1, "pb\n", 3);
}
