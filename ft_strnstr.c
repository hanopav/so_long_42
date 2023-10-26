/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:07:32 by phanosek          #+#    #+#             */
/*   Updated: 2023/01/17 15:14:45 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	i;
// 	size_t	j;

// 	if (!haystack || !needle)
// 		return (NULL);
// 	if (!needle || !needle[0])
// 		return ((char *)haystack);
// 	i = 0;
// 	while (haystack[i] && i < len)
// 	{
// 		j = 0;
// 		while (haystack[i + j] && needle[j] &&
// 				i + j < len && haystack[i + j] == needle[j])
// 			j++;
// 		if (!needle[j])
// 			return ((char*)(haystack + i));
// 		i++;
// 	}
// 	return (NULL);
// }

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		a;

	i = 0;
	if (big == 0 || little == 0)
		return (NULL);
	if (little == 0 || little[0] == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		a = 0;
		while (big [i + a] && little[a]
			&& i + a < len && big[i + a] == little[a])
			a++;
		if (!little[a])
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
