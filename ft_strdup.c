/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:12:36 by phanosek          #+#    #+#             */
/*   Updated: 2023/01/18 16:06:00 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		len;

	len = ft_strlen(s) + 1;
	ret = malloc(len * sizeof(char));
	if (ret == 0)
		return (NULL);
	ret = ft_memcpy(ret, s, len);
	return (ret);
}
