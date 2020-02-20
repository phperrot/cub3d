/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:00:20 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 15:04:42 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_key_hit(int key, t_env *env)
{
	if (key == KEY_UP)
		env->move.up = 1;
	if (key == KEY_DOWN)
		env->move.down = 1;
	if (key == ROTATE_LEFT)
		env->move.left = 1;
	if (key == KEY_LEFT)
		env->move.strafl = 1;
	if (key == ROTATE_RIGHT)
		env->move.right = 1;
	if (key == KEY_RIGHT)
		env->move.strafr = 1;
	if (key == KEY_EXIT)
		ft_exit(env);
	return (SUCCESS);
}

int		ft_key_release(int key, t_env *env)
{
	if (key == KEY_UP)
		env->move.up = 0;
	if (key == KEY_DOWN)
		env->move.down = 0;
	if (key == ROTATE_LEFT)
		env->move.left = 0;
	if (key == KEY_LEFT)
		env->move.strafl = 0;
	if (key == ROTATE_RIGHT)
		env->move.right = 0;
	if (key == KEY_RIGHT)
		env->move.strafr = 0;
	return (SUCCESS);
}

int		ft_run(t_env *env)
{
	ft_free_img(env, env->img);
	if ((env->img = ft_new_image(env, env->width, env->height)) == NULL)
	{
		env->error = IMG_ERROR;
		ft_error(env->error, env);
		return (IMG_ERROR);
	}
	ft_move(env);
	ft_disp_screen(env, 0);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->img_ptr, 0,
		0);
	return (SUCCESS);
}

int		events(t_env env)
{
	while (env.save_flag && env.width % 4)
		env.width++;
	if (env.save_flag)
	{
		if (!(env.win_ptr = mlx_new_window(env.mlx_ptr, 1, 1, "Cub3D")))
			return (MLX_ERROR);
	}
	else
	{
		if (!(env.win_ptr = mlx_new_window(env.mlx_ptr, env.width, \
		env.height, "Cub3D")))
			return (MLX_ERROR);
	}
	mlx_hook(env.win_ptr, 17, STRUCTURENOTIFYMASK, ft_exit, &env);
	mlx_hook(env.win_ptr, KEYPRESS, KEYPRESSMASK, ft_key_hit, &env);
	mlx_hook(env.win_ptr, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &env);
	mlx_loop_hook(env.mlx_ptr, ft_run, &env);
	mlx_loop(env.mlx_ptr);
	return (SUCCESS);
}
