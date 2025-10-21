/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:18:45 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/21 20:27:23 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb && size && nmemb != (nmemb * size / size))
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	bzero(p, nmemb * size);
	return (p);
}
