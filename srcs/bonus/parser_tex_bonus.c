/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:25:51 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 16:41:25 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			check_path(t_arg *arg, char *buff)
{
	char	*orientation;
	int		i;

	if (ft_strlen(buff) < 1)
		return (PATH_ERROR);
	orientation = ft_strsub(buff, 0, 2);
	i = 2;
	while (ft_strchr(INVISI_CHAR, buff[i]))
		i++;
	if (!ft_strncmp("NO", orientation, 2))
	{
		if (ft_strlen(arg->no))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->no = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	if (!ft_strncmp("SO", orientation, 2))
	{
		if (ft_strlen(arg->so))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->so = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	return (check_path1(orientation, buff, i, arg));
}

int			check_path1(char *orientation, char *buff, int i, t_arg *arg)
{
	if (!ft_strncmp("WE", orientation, 2))
	{
		if (ft_strlen(arg->we))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->we = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	if (!ft_strncmp("EA", orientation, 2))
	{
		if (ft_strlen(arg->ea))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->ea = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	if (!ft_strncmp("S ", orientation, 2))
	{
		if (ft_strlen(arg->sprite))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->sprite = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	if (!ft_strncmp("S1", orientation, 2))
	{
		if (ft_strlen(arg->sprite1))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->sprite1 = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	return (check_path2(orientation, buff, i, arg));
}

int			check_path2(char *orientation, char *buff, int i, t_arg *arg)
{
	if (!ft_strncmp("D ", orientation, 2))
	{
		if (ft_strlen(arg->door))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->door = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	if (!ft_strncmp("B ", orientation, 2))
	{
		if (ft_strlen(arg->bonus))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->bonus = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	if (!ft_strncmp("A ", orientation, 2))
	{
		if (ft_strlen(arg->ammo))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->ammo = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	if (!ft_strncmp("O ", orientation, 2))
	{
		if (ft_strlen(arg->ennemy))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->ennemy = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	return (check_path3(orientation, buff, i, arg));
}

int			check_path3(char *orientation, char *buff, int i, t_arg *arg)
{
	if (!ft_strncmp("T ", orientation, 2))
	{
		if (ft_strlen(arg->treasure))
			return (ft_error_tex_inputs(PATH_ERROR, orientation));
		arg->treasure = ft_strsub(buff, i, ft_strlen(buff) - i);
	}
	free(orientation);
	return (SUCCESS);
}
