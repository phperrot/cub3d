/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:24:26 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 17:00:03 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		init_weapon_img(t_env *env)
{
	env->error = 0;
	if ((env->weapon_list.weapon1.img = ft_new_img(env,\
	env->weapon_list.weapon1.path)) == NULL && !env->error)
		env->error = IMG_ERROR_WEAPON_1;
	if ((env->weapon_list.weapon2.img = ft_new_img(env,\
	env->weapon_list.weapon2.path)) == NULL && !env->error)
		env->error = IMG_ERROR_WEAPON_2;
	if ((env->weapon_list.weapon3.img = ft_new_img(env,\
	env->weapon_list.weapon3.path)) == NULL && !env->error)
		env->error = IMG_ERROR_WEAPON_3;
	if ((env->weapon_list.weapon4.img = ft_new_img(env,\
	env->weapon_list.weapon4.path)) == NULL && !env->error)
		env->error = IMG_ERROR_WEAPON_4;
	if ((env->weapon_img = ft_new_img(env, env->current_weapon\
	->path)) == NULL)
		env->error = IMG_ERROR_WEAPON_5;
	if (env->error)
	{
		ft_error(env->error, env);
		return (IMG_ERROR);
	}
	return (SUCCESS);
}

void	init_weapon2(t_env *env)
{
	env->weapon_list.weapon4.name = "shotgun";
	env->weapon_list.weapon4.width = 407;
	env->weapon_list.weapon4.height = 193;
	env->weapon_list.weapon4.ammo = 10;
	env->weapon_list.weapon4.path = "./weapon/shotgun.xpm";
	env->weapon_list.weapon4.color = 0x0000ff;
}

int		init_weapon(t_env *env)
{
	env->weapon_id = 1;
	env->weapon_list.weapon1.name = "handgun";
	env->weapon_list.weapon1.width = 407;
	env->weapon_list.weapon1.height = 193;
	env->weapon_list.weapon1.ammo = 10;
	env->weapon_list.weapon1.path = "./weapon/gun.xpm";
	env->weapon_list.weapon1.color = 0x0000ff;
	env->weapon_list.weapon2.name = "firegun";
	env->weapon_list.weapon2.width = 407;
	env->weapon_list.weapon2.height = 193;
	env->weapon_list.weapon2.ammo = 10;
	env->weapon_list.weapon2.path = "./weapon/firegun.xpm";
	env->weapon_list.weapon2.color = 0x0000ff;
	env->weapon_list.weapon3.name = "sniper";
	env->weapon_list.weapon3.width = 407;
	env->weapon_list.weapon3.height = 193;
	env->weapon_list.weapon3.ammo = 10;
	env->weapon_list.weapon3.path = "./weapon/sniper.xpm";
	env->weapon_list.weapon3.color = 0x0000ff;
	init_weapon2(env);
	env->current_weapon = &env->weapon_list.weapon1;
	init_weapon_img(env);
	return (SUCCESS);
}
