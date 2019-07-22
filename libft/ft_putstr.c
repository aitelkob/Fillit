/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:24:56 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/10 20:01:51 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	unsigned char	*r;
	size_t			i;

	if (s)
	{
		r = (unsigned char*)s;
		i = 0;
		while (s[i])
		{
			ft_putchar(r[i]);
			i++;
		}
	}
}
