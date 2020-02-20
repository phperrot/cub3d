/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:13:02 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 15:17:07 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_reload_ammo(t_env *env)
{
	env->weapon_list.weapon1.ammo += 10;
	env->weapon_list.weapon2.ammo += 10;
	env->weapon_list.weapon3.ammo += 10;
	env->weapon_list.weapon4.ammo += 10;
	env->sprite_count--;
}

void	ft_game_over(t_env *env)
{
	ft_putstr("\n###############GAME OVER##############\n");
	ft_exit(env);
}

void	ft_ennemy(t_env *env)
{
	env->lives -= 0.1;
	if (env->lives <= 0)
		ft_game_over(env);
}

void	ft_new_level(t_env *env, int i, int x, int y)
{
	while (i <= (env->level * 2))
	{
		y = rand() % env->map_height;
		x = rand() % ft_strlen(env->map[y]);
		if (env->map[y][x] == '0')
		{
			env->map[y][x] = 'O';
			i++;
		}
	}
	env->ennemy_count += env->level * 2 + 1;
	env->sprite_count += env->level * 2 + 2;
	i = 0;
	while (i < 1)
	{
		y = rand() % env->map_height;
		x = rand() % env->map_width;
		if (env->map[y][x] == '0')
			env->map[y][x] = 'T';
		if (env->map[y][x] == 'T')
			i++;
	}
	env->treasure_caught = 0;
	env->target_divider += 0.5;
	init_sprite(env);
}

void	ft_next_level(t_env *env)
{
	if (env->treasure_caught)
	{
		ft_putstr("######LEVEL ");
		ft_putnbr(env->level);
		ft_putstr(" COMPLETED######\n");
		env->level++;
		ft_putstr("\n##################################\nEntering new level\n");
		ft_putstr("\nlevel #");
		ft_putnbr(env->level);
		ft_putstr("\n\n##################################\n");
		ft_new_level(env, 0, 0, 0);
	}
}
