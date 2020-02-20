/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:16:23 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 17:00:41 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	weapon_bullet_decrease(t_env *env)
{
	if (env->weapon_id == 1)
	{
		env->weapon_list.weapon1.ammo--;
		env->current_weapon = &env->weapon_list.weapon1;
	}
	if (env->weapon_id == 2)
	{
		env->weapon_list.weapon2.ammo--;
		env->current_weapon = &env->weapon_list.weapon2;
	}
	if (env->weapon_id == 3)
	{
		env->weapon_list.weapon3.ammo--;
		env->current_weapon = &env->weapon_list.weapon3;
	}
	if (env->weapon_id == 4)
	{
		env->weapon_list.weapon4.ammo--;
		env->current_weapon = &env->weapon_list.weapon4;
	}
}

int		weapon_shot(t_env *env)
{
	weapon_bullet_decrease(env);
	if (env->current_weapon->ammo >= 0)
	{
		env->weapon_shot = 1;
		if (env->ennemy_can_be_shot)
		{
			env->sprite_count--;
			env->ennemy_count--;
			env->map[env->ennemy_be_shot_y][env->ennemy_be_shot_x] = '0';
			env->ennemy_can_be_shot = 0;
			env->sprite_count = sprite_count(env);
			ft_next_level(env);
			init_sprite(env);
		}
		if (env->sound)
			system("afplay  ./sound/gun_shot.mp3");
	}
	else
		env->weapon_shot = 0;
	return (SUCCESS);
}

void	display_weapon1(t_env env, int action, t_pos offset, int *n)
{
	int	*tab;
	int	width;

	tab = env.weapon_img->img_data;
	width = env.weapon_img->width;
	n[0] = 0;
	while (n[0] < env.weapon_img->height * width)
	{
		n[1] = 0;
		n[2] = 0;
		while (n[1] < width)
		{
			if (action == 0)
				if (tab[n[0]] != env.current_weapon->color && n[1] < width / 2)
					ft_put_pixel(env.img, tab[n[0]], offset.x +  \
					n[1] / 1, offset.y + n[0] / (width) / 1);
			if (action == 1)
				if (tab[n[0]] != env.current_weapon->color && n[1] > \
				width / 2 && n[1] < 2 * width / 2)
					ft_put_pixel(env.img, tab[n[0]], offset.x + \
					n[1] / 1, offset.y + n[0] / (width) / 1);
			n[0]++;
			n[1]++;
		}
	}
}

int		display_weapon(t_env env, int action, t_pos offset, int *num)
{
	int	*tab;
	int	height;
	int	width;

	change_weapon(&env);
	tab = env.weapon_img->img_data;
	width = env.weapon_img->width;
	height = env.weapon_img->height;
	offset.y = env.height - height;
	if (action == 0)
		offset.x = env.width / 2 - 1 * width / 4;
	if (action)
		offset.x = env.width / 2 - 3 * width / 4;
	offset.x = offset.x + 10;
	display_weapon1(env, action, offset, num);
	if (action == 1)
		weapon_shot(&env);
	env.weapon_shot = 0;
	return (SUCCESS);
}

int		change_weapon(t_env *env)
{
	if (env->weapon_id == 1)
		env->current_weapon = &env->weapon_list.weapon1;
	if (env->weapon_id == 2)
		env->current_weapon = &env->weapon_list.weapon2;
	if (env->weapon_id == 3)
		env->current_weapon = &env->weapon_list.weapon3;
	if (env->weapon_id == 4)
		env->current_weapon = &env->weapon_list.weapon4;
	env->weapon_img = env->current_weapon->img;
	return (SUCCESS);
}
