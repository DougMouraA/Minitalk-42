/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglasmoura <douglasmoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:45:16 by douglasmour       #+#    #+#             */
/*   Updated: 2022/06/19 19:48:11 by douglasmour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	verify(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*substr;

	size = len;
	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		size = 0;
	else if (len >= ft_strlen(&s[start]))
		size = ft_strlen(&s[start]);
	substr = (char *)malloc(size + 1);
	if (!substr)
		return (NULL);
	while (i < size)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

static char	*string_null(void)
{
	char	*newstring;

	newstring = (char *)malloc(1);
	if (!newstring)
		return (0);
	*(newstring) = '\0';
	return (newstring);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	pns;
	char	*newstr;

	i = 0;
	if (!s1)
		return (0);
	j = ft_strlen(s1) - 1;
	pns = 0;
	while (verify(s1[i], set) == 0 && i < ft_strlen(s1))
			i++;
	while (verify(s1[j], set) == 0 && j > 0)
		j--;
	if (i > j || (i == 0 && j == 0))
		return (string_null());
	newstr = ft_substr(s1, i, j - i + 1);
	if (!newstr)
		return (0);
	return (newstr);
}
