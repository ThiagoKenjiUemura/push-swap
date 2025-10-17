/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:50:07 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/10/17 17:11:32 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current_node;
	t_stack	*next_node;

	if (!stack || !*stack)
		error_exit();
	current_node = *stack;
	while (current_node != NULL)
	{
		next_node = current_node -> next;
		free(current_node);
		current_node = next_node;
	}
	*stack = NULL;
}
