/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:58:53 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/09 02:33:47 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_len_malloc(int n)
{
	int		i;
	int		neg;

	i = 1;
	neg = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n = -n;
		neg++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + neg);
}

static void	ft_swap(char *str)
{
	int		i;
	int		x;
	char	swap;
	int		size;

	size = ft_strlen(str);
	i = 0;
	x = size - 1;
	if (str[0] == '-')
		i++;
	while (i < x)
	{
		swap = str[i];
		str[i] = str[x];
		str[x] = swap;
		i++;
		x--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = -1;
	str = ft_calloc(sizeof (char), ft_len_malloc(n));
	if (n == -2147483648)
	{
		(ft_strlcpy(str, "-2147483648", 12));
		return (str);
	}
	if (n < 0)
	{
		str[++i] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[++i] = (n % 10) + 48;
		n = n / 10;
	}
	if (str[0] == 0)
		str[0] = '0';
	ft_swap(str);
	return (str);
}
