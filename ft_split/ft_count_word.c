/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:33:37 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/19 12:33:41 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_word(char const *s, char *charset)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_in_charset(charset, s[i]))
		{
			count++;
			while (s[i] && !ft_in_charset(charset, s[i]))
				i++;
			i--;
		}
		i++;
	}
	return (count);
}
