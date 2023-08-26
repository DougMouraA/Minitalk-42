/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglasmoura <douglasmoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:40:29 by douglasmour       #+#    #+#             */
/*   Updated: 2022/06/19 19:40:29 by douglasmour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*result_string(const char *s1, const char *s2)
{
	size_t	j;

	j = 0;
	if (s2[j] == '\0')
		return ((char *)(s1));
	return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	start_comp;

	i = 0;
	j = 0;
	start_comp = 0;
	while (i < n && s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
		{
			j = 0;
			i = start_comp + 1;
			start_comp = i;
		}
		if (s1[i] == s2[j] & start_comp < n)
		{
			i++;
			j++;
		}
	}
	return (result_string(&s1[start_comp], &s2[j]));
}
