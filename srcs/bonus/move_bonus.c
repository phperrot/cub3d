/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c	                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:13:11 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 15:36:37 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_rotate(t_env *env, int advance)
{
	double	dir;
	double	plane;

	dir = env->ray.dirx;
	plane = env->ray.planex;
	env->ray.dirx = env->ray.dirx * cos(advance * 0.1)
		- env->ray.diry * sin(advance * 0.1);
	env->ray.diry = dir * sin(advance * 0.1)
		+ env->ray.diry * cos(advance * 0.1);
	env->ray.planex = env->ray.planex * cos(advance * 0.1)
		- env->ray.planey * sin(advance * 0.1);
	env->ray.planey = plane * sin(advance * 0.1)
		+ env->ray.planey * cos(advance * 0.1);
}

void	move_up(t_env *env)
{
	if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y)]\
	[(int)(env->player_x + env->ray.dirx * env->ray.speed)]))
		env->player_x += env->ray.dirx * env->ray.speed;
	else if (env->sound)
		system("afplay ./sound/collision.mp3");
	if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y + \
		env->ray.diry * env->ray.speed)][(int)(env->player_x)]))
		env->player_y += env->ray.diry * env->ray.speed;
	else if (env->sound)
		system("afplay ./sound/collision.mp3");
}

void	up_down(t_env *env)
{
	if (env->move.up == 1)
	{
		move_up(env);
	}
	if (env->move.down == 1)
	{
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y)][(int)\
			(env->player_x - env->ray.dirx * env->ray.speed)]))
			env->player_x -= env->ray.dirx * env->ray.speed;
		else if (env->sound)
			system("afplay ./sound/collision.mp3");
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y - \
			env->ray.diry * env->ray.speed)][(int)(env->player_x)]))
			env->player_y -= env->ray.diry * env->ray.speed;
		else if (env->sound)
			system("afplay ./sound/collision.mp3");
	}
}

void	straf(t_env *env)
{
	if (env->move.strafl == 1)
	{
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y - env->\
		ray.dirx * env->ray.speed)][(int)(env->player_x)]))
			env->player_y += -env->ray.dirx * env->ray.speed;
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y)][(int)\
		(env->player_x
			+ env->ray.diry * env->ray.speed)]))
			env->player_x += env->ray.diry * env->ray.speed;
	}
	if (env->move.strafr == 1)
	{
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y + env->\
		ray.dirx * env->ray.speed)][(int)(env->player_x)]))
			env->player_y -= -env->ray.dirx * env->ray.speed;
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y)][(int)\
		(env->player_x - env->ray.diry * env->ray.speed)]))
			env->player_x -= env->ray.diry * env->ray.speed;
	}
}

void	ft_move(t_env *env)
{
	int pos;

	if (env->move.up == 1 || env->move.down == 1)
		up_down(env);
	if (env->move.strafr == 1 || env->move.strafl == 1)
		straf(env);
	if (env->move.left == 1)
		ft_rotate(env, -1);
	if (env->move.right == 1)
		ft_rotate(env, 1);
	pos = env->map[(int)(env->player_y)][(int)(env->player_x)];
	if (pos == 'B')
		ft_bonus(env);
	if (pos == 'A')
		ft_reload_ammo(env);
	if (pos == 'O')
		ft_ennemy(env);
	if (pos == 'T')
		env->treasure_caught = 1;
	if (pos == 'T')
		env->sprite_count--;
	if (ft_strchr("BAT", pos))
		env->map[(int)(env->player_y)][(int)(env->player_x)] = '0';
	if (pos == 'T')
		ft_next_level(env);
}
