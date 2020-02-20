/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:26:11 by phperrot          #+#    #+#             */
/*   Updated: 2019/12/21 14:25:53 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_head_size(char *s1, char *set)
{
	int i;
	int j;
	int set_size;

	i = 0;
	j = 0;
	set_size = 0;
	while (set[set_size] != '\0')
		set_size++;
	while (s1[i] != '\0')
	{
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if ((j == set_size) | (s1[i] == '\0'))
			return (i);
		else
		{
			i++;
			j = 0;
		}
	}
	return (0);
}

int		ft_tail_size(char const *s1, char const *set)
{
	int i;
	int j;

	i = (int)ft_strlen(s1) - 1;
	j = 0;
	while (i >= 0)
	{
		while (s1[i] != set[j] && set[j] != '\0')
		{
			j++;
		}
		if (j == (int)(ft_strlen(set)) | i == -1)
		{
			return (ft_strlen(s1) - (i + 1));
		}
		else
		{
			i--;
			j = 0;
		}
	}
	return (ft_strlen(s1));
}

char	*ft_empty_input(char const *s1, char const *set)
{
	if ((s1[0] == '\0') || (set[0] == '\0'))
		return ((char *)s1);
	else
		return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		malloc_size;
	int		i;
	char	*output;

	if (!s1 || !set)
		return (NULL);
	if ((ft_empty_input(s1, set)) != NULL)
		return (ft_empty_input(s1, set));
	malloc_size = ft_strlen((char*)s1) - \
				ft_head_size((char*)s1, (char*)set) - ft_tail_size(s1, set);
	if (malloc_size > 0)
	{
		if (!(output = malloc(sizeof(char) * (malloc_size + 1))))
			return (0);
	}
	else
		return (ft_strdup(""));
	i = 0;
	while (i < malloc_size)
	{
		output[i] = s1[ft_head_size((char*)s1, (char*)set) + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
