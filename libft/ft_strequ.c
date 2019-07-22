/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:23:27 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/07 19:46:59 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	if (s1 && s2)
	{
		i = ft_strcmp(s1, s2);
		if (i == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
