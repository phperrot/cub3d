/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:58 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 14:28:50 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		ft_abs(double x)
{
	if (x < 0)
		x = -x;
	return (x);
}

int			count_char(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char		*withdraw_char(char *str, char c)
{
	int		i;
	int		j;
	int		new_len;
	int		old_len;
	char	*new_str;

	old_len = ft_strlen(str);
	new_len = old_len - count_char(str, c);
	if (!(new_str = malloc(sizeof(char) * (new_len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < old_len)
	{
		if (str[i] != c)
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

t_map		*ft_lstlast_map(t_map *lst)
{
	t_map	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
