/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 02:36:42 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/05 22:56:10 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void *s1, const void *s2, size_t n)
{
	const unsigned char *str;
	const unsigned char *ptr;
	size_t				i;

	str = (const unsigned char*)s1;
	ptr = (const unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (str[i] == ptr[i])
			i++;
		else
			return (str[i] - ptr[i]);
	}
	return (0);
}
