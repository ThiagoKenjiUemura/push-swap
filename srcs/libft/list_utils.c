/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:18:58 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/21 20:19:01 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list *list)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = list;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	lst_add_back(t_list **a, t_list *new_node)
{
	t_list	*last;

	if (a == NULL || new_node == NULL)
		return ;
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void	cleanup(t_list **a, t_list **b)
{
	free_stack(a);
	free_stack(b);
}

void	free_stack(t_list **stack)
{
	t_list	*cur;
	t_list	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	cur = *stack;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*stack = NULL;
}

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
