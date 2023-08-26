/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglasmoura <douglasmoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:50:22 by douglasmour       #+#    #+#             */
/*   Updated: 2022/06/19 19:50:47 by douglasmour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch);
	else if (ch >= 'A' && ch <= 'Z')
	{
		ch = ch + 32;
		return (ch);
	}
	else
		return (ch);
}
