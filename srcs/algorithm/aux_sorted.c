/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:17:47 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/22 09:56:33 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_pos(t_list **b, int max_index, int size)
{
	t_list	*p;
	int		index;
	int		found;

	index = 0;
	found = 0;
	p = *b;
	while (p && !found)
	{
		if (p->index == max_index)
			found = 1;
		else
			index++;
		p = p->next;
	}
	if (index < size / 2 + size % 2)
		return (0);
	else
		return (1);
}

int	min_pos(t_list **a, int min, int size)
{
	t_list	*p;
	int		min_index;
	int		found;

	min_index = 0;
	found = 0;
	p = *a;
	while (p != NULL && !found)
	{
		if (p->number == min)
			found = 1;
		else
			min_index++;
		p = p->next;
	}
	if (min_index < size / 2 + size % 2)
		return (0);
	else
		return (1);
}

void	set_index(t_list **a)
{
	t_list	*current;
	t_list	*comparer;
	int		index;

	current = *a;
	while (current)
	{
		comparer = *a;
		index = 0;
		while (comparer)
		{
			if (current->number > comparer->number)
				index++;
			comparer = comparer->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	sorted_pa(t_list **a, t_list **b)
{
	int	max;
	int	size_b;

	max = 0;
	size_b = 0;
	while (*b != NULL)
	{
		max = index_max(b);
		size_b = lst_size(*b);
		if ((*b)->index != max)
		{
			if (!max_pos(b, max, size_b))
				rb(b);
			else
				rrb(b);
		}
		else
			pa(a, b);
	}
}

int	index_max(t_list **a)
{
	int		max_index;
	t_list	*p;

	p = *a;
	max_index = p->index;
	p = p->next;
	while (p != NULL)
	{
		if (max_index < p->index)
			max_index = p->index;
		p = p->next;
	}
	return (max_index);
}
