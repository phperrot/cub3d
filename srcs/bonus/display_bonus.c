/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:34:45 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/20 08:46:48 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			ft_put_pixel(t_img *img, unsigned int color, int p_x, int p_y)
{
	if (p_y >= img->height || p_x >= img->width || p_x < 0\
	|| p_y < 0 || ((p_y * img->width + p_x) >= (img->width * img->height - 1)))
		return (PIXEL_ERROR);
	img->img_data[p_y * img->width + p_x] = color;
	return (SUCCESS);
}

char		*ft_disp_col(t_env *env, int x, char tex, int y)
{
	char	*tex_path;
	int		height;

	if (tex == 'E')
		height = env->tex_e->height;
	if (tex == 'N')
		height = env->tex_n->height;
	if (tex == 'W')
		height = env->tex_w->height;
	if (tex == 'S')
		height = env->tex_s->height;
	while (y < env->ray.wstart)
		ft_put_pixel(env->img, env->ceil, x, y++);
	while (y >= env->ray.wstart && y <= env->ray.wend)
	{
		env->ray.tex_y = (int)env->ray.tex_pos & (height - 1);
		env->ray.tex_pos += env->ray.step_tex;
		tex_path = pix_color(env, 0);
		ft_put_pixel(env->img, env->color, x, y);
		y++;
	}
	while (y < env->height)
		ft_put_pixel(env->img, env->floor, x, y++);
	return (tex_path);
}

int			ft_disp_screen(t_env *env, int x)
{
	char tex;

	while (x < env->width)
	{
		ft_init_ray(env, x);
		ft_direction_ray(env);
		tex = ft_hit_ray(env, 0);
		ft_size_ray(env);
		ft_wall_tex(env, tex);
		ft_disp_col(env, x++, tex, 0);
		env->ray.zbuffer[x] = env->ray.dist;
	}
	init_sprite(env);
	init_minimap(*env);
	ft_disp_items(env);
	env->weapon_shot = 0;
	if (env->save_flag == 1)
	{
		if (launch_save(env) != SUCCESS)
			ft_putstr("Error\nError while writing save file");
		ft_exit(env);
	}
	return (SUCCESS);
}
