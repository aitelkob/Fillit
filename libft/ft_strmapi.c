/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:58:11 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/07 16:18:01 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	l;
	char	*r;
	size_t	i;

	if (s)
	{
		l = ft_strlen(s);
		if (!(r = (char *)malloc(l + 1)))
			return (NULL);
		i = 0;
		while (*s)
		{
			r[i] = f(i, *s++);
			i++;
		}
		r[i] = '\0';
		return (r);
	}
	return (NULL);
}
