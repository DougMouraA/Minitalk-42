/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglasmoura <douglasmoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:26:38 by douglasmour       #+#    #+#             */
/*   Updated: 2022/06/19 19:26:38 by douglasmour      ###   ########.fr       */
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

static void	strcpys(char const *s, char *ns)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ns[i] = s[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	size;

	if (!s1)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = (char *)malloc(size);
	if (!newstr)
		return (NULL);
	strcpys(s1, newstr);
	strcpys(s2, &newstr[ft_strlen(s1)]);
	newstr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (newstr);
}
