/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:19:26 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/21 20:27:45 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = strlen(s) + 1;
	dup = calloc(len, 1);
	if (!dup)
		return (NULL);
	strlcpy(dup, s, len);
	return (dup);
}
