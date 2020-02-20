/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:29:52 by phperrot          #+#    #+#             */
/*   Updated: 2019/12/04 13:14:12 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_find_nl(char **temp)
{
	char		*stock_long;
	char		*memory;

	memory = NULL;
	stock_long = ft_strdup_gnl((char*)temp);
	if (ft_strchr_gnl(*temp, '\n'))
	{
		free(stock_long);
		stock_long = NULL;
		stock_long = ft_strsub_gnl(*temp, 0, (ft_strlen_gnl(*temp)\
						- ft_strlen_gnl((char*)ft_strchr_gnl(*temp, '\n'))));
		memory = ft_strdup_gnl(ft_strchr_gnl(*temp, '\n') + 1);
		free(*temp);
		*temp = NULL;
		*temp = (char *)ft_strdup_gnl(stock_long);
	}
	free(stock_long);
	return (memory);
}

char			*ft_join_free_gnl(char *s1, char *s2)
{
	char		*tmp;

	tmp = ft_strdup_gnl(s1);
	free(s1);
	s1 = ft_strjoin_gnl(s2, tmp);
	free(tmp);
	free(s2);
	s2 = NULL;
	return (s1);
}

static int		ft_read(int fd, char **temp)
{
	char		buffer[BUFFER_SIZE + 1];
	int			check;
	int			ret;
	char		*tmp;

	ret = 1;
	check = 1;
	while ((ret > 0) && check == 1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		if (*temp)
		{
			tmp = ft_strdup_gnl(*temp);
			free(*temp);
			*temp = ft_strjoin_gnl(tmp, buffer);
			free(tmp);
		}
		else
			*temp = ft_strdup_gnl(buffer);
		check = ((ft_strchr_gnl(buffer, '\n')) ? 0 : 1);
	}
	return (ret);
}

int				str_free(char *str, int i)
{
	free(str);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	char		*temp;
	static char	*memor;
	int			ret;

	temp = ft_strdup_gnl("\0");
	ret = ft_read(fd, &temp);
	if (ret < 0 || fd < 0 || !(line) || BUFFER_SIZE <= 0)
		return (str_free(temp, -1));
	temp = (memor != NULL) ? ft_join_free_gnl(temp, memor) : temp;
	memor = NULL;
	if ((ret == 0 && !ft_strchr_gnl(temp, '\n') && !ft_strchr_gnl(memor, '\n')))
	{
		*line = ft_strdup_gnl(temp);
		return (str_free(temp, 0));
	}
	if (ret >= 0)
	{
		memor = ft_find_nl(&temp);
		*line = ft_strdup_gnl(temp);
	}
	return (str_free(temp, 1));
}
