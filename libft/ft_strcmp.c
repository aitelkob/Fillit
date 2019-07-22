/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:42:58 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/07 19:28:30 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *a1;
	unsigned char *a2;

	a2 = (unsigned char *)s2;
	a1 = (unsigned char *)s1;
	while ((*a1) && *a1 == *a2)
	{
		++a1;
		++a2;
	}
	return (*a1 - *a2);
}
