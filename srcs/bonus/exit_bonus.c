/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:01:59 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 16:43:02 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_free_ennemy(t_env *env)
{
	ft_free_tex(env, env->tex_ennemy_1);
	ft_free_tex(env, env->tex_ennemy_2);
	ft_free_tex(env, env->tex_ennemy_3);
	ft_free_tex(env, env->tex_ennemy_4);
	ft_free_tex(env, env->tex_ennemy_5);
	ft_free_tex(env, env->tex_ennemy_6);
	ft_free_tex(env, env->tex_ennemy_7);
	ft_free_tex(env, env->tex_ennemy_8);
	ft_free_tex(env, env->tex_ennemy_9);
	ft_free_tex(env, env->tex_ennemy);
}

int		ft_exit(t_env *env)
{
	if (!env->error)
	{
		ft_free_img(env, env->img);
		ft_free_tex(env, env->tex_s);
		ft_free_tex(env, env->tex_n);
		ft_free_tex(env, env->tex_w);
		ft_free_tex(env, env->tex_e);
		ft_free_tex(env, env->tex_sprite);
		ft_free_tex(env, env->tex_sprite1);
		ft_free_tex(env, env->tex_door);
		ft_free_tex(env, env->tex_bonus);
		ft_free_ennemy(env);
		ft_free_tex(env, env->tex_ammo);
		ft_free_tex(env, env->tex_treasure);
		ft_free_img(env, env->sound_icon);
		ft_free_img(env, env->bullet);
		ft_free_img(env, env->lives_icon);
		ft_free_img(env, env->target);
		ft_free_img(env, env->weapon_img);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	}
	exit(0);
	return (SUCCESS);
}
