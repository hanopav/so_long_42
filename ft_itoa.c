/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:30:17 by phanosek          #+#    #+#             */
/*   Updated: 2023/02/02 12:51:30 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_length(int nbr)
{
	unsigned int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len += 1;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*ret;
	unsigned int	nbr;

	len = num_length(n);
	ret = malloc(sizeof(char *) * (len + 1));
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr == 0)
		ret[0] = '0';
	ret[len] = '\0';
	while (nbr != 0)
	{
		ret[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (ret);
}

// char	*ft_itoa(int n)
// {
// 	char		*string;
// 	unsigned int	number;
// 	unsigned int	length;

// 	length = num_length(n);
// 	string = (char *)malloc(sizeof(char) * (length + 1));
// 	if (string == NULL)
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		string[0] = '-';
// 		number = -n;
// 	}
// 	else
// 		number = n;
// 	if (number == 0)
// 		string[0] = '0';
// 	string[length] = '\0';
// 	while (number != 0)
// 	{
// 		string[length - 1] = (number % 10) + '0';
// 		number = number / 10;
// 		length--;
// 	}
// 	return (string);
// }

// char	*ft_itoa(int n)
// {
// 	unsigned int	len;
// 	char			*ret;
// 	unsigned int	nbr;

// 	len = num_length(n);
// 	ret = (char *)malloc(sizeof(char) * (len + 1));
// 	if (ret == NULL)
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		ret[0] = '-';
// 		nbr = -n;
// 	}
// 	else
// 		nbr = n;
// 	if (nbr == 0)
// 		ret[0] = '0';
// 	ret[len] = '\0';
// 	while (nbr != 0)
// 	{
// 		ret[len - 1] = (nbr % 10) + '0';
// 		nbr = nbr / 10;
// 		len--;
// 	}
// 	return (ret);
// }

// // #include "libft.h"

// // static unsigned int	num_length(int nbr)
// // {
// // 	unsigned int	len;

// // 	len = 0;
// // 	if (nbr == 0)
// // 		return (1);
// // 	if (nbr < 0)
// // 		len += 1;
// // 	while (nbr > 0)
// // 	{
// // 		nbr /= 10;
// // 		len++;
// // 	}
// // 	return (len);
// // }

// // char	*ft_itoa(int n)
// // {
// // 	char			*string;
// // 	unsigned int	number;
// // 	unsigned int	len;

// // 	len = num_length(n);
// // 	string = malloc(sizeof(char *) * (len + 1));
// // 	if (string == NULL)
// // 		return (NULL);
// // 	if (n < 0)
// // 	{
// // 		string[0] = '-';
// // 		number = -n;
// // 	}
// // 	else
// // 		number = n;
// // 	if (number == 0)
// // 		string[0] = '0';
// // 	string[len] = '\0';
// // 	while (number != 0)
// // 	{
// // 		string[len - 1] = (number % 10) + '0';
// // 		number = number / 10;
// // 		len--;
// // 	}
// // 	return (string);
// // }
