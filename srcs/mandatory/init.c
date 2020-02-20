/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:06:16 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 15:12:34 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			init_items(t_env *env)
{
	env->error = 0;
	if ((env->sound_icon = ft_new_img(env, "./textures/sound.xpm")) == NULL)
		env->error = IMG_ERROR_ITEM;
	if ((env->bullet = ft_new_img(env, "./weapon/bullets.xpm")) == NULL)
		env->error = IMG_ERROR_ITEM;
	if ((env->lives_icon = ft_new_img(env, "./textures/life.xpm")) == NULL)
		env->error = IMG_ERROR_ITEM;
	if ((env->target = ft_new_img(env, "./textures/aim.xpm")) == NULL)
		env->error = IMG_ERROR_ITEM;
	if (env->error)
	{
		ft_error(env->error, env);
		return (IMG_ERROR_ITEM);
	}
	return (SUCCESS);
}

int			init_raybuffer(t_env *env)
{
	if (!(env->ray.zbuffer = malloc(sizeof(double) * (env->width + 1))))
		return (ZBUFFER_ERROR);
	return (SUCCESS);
}

void		init_env_orientation(t_env *env)
{
	if (env->orientation == 'N')
	{
		env->ray.diry = -0.99;
		env->ray.planex = -0.80;
	}
	if (env->orientation == 'S')
	{
		env->ray.diry = 0.99;
		env->ray.planex = 0.80;
	}
	if (env->orientation == 'E')
	{
		env->ray.dirx = 0.99;
		env->ray.planey = -0.80;
	}
	if (env->orientation == 'W')
	{
		env->ray.dirx = -0.99;
		env->ray.planey = 0.80;
	}
}

void		init_env_2(t_env *env, t_arg arg)
{
	env->width = arg.screen_w;
	env->height = arg.screen_h;
	env->floor = from_rgb_to_hex(arg.floor);
	env->ceil = from_rgb_to_hex(arg.ceil);
	env->arg = arg;
	init_env_orientation(env);
	env->mlx_ptr = mlx_init();
	env->player_x += 0.5;
	env->player_y += 0.5;
	env->lives = 3;
	env->minimap = 1;
	env->target_divider = 1;
}

t_env		init_env(t_arg arg)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	ft_bzero(&env.ray, sizeof(t_ray));
	get_arg_for_env(&env, arg, 0, 0);
	env.ray.speed = 0.1;
	if (!(env.map = from_lst_to_tab(arg.map)))
	{
		env.error = FROM_LST_ERROR;
		ft_error(env.error, &env);
	}
	init_env_2(&env, arg);
	init_env_orientation(&env);
	init_weapon(&env);
	init_tex(&env);
	init_items(&env);
	env.map_height = ft_lstsize_map(env.arg.map);
	if ((env.error = init_raybuffer(&env)) != SUCCESS)
	{
		ft_error(env.error, &env);
	}
	init_sprite(&env);
	return (env);
}
