/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:18:45 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/22 09:44:36 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
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
