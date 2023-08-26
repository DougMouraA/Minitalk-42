/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglasmoura <douglasmoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:51:07 by douglasmour       #+#    #+#             */
/*   Updated: 2022/06/19 19:53:00 by douglasmour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_toupper(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return (ch);
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		ch = ch - 32;
		return (ch);
	}
	else
	{
		return (ch);
	}
}
