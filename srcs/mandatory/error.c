/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:53:06 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 16:44:22 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_img_item(int error, t_env *env)
{
	env->error = error;
	if (env->sound_icon)
		ft_free_img(env, env->sound_icon);
	if (env->bullet)
		ft_free_img(env, env->bullet);
	if (env->bullet)
		ft_free_img(env, env->lives_icon);
	if (env->bullet)
		ft_free_img(env, env->target);
}

void	ft_error_tex_ennemy(int error, t_env *env)
{
	env->error = error;
	if (env->tex_ennemy)
		ft_free_tex(env, env->tex_ennemy);
	if (env->tex_ennemy_1)
		ft_free_tex(env, env->tex_ennemy_1);
	if (env->tex_ennemy_2)
		ft_free_tex(env, env->tex_ennemy_2);
	if (env->tex_ennemy_3)
		ft_free_tex(env, env->tex_ennemy_3);
	if (env->tex_ennemy_4)
		ft_free_tex(env, env->tex_ennemy_4);
	if (env->tex_ennemy_5)
		ft_free_tex(env, env->tex_ennemy_5);
	if (env->tex_ennemy_6)
		ft_free_tex(env, env->tex_ennemy_6);
	if (env->tex_ennemy_7)
		ft_free_tex(env, env->tex_ennemy_7);
	if (env->tex_ennemy_8)
		ft_free_tex(env, env->tex_ennemy_8);
	if (env->tex_ennemy_9)
		ft_free_tex(env, env->tex_ennemy_9);
}

void	ft_error_tex(int error, t_env *env)
{
	env->error = error;
	if (env->tex_n)
		ft_free_tex(env, env->tex_n);
	if (env->tex_s)
		ft_free_tex(env, env->tex_s);
	if (env->tex_w)
		ft_free_tex(env, env->tex_w);
	if (env->tex_e)
		ft_free_tex(env, env->tex_e);
	if (env->tex_sprite)
		ft_free_tex(env, env->tex_sprite);
	if (env->tex_sprite1)
		ft_free_tex(env, env->tex_sprite1);
	if (env->tex_door)
		ft_free_tex(env, env->tex_door);
	if (env->tex_bonus)
		ft_free_tex(env, env->tex_bonus);
	if (env->tex_ammo)
		ft_free_tex(env, env->tex_ammo);
	if (env->tex_treasure)
		ft_free_tex(env, env->tex_treasure);
	ft_putstr("Error\nProblem with textures loading");
}

void	ft_error_img_weapon(int error, t_env *env)
{
	ft_putnbr(error);
	if (env->weapon_list.weapon1.img)
		free(env->weapon_list.weapon1.img);
	if (env->weapon_list.weapon2.img)
		free(env->weapon_list.weapon2.img);
	if (env->weapon_list.weapon3.img)
		free(env->weapon_list.weapon3.img);
	if (env->weapon_list.weapon4.img)
		free(env->weapon_list.weapon4.img);
	if (env->weapon_img)
		free(env->weapon_img);
	ft_putstr("Error\nProblem with weapon creation");
}

int		ft_error(int error, t_env *env)
{
	if (error == ZBUFFER_ERROR)
	{
		ft_putstr("Error\nProblem with memory allocation");
	}
	if (error == FROM_LST_ERROR)
	{
		ft_putstr("Error\nProblem with map creation");
	}
	if (error == IMG_ERROR_WEAPON_5 ||
		error == IMG_ERROR_WEAPON_4 ||
		error == IMG_ERROR_WEAPON_3 ||
		error == IMG_ERROR_WEAPON_2 ||
		error == IMG_ERROR_WEAPON_1)
	{
		ft_error_img_weapon(error, env);
		ft_putstr("Error\nProblem with weapon creation");
	}
	if (error == TEX_ERROR)
		ft_error_tex(error, env);
	if (error == TEX_ERROR_ENNEMY)
		ft_error_tex_ennemy(error, env);
	if (error == IMG_ERROR_ITEM)
		ft_error_img_item(error, env);
	ft_exit(env);
	return (SUCCESS);
}
