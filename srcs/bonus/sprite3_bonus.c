/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:10:57 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 17:01:43 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		calc_end_start(t_env *env)
{
	int		tmp;

	if (env->sprite.drawstart_y < 0)
		env->sprite.drawstart_y = 0;
	env->sprite.drawend_y = env->sprite.sprite_height / 2 + env->height / 2;
	if (env->sprite.drawend_y >= env->height)
		env->sprite.drawend_y = env->height - 1;
	env->sprite.sprite_width = abs((int)(env->height / (env->sprite.transy)))\
							* 0.85;
	env->sprite.drawstart_x = -env->sprite.sprite_width / 2 +\
	env->sprite.spritescreenx;
	if (env->sprite.drawstart_x < 0)
		env->sprite.drawstart_x = 0;
	env->sprite.drawend_x = env->sprite.sprite_width / 2 + \
	env->sprite.spritescreenx;
	if (env->sprite.drawend_x >= env->width)
		env->sprite.drawend_x = env->width - 1;
	tmp = env->sprite.drawend_x;
}

void		ft_sprite_calc(t_env *env, int i)
{
	double	inv;

	env->sprite.spcamx = 1 * (env->sprite_tab[env->ray.sp_order[i]].\
	pos_x - env->player_x);
	env->sprite.spcamy = env->sprite_tab[env->ray.sp_order[i]].pos_y\
	- env->player_y;
	inv = -1.0 / (env->ray.planex * env->ray.diry - env->ray.dirx *
		env->ray.planey);
	env->sprite.transx = inv * (env->ray.diry * env->sprite.spcamx - \
	env->ray.dirx * env->sprite.spcamy);
	env->sprite.transy = inv * (env->ray.planey * env->sprite.spcamx\
	- env->ray.planex * env->sprite.spcamy);
	env->sprite.spritescreenx = (int)((env->width / 2) * (1 +  \
	env->sprite.transx / env->sprite.transy));
	env->sprite.sprite_height = abs((int)(env->height / env->sprite.transy));
	env->sprite.drawstart_y = -env->sprite.sprite_height / 2 + env->height / 2;
	calc_end_start(env);
}

int			sprite_put_pixel(t_env *env, int i, int y)
{
	env->color = env->sprite_tab[i].tex->tex_data[env->sprite_tab[i].\
	tex->width * env->sprite.sp_y + env->sprite.sp_x];
	if (env->color != 0x0000ff && env->color != 0x0003ff)
	{
		if (!env->img)
			if ((env->img = ft_new_image(env, env->width, env->height)) == NULL)
			{
				env->error = IMG_ERROR;
				ft_exit(env);
				return (IMG_ERROR);
			}
		env->img->width = env->width;
		env->img->height = env->height;
		if (ft_put_pixel(env->img, env->color, env->sprite.stripe, y) != \
				SUCCESS)
			return (PIXEL_ERROR);
	}
	return (SUCCESS);
}

void		check_if_sprite_shot(t_env *env, int i)
{
	if ((env->sprite.stripe >= env->shot_box_x && env->\
	sprite.stripe <= env->shot_box_x + env->shot_box_size)\
	&& (env->sprite.sp_y >= env->shot_box_y && env->sprite.sp_y\
	<= env->shot_box_y + env->shot_box_size))
	{
		env->ennemy_can_be_shot = 1;
		env->ennemy_be_shot_x = (int)env->sprite_tab[i].tex->sprite_x;
		env->ennemy_be_shot_y = (int)env->sprite_tab[i].tex->sprite_y;
	}
	else
		env->ennemy_can_be_shot = 0;
}

int			add_sprite_two(t_env *env, int i)
{
	int		d;
	int		y;
	int		height;
	int		width;

	width = 2;
	height = 1;
	y = env->sprite.drawstart_y;
	if (env->sprite.transy > 0 && env->sprite.stripe > 0
	&& env->sprite.stripe < env->width && env->sprite.transy
	< env->ray.zbuffer[env->sprite.stripe])
	{
		while (y < env->sprite.drawend_y)
		{
			d = y * width - env->height * height + env->sprite.sprite_height\
				* height;
			env->sprite.sp_y = ((d * env->sprite_tab[i].tex->height) /\
			env->sprite.sprite_height) / width;
			if (sprite_put_pixel(env, i, y) != SUCCESS)
				return (sprite_put_pixel(env, i, y));
			check_if_sprite_shot(env, i);
			y++;
		}
	}
	return (SUCCESS);
}
