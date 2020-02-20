/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:27:28 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 16:42:49 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_img		*ft_new_image(t_env *env, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->img_ptr = mlx_new_image(env->mlx_ptr, width, height)))
		return (NULL);
	if (!(img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->endian)))
		return (NULL);
	img->width = width;
	img->height = height;
	return (img);
}

void		pixel_tex(t_tex *tex, t_env *env)
{
	if (tex->width * env->ray.tex_y + env->ray.tex_x < (tex->width *\
				tex->height))
		env->color = tex->tex_data[tex->width * env->ray.tex_y +\
					env->ray.tex_x];
}

char		*get_output_wall(t_env *env)
{
	if (env->ray.stepx < 0 && env->ray.rmapx < (int)env->ray.\
rposx && env->ray.wall == 0)
	{
		pixel_tex(env->tex_e, env);
		return (env->arg.ea);
	}
	if (env->ray.stepx > 0 && env->ray.rmapx > (int)env->ray.rposx\
	&& env->ray.wall == 0)
	{
		pixel_tex(env->tex_w, env);
		return (env->arg.we);
	}
	if (env->ray.stepy < 0 && env->ray.rmapy < (int)env->ray.rposy &&\
	env->ray.wall - 0)
	{
		pixel_tex(env->tex_n, env);
		return (env->arg.no);
	}
	if (env->ray.stepy > 0 && env->ray.rmapy > (int)\
	env->ray.rposy && env->ray.wall == 1)
		pixel_tex(env->tex_s, env);
	return (env->arg.so);
}

char		*pix_color(t_env *env, int sprite)
{
	char	*output;

	output = NULL;
	if (!sprite && !env->ray.door)
	{
		output = get_output_wall(env);
	}
	if (env->ray.door)
	{
		pixel_tex(env->tex_door, env);
		output = env->arg.door;
	}
	if (sprite && env->ray.sprite)
	{
		pixel_tex(env->tex_sprite, env);
		output = env->arg.sprite;
	}
	return (output);
}

void		open_door(t_env *env, char c, int x, int y)
{
	while (y < env->map_height)
	{
		x = 0;
		while (env->map[y][x])
		{
			if (env->map[y][x] == c && env->open_door && ft_abs((double)(y -\
			env->player_y)) <= 2 && (ft_abs((double)x - env->player_x) <= 2))
			{
				if (c == 'D')
					env->sprite_count--;
				env->map[y][x] = (c == 'D') ? 'F' : 'Q';
			}
			if (env->map[y][x] == c && !env->open_door && ft_abs((double)(y -\
			env->player_y)) <= 2 && (ft_abs((double)x - env->player_x) <= 2))
			{
				env->map[y][x] = (c == 'F') ? 'D' : 'P';
				if (c == 'F')
					env->sprite_count++;
			}
			x++;
		}
		y++;
	}
	ft_disp_screen(env, 0);
}
