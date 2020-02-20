/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:53:11 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 16:43:48 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			ft_get_tex_height(t_env *env, char tex)
{
	int		height;

	height = 64;
	if (tex == 'E')
		height = env->tex_e->height;
	if (tex == 'N')
		height = env->tex_n->height;
	if (tex == 'W')
		height = env->tex_w->height;
	if (tex == 'S')
		height = env->tex_s->height;
	return (height);
}

int			ft_get_tex_width(t_env *env, char tex)
{
	int		width;

	width = 64;
	if (tex == 'E')
		width = env->tex_e->width;
	if (tex == 'N')
		width = env->tex_n->width;
	if (tex == 'W')
		width = env->tex_w->width;
	if (tex == 'S')
		width = env->tex_s->width;
	return (width);
}

void		ft_wall_tex(t_env *env, char tex)
{
	double	wallx;
	int		height;
	int		width;

	width = ft_get_tex_width(env, tex);
	height = ft_get_tex_height(env, tex);
	if (env->ray.door)
	{
		width = env->tex_door->width;
		height = env->tex_door->height;
	}
	if (env->ray.wall == 0)
		wallx = env->ray.rposy - env->ray.dist * env->ray.rdiry;
	else
		wallx = env->ray.rposx - env->ray.dist * env->ray.rdirx;
	wallx -= (int)wallx;
	env->ray.tex_x = (int)(wallx * width);
	if (env->ray.wall == 0)
		env->ray.tex_x = width + env->ray.tex_x;
	else if (env->ray.wall == 1)
		env->ray.tex_x = width + env->ray.tex_x - 1;
	env->ray.step_tex = 1 * width / env->ray.rh;
	env->ray.tex_pos = (env->ray.wstart - env->height / 2\
	+ env->ray.rh / 2) * env->ray.step_tex - 1;
}
