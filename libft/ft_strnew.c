/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:17:33 by sberrich          #+#    #+#             */
/*   Updated: 2019/05/10 00:11:56 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tab;

	if (!(tab = (char *)malloc(size + 1)))
		return (NULL);
	else
		ft_bzero(tab, size + 1);
	return (tab);
}
