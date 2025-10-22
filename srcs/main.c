/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:22:31 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/10/21 22:04:07 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	check_rep(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
				error_exit();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		total_size;

	a = NULL;
	b = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		error_exit();
	total_size = input(argc, argv, &a);
	check_rep(&a);
	if (!is_sorted(&a))
		sorted(&a, &b, total_size);
	cleanup(&a, &b);
	return (0);
}