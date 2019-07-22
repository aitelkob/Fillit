/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:02:52 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/06 18:32:48 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (n--)
	{
		*s1 = *s2;
		if (*s1 == (unsigned char)c)
		{
			return (s1 + 1);
		}
		s1++;
		s2++;
	}
	return (0);
}
