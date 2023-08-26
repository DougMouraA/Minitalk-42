/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:57:30 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/06/15 14:57:30 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*sr1;
	char	*sr2;

	i = 0;
	sr1 = (void *)src;
	sr2 = (void *)dest;
	if (!sr1 && !sr2)
		return (0);
	while (i < n)
	{
		sr2[i] = sr1[i];
		i++;
	}
	return (sr2);
}
