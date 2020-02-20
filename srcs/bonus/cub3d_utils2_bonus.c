/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:26:33 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 14:29:55 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_map		*ft_lstnew_map(void *content)
{
	t_map	*elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem->line = content;
	elem->next = NULL;
	return (elem);
}

void		ft_lstadd_back_map(t_map **alst, t_map *new)
{
	t_map	*tmp;

	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
		(ft_lstlast_map(*alst))->next = new;
}

void		ft_lstclear_map(t_map **lst)
{
	t_map	*tmp;
	t_map	*next;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

int			ft_lstsize_map(t_map *lst)
{
	t_map	*tmp;
	int		i;

	i = 0;
	if (!lst)
		return (i);
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char		**from_lst_to_tab(t_map *lst)
{
	t_map	*tmp;
	int		i;
	int		j;
	char	**tab;

	tmp = lst;
	if (!(tab = malloc(sizeof(char*) * (ft_lstsize_map(lst) + 1))))
		return (NULL);
	i = 0;
	while (i < ft_lstsize_map(lst))
	{
		if (!(tab[i] = malloc(sizeof(char) * (ft_strlen(tmp->line) + 1))))
			return (NULL);
		j = 0;
		while (tmp->line[j] != '\0')
		{
			tab[i][j] = tmp->line[j];
			j++;
		}
		tab[i][j] = '\0';
		tmp = tmp->next;
		i++;
	}
	return (tab);
}
