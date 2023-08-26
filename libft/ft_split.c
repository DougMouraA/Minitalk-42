/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglasmoura <douglasmoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:01:27 by sdos-san          #+#    #+#             */
/*   Updated: 2022/06/19 20:06:53 by douglasmour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*substr;

	i = 0;
	if (ft_strlen(&s[start]) > len)
		size = len;
	else
		size = ft_strlen(&s[start]);
	substr = (char *)malloc(size + 1);
	if (!substr)
		return (0);
	while (i < size)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

static char	**malloc_array(char const *s, char c)
{
	size_t	size;
	size_t	pos;
	size_t	check_div;
	char	**ptr;

	size = 0;
	pos = 0;
	check_div = 1;
	while (*(s + pos))
	{
		if (check_div == 1 && *(s + pos) != c)
		{
			check_div = 0;
			size++;
		}
		else if (*(s + pos) == c)
			check_div = 1;
		pos++;
	}
	ptr = (char **)malloc(sizeof(char **) * (size + 1));
	if (!ptr)
		return (0);
	ptr[size] = 0;
	return (ptr);
}

static char	*malloc_strings(char const *s, char c)
{
	size_t	size;
	size_t	i;
	char	*ptr;

	size = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			size++;
		else if (s[i] == c && size > 0)
			break ;
		i++;
	}
	ptr = ft_substr(s, 0, size);
	if (!ptr)
		return (0);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_str;
	size_t	i_array;
	size_t	i;

	i = 0;
	i_array = 0;
	if (!s)
		return (0);
	str_str = malloc_array(s, c);
	if (!str_str)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			str_str[i_array] = malloc_strings(s + i, c);
			i = i + ft_strlen(str_str[i_array]);
			i_array++;
		}
		else
			i++;
	}
	return (str_str);
}
