/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:02:07 by phanosek          #+#    #+#             */
/*   Updated: 2023/01/18 16:41:03 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	char	*s;
// 	char	*d;

// 	s = (char *)src;
// 	d = (char *)dst;
// 	if (dst == src)
// 		return (dst);
// 	if (s < d)
// 	{
// 		while (len)
// 		{
// 			*(d + len) = *(s + len);
// 			len--;
// 		}
// 		return (dst);
// 	}
// 	while (len)
// 	{
// 		*d = *s;
// 		d++;
// 		s++;
// 		len--;
// 	}
// 	return (dst);
// }

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len != 0)
		{
			len--;
			*(d + len) = *(s + len);
		}
		return (dst);
	}
	while (len != 0)
	{
		*d = *s;
		len--;
		d++;
		s++;
	}
	return (dst);
}
