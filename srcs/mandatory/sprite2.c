/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:10:27 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 16:59:37 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			sprite_count(t_env *env)
{
	int		x;
	int		y;
	int		result;
	int		ennemy;

	y = 0;
	result = 0;
	ennemy = 0;
	while (y < env->map_height)
	{
		x = 0;
		while (env->map[y][x])
		{
			if (ft_strchr("23ABDOT", env->map[y][x]))
				result++;
			if (env->map[y][x] == 'O')
				ennemy++;
			x++;
		}
		y++;
	}
	env->ennemy_count = ennemy;
	return (result);
}

void		add_sprite(t_env *env)
{
	int		i;
	int		height;

	i = 0;
	height = 256;
	while (i < env->sprite_count)
	{
		ft_sprite_calc(env, i);
		env->sprite.stripe = env->sprite.drawstart_x;
		while (env->sprite.stripe < env->sprite.drawend_x)
		{
			env->sprite.sp_x = (int)(height * (env->sprite.stripe\
			- (-env->sprite.sprite_width / 2 + env->sprite.spritescreenx)) * \
			env->sprite_tab[i].tex->width / env->sprite.sprite_width / height);
			add_sprite_two(env, i);
			env->sprite.stripe++;
		}
		i++;
	}
}

void		ft_sort(int *order, double *dist, int num, t_env *env)
{
	int		i;
	int		temp;
	double	temp2;
	t_tex	*temp3;

	i = 0;
	while (i < num - 1)
	{
		if (dist[i] < dist[i + 1])
		{
			temp3 = env->sprite_tab[i + 1].tex;
			env->sprite_tab[i + 1].tex = env->sprite_tab[i].tex;
			env->sprite_tab[i].tex = temp3;
			temp2 = dist[i + 1];
			dist[i + 1] = dist[i];
			dist[i] = temp2;
			temp = order[i + 1];
			order[i + 1] = order[i];
			order[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void		ft_order_sprite(t_env *env)
{
	int		i;

	i = 0;
	env->sprite_count = sprite_count(env);
	while (i < env->sprite_count)
	{
		env->ray.sp_order[i] = i;
		env->ray.sp_distance[i] = ((env->player_x - env->sprite_tab[i].pos_x) *
			(env->player_x - env->sprite_tab[i].pos_x) +
			(env->player_y - env->sprite_tab[i].pos_y) *
			(env->player_y - env->sprite_tab[i].pos_y));
		i++;
	}
	ft_sort(env->ray.sp_order, env->ray.sp_distance, env->sprite_count, env);
	add_sprite(env);
}

void		get_ennemy_sprite(t_env *env, int i)
{
	env->count_ennemy_gif++;
	if (env->count_ennemy_gif > 9)
		env->count_ennemy_gif = 1;
	if (env->count_ennemy_gif == 1)
		env->tex_ennemy = env->tex_ennemy_1;
	if (env->count_ennemy_gif == 2)
		env->tex_ennemy = env->tex_ennemy_2;
	if (env->count_ennemy_gif == 3)
		env->tex_ennemy = env->tex_ennemy_3;
	if (env->count_ennemy_gif == 4)
		env->tex_ennemy = env->tex_ennemy_4;
	if (env->count_ennemy_gif == 5)
		env->tex_ennemy = env->tex_ennemy_5;
	if (env->count_ennemy_gif == 6)
		env->tex_ennemy = env->tex_ennemy_6;
	if (env->count_ennemy_gif == 7)
		env->tex_ennemy = env->tex_ennemy_7;
	if (env->count_ennemy_gif == 8)
		env->tex_ennemy = env->tex_ennemy_8;
	if (env->count_ennemy_gif == 9)
		env->tex_ennemy = env->tex_ennemy_9;
	env->sprite_tab[i].tex = env->tex_ennemy;
	env->sprite_tab[i].tex->width = env->tex_ennemy->width;
	env->sprite_tab[i].tex->height = env->tex_ennemy->height;
}
