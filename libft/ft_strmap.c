/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:49:29 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/07 14:57:59 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	l;
	char	*r;

	if (s)
	{
		l = ft_strlen(s);
		if (!(r = (char *)malloc(l + 1)))
			return (NULL);
		i = 0;
		while (i < l)
		{
			r[i] = f(s[i]);
			i++;
		}
		r[i] = '\0';
		return (r);
	}
	return (NULL);
}
