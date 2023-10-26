/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:38:20 by phanosek          #+#    #+#             */
/*   Updated: 2023/01/16 16:09:03 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (str == 0)
		return (NULL);
	while (i < n)
	{
		if (*(unsigned char *)(str + i) == (unsigned char )c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
