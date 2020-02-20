/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:27:15 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/20 08:37:05 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_square(t_env env, int x, int y, int color)
{
	int i;
	int j;
	int width;
	int height;

	i = x;
	j = y;
	height = MINIMAP_SIZE;
	width = height;
	while (i < width + x)
	{
		j = y;
		while (j < height + y)
		{
			ft_put_pixel(env.img, color, j, i);
			j++;
		}
		i++;
	}
}

int		get_color_minimap(t_env env, int i, int j)
{
	int color;

	if (env.map[i][j] == '1')
		color = COLOR_MAP_WALL;
	if (ft_strchr("23", env.map[i][j]))
		color = COLOR_MAP_SPRITE;
	if (ft_strchr("NSEW0FQ", env.map[i][j]))
		color = COLOR_MAP_FLOOR;
	if (ft_strchr("D", env.map[i][j]))
		color = COLOR_MAP_DOOR;
	if (ft_strchr("P", env.map[i][j]))
		color = COLOR_MAP_SECRET_DOOR;
	if (ft_strchr("B", env.map[i][j]))
		color = COLOR_MAP_BONUS;
	if (ft_strchr("A", env.map[i][j]))
		color = COLOR_MAP_AMMO;
	if (ft_strchr("O", env.map[i][j]))
		color = COLOR_MAP_ENNEMY;
	if (ft_strchr("T", env.map[i][j]))
		color = COLOR_MAP_TREASURE;
	return (color);
}

void	init_minimap(t_env env)
{
	int i;
	int j;
	int color;
	int offset_x;

	if (!env.minimap)
		return ;
	offset_x = env.width / 2 - (ft_strlen(env.map[0]) * MINIMAP_SIZE) / 2;
	i = 0;
	while (i < env.map_height)
	{
		j = 0;
		while (env.map[i][j] != '\0')
		{
			color = get_color_minimap(env, i, j);
			draw_square(env, i * MINIMAP_SIZE, offset_x +\
			j * MINIMAP_SIZE, color);
			j++;
		}
		i++;
	}
	draw_square(env, (env.player_y - 0.5) * \
	MINIMAP_SIZE, offset_x + (env.player_x) * MINIMAP_SIZE, COLOR_MAP_PLAYER);
}
