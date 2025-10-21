/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:19:09 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/21 20:27:34 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned const char *)src)[n];
	}
	else
		memcpy(dest, src, n);
	return (dest);
}
