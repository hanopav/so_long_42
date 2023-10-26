/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:59:59 by phanosek          #+#    #+#             */
/*   Updated: 2023/01/23 16:32:14 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
// {
// 	char			*str;
// 	unsigned int	i;

// 	i = 0;
// 	if (!(str = ft_strdup(s)))
// 		return (NULL);
// 	while (str[i] != 0)
// 	{
// 		str[i] = (*f)(i, str[i]);
// 		i++;
// 	}
// 	return (str);
// }

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (0);
	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
