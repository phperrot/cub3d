/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:30:07 by phperrot          #+#    #+#             */
/*   Updated: 2019/12/04 11:06:09 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char					*ft_strsub_gnl(char *str, int start, int len)
{
	int					i;
	char				*output;

	i = 0;
	if (!str)
		return (NULL);
	if (!(output = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && (str[start + i] != '\n'))
	{
		output[i] = str[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

size_t					ft_strlen_gnl(const char *s)
{
	int					i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char					*ft_strchr_gnl(const char *s, int c)
{
	int					i;
	char				*tmp;

	i = 0;
	tmp = (char *)s;
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (*tmp)
			tmp++;
		return ((char*)tmp);
	}
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			return ((char *)&tmp[i]);
		i++;
	}
	if (*tmp == '\0' && c == '\0')
	{
		return (tmp);
	}
	return (NULL);
}

char					*ft_strdup_gnl(const char *s1)
{
	char				*output;
	int					i;
	int					size;

	if (!s1)
		return (NULL);
	size = ft_strlen_gnl(s1);
	if (!(output = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while ((char)s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char					*ft_strjoin_gnl(char const *s1, char const *s2)
{
	unsigned long		i;
	char				*output;
	unsigned long		size1;
	unsigned long		size2;

	if (!(s1 && s2))
		return (NULL);
	size1 = ft_strlen_gnl(s1);
	size2 = ft_strlen_gnl(s2);
	if (!(output = malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	i = 0;
	while (i < size1)
	{
		output[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		output[i] = s2[i - size1];
		i++;
	}
	output[i] = '\0';
	return (output);
}
