/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 00:32:31 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/01 00:39:16 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*j;
	unsigned char		c1;

	i = 0;
	j = (unsigned char *) s;
	c1 = (unsigned char) c;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (j[i] == c1)
			return (j + i);
		i++;
	}
	return (0);
}
