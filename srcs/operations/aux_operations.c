/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:17:57 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/22 09:56:07 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_min(t_list **a)
{
	int		min;
	t_list	*p;

	min = (*a)->number;
	p = (*a)->next;
	while (p != NULL)
	{
		if (p->number < min)
			min = p->number;
		p = p->next;
	}
	return (min);
}

int	n_max(t_list **a)
{
	int		max;
	t_list	*p;

	max = (*a)->number;
	p = (*a)->next;
	while (p != NULL)
	{
		if (p->number > max)
			max = p->number;
		p = p->next;
	}
	return (max);
}
