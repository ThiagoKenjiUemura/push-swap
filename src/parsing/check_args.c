/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:52:41 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/10/17 17:11:43 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		error_exit();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_exit();
		i++;
	}
	return (1);
}

long	ft_atol_safe(const char *nptr)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_in_int_range(long number)
{
	if (number > INT_MAX || number < INT_MIN)
		error_exit();
	return (1);
}

int	has_duplicates(t_stack *a)
{
	t_stack *current;
	t_stack *runner;
	
	current = a;
	while (current != NULL)
	{
		runner = current -> next;
		while (runner != NULL)
		{
			if(current -> value == runner -> value)
				return (1);
			runner = runner -> next;
		}
		current = current ->next;
	}
	return (0);
}
