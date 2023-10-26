/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:37:43 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/25 19:53:18 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// static unsigned int	count_strings(const char *s, char c)
// {
// 	unsigned int	res;
// 	int				i;

// 	res = 0;
// 	i = 0;
// 	while (s[i] != 0)
// 	{
// 		if (s[i] != c)
// 		{
// 			res++;
// 			while (s[i] != 0 && s[i] != c)
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (res);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char			**ret;
// 	unsigned int	i;
// 	unsigned int	len;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	ret = malloc(sizeof(char *) * (count_strings(s, c) + 1));
// 	if (ret == 0)
// 		return (0);
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			len = 0;
// 			while (*s && *s != c && ++len)
// 				s++;
// 			ret[i++] = ft_substr(s - len, 0, len);
// 		}
// 		else
// 			s++;
// 	}
// 	ret[i] = 0;
// 	return (ret);
// }

#include "libft.h"

static int	wordcounter(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static char	*stringreturn(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_free(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		string;

	string = wordcounter(s, c);
	i = 0;
	ret = malloc(sizeof(char **) * (string + 1));
	if (!ret || !s)
		return (NULL);
	while (i < string)
	{
		while (*s == c)
			s++;
		ret[i] = stringreturn(s, c);
		if (ret[i] == NULL)
			ft_free(ret, i);
		s += ft_strlen(ret[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
