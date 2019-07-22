/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:09:21 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/22 16:13:54 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c;
	char	*c1;
	size_t	i;

	i = 0;
	c = (char *)dst;
	c1 = (char *)src;
	if (n == 0 || dst == src)
	{
		return (dst);
	}
	while (n--)
	{
		c[i] = c1[i];
		i++;
	}
	return (dst);
}
