/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:17:51 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/22 09:56:50 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted(t_list **a, t_list **b, int size)
{
	if (size >= 2 && size <= 5)
	{
		if (size == 2)
			sorted_2(a);
		else if (size == 3)
			sorted_3(a);
		else if (size == 4 || size == 5)
			sorted_4_5(a, b, size);
	}
	if (size >= 6)
	{
		set_index(a);
		if (size <= 100)
			sorted_big(a, b, 15);
		else
			sorted_big(a, b, 30);
	}
}

void	sorted_2(t_list **a)
{
	if ((*a)->next->number < (*a)->number)
		sa(a);
}

void	sorted_3(t_list **a)
{
	if ((*a)->number == n_max(a))
	{
		ra(a);
		if ((*a)->number > (*a)->next->number)
			sa(a);
	}
	else if ((*a)->number == n_min(a) && (*a)->next->number == n_max(a))
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->number != n_min(a) && (*a)->number > (*a)->next->number)
		sa(a);
	else if ((*a)->number != n_min(a) && (*a)->number < (*a)->next->number)
		rra(a);
}

void	sorted_4_5(t_list **a, t_list **b, int size)
{
	int	i;

	i = 0;
	while (i < size / 2 + size % 2)
	{
		if ((*a)->number > n_min(a) && !min_pos(a, n_min(a), lst_size(*a)))
			ra(a);
		else if ((*a)->number > n_min(a) && min_pos(a, n_min(a), lst_size(*a)))
			rra(a);
		else if ((*a)->number == n_min(a))
		{
			pb(a, b);
			i++;
		}
	}
	if ((*a)->number != n_min(a))
		sa(a);
	while ((*b))
		pa(a, b);
}

void	sorted_big(t_list **a, t_list **b, int chunk_size)
{
	int	i;

	i = 0;
	while ((*a) != NULL)
	{
		if (i > 0 && (*a)->index < i)
		{
			pb(a, b);
			if ((*a) && (*a)->index >= i + chunk_size)
				rr(a, b);
			else
				rb(b);
			i++;
		}
		else if ((*a)->index < i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index >= i + chunk_size)
			ra(a);
	}
	sorted_pa(a, b);
}
