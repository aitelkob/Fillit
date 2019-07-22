/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:42:56 by sberrich          #+#    #+#             */
/*   Updated: 2019/05/10 00:39:52 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;

	if (s1 && s2)
	{
		s1len = ft_strlen(s1);
		s2len = ft_strlen(s2);
		if (!(ptr = (char *)ft_memalloc(s1len + s2len + 1)))
			return (NULL);
		ft_strcat(ptr, s1);
		ft_strcat(ptr, s2);
		return (ptr);
	}
	return (NULL);
}
