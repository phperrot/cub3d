/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:52:18 by phperrot          #+#    #+#             */
/*   Updated: 2019/11/18 17:13:43 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_occur(const char *s, char c)
{
	int i;
	int nb;
	int is_char;
	int is_string;

	i = 0;
	nb = 0;
	is_char = 1;
	is_string = 0;
	while (s[i])
	{
		if (s[i] != c && !is_string)
		{
			is_string = 1;
			is_char = 0;
			nb++;
		}
		if (s[i] == c && !is_char)
		{
			is_string = 0;
			is_char = 1;
		}
		i++;
	}
	return (nb);
}

static int	get_start(int i, const char *s, char c, int tab[])
{
	int is_string;
	int start;

	start = 0;
	is_string = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\0' && s[i] != c && !is_string)
		{
			is_string = 1;
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[0] = i - start;
			break ;
		}
		i++;
	}
	return (start);
}

static char	**ft_check(char const *s, char c)
{
	int		check;
	char	**tab_str;

	check = 0;
	if (!(tab_str = (char**)malloc(sizeof(char *) * 1)))
		return (NULL);
	if (!s && !c)
	{
		tab_str[0] = ft_strdup("");
		return (tab_str);
	}
	while (s[check++] == c)
	{
		if (s[check] == '\0')
		{
			tab_str[0] = NULL;
			return (tab_str);
		}
	}
	return (0);
}

static char	**ft_loop(char const *s, char c, int *tab, char **tab_str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < ft_nb_occur(s, c))
	{
		k = 0;
		j = get_start(j, s, c, tab);
		if (!(tab_str[i] = (char*)malloc(sizeof(char) * (tab[0] + 1))))
			return (NULL);
		while (k < tab[0])
		{
			tab_str[i][k] = s[j];
			k++;
			j++;
		}
		tab_str[i][k] = '\0';
		i++;
	}
	tab_str[i] = 0;
	return (tab_str);
}

char		**ft_split(char const *s, char c)
{
	int		tab[1];
	char	**tab_str;

	if (!s)
		return (NULL);
	if (ft_check(s, c) != 0)
		return (ft_check(s, c));
	if (ft_strncmp(s, "", 1) == 0)
	{
		if (!(tab_str = (char**)malloc(sizeof(char *) * 1)))
			return (NULL);
		tab_str[0] = NULL;
		return (tab_str);
	}
	if (!(tab_str = (char**)malloc(sizeof(char *) * (ft_nb_occur(s, c) + 1))))
		return (NULL);
	return (ft_loop(s, c, tab, tab_str));
}
