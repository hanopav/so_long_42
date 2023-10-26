/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:27:27 by phanosek          #+#    #+#             */
/*   Updated: 2023/08/06 14:25:36 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned char	i;
	unsigned char	str;

	i = 0;
	str = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[i] != '\0' && (str + 1) < (unsigned char)size)
	{
		dst[str] = src[i];
		i++;
		str++;
	}
	dst[str] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
