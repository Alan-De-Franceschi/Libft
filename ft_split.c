/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:48:02 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/16 10:48:05 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, size_t *p)
{
	size_t		l;
	size_t		i;
	char		*word;

	l = 0;
	i = 0;
	while (s[*p] && s[*p] == c)
		(*p)++;
	while (s[*p + l] && s[*p + l] != c)
		l++;
	word = malloc(sizeof (char) * (l + 1));
	if (!word)
		return (NULL);
	while (i < l && s[*p])
	{
		word[i] = s[*p];
		i++;
		(*p)++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_word(char **tab, size_t index_err)
{
	size_t	i;

	i = 0;
	while (i < index_err)
	{
		free(tab[i]);
		i++;
	}
}

static size_t	fill_tab(char **tab, const char *s, size_t nb_word, char c)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (i < nb_word)
	{
		tab[i] = get_word(s, c, &z);
		if (!tab[i])
		{
			free_word(tab, i);
			return (1);
		}
		i++;
	}
	tab[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nb_word;
	size_t	err;

	if (!s)
		return (NULL);
	nb_word = count_word(s, c);
	tab = malloc(sizeof(char *) * (nb_word + 1));
	if (!tab)
		return (NULL);
	err = fill_tab(tab, s, nb_word, c);
	if (err)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}