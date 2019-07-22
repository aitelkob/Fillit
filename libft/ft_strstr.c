/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:26:01 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/19 22:19:20 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*src;
	size_t	size;

	src = (char *)haystack;
	size = ft_strlen(needle);
	if (size == 0)
		return (src);
	while (*src)
	{
		if (ft_strncmp(src, needle, size) == 0)
			return (src);
		src++;
	}
	return (NULL);
}
