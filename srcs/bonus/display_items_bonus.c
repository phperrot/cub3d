/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 10:47:20 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 14:52:06 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		display_bullet(t_env *env, t_pos offset, double div, int *n)
{
	int		*tab;
	int		dim[2];

	dim[0] = env->bullet->width;
	dim[1] = env->bullet->height;
	n[1] = 0;
	n[0] = 0;
	tab = env->bullet->img_data;
	while (n[1] < dim[0] * dim[1] - (3 - env->current_weapon->ammo \
	/ 40) * dim[1] / 4 * dim[0])
	{
		n[2] = 0;
		while (n[2] < dim[0])
		{
			if (tab[n[1]] != env->current_weapon->color && n[2] < ((dim[0] \
			/ 3.9)) - (20 * (10 - env->current_weapon->ammo)))
				if ((n[0] > 70 && n[2] < (dim[0] / 3.9) - (20 * (10 - \
				env->current_weapon->ammo + (40 * (n[0] / 70))))) || n[0] < 70)
					ft_put_pixel(env->img, tab[n[1]], offset.x + n[2] / div, \
					offset.y + n[1] / (dim[0]) / div);
			n[1]++;
			n[2]++;
		}
		n[0]++;
	}
}

int			display_sound(t_env *env, t_pos offset, int *num)
{
	int		*tab;
	int		dim[2];
	double	divider;

	dim[0] = env->sound_icon->width;
	dim[1] = env->sound_icon->height;
	tab = env->sound_icon->img_data;
	num[0] = 0;
	divider = 1;
	offset.y = 0;
	offset.x = (env->sound) ? env->width - dim[0] : env->width - dim[0] / 2;
	while (num[0] < dim[0] * dim[1])
	{
		num[1] = 0;
		while (num[1]++ < dim[0])
		{
			if (tab[num[0]] != 0x0000ff)
				if ((env->sound && num[1] > dim[0] / 2) || (!env->sound &&\
				num[1] < dim[0] / 2))
					ft_put_pixel(env->img, tab[num[0]], offset.x + num[1] /\
					divider, offset.y + num[0] / (dim[0]) / divider);
			num[0]++;
		}
	}
	return (SUCCESS);
}

int			display_life(t_env *env, t_pos offset, int *num)
{
	int		*tab;
	int		dim[2];
	int		divider;

	dim[0] = env->lives_icon->width;
	dim[1] = env->lives_icon->height;
	tab = env->lives_icon->img_data;
	num[0] = 0;
	divider = 4;
	offset.y = env->height - dim[1] / (divider);
	offset.x = 0;
	while (num[0] < dim[1] * dim[0])
	{
		num[1] = 0;
		while (num[1] < dim[0])
		{
			if (tab[num[0]] != 0x0000ff && num[1] < (dim[0] / 3 * env->lives))
				ft_put_pixel(env->img, tab[num[0]], offset.x + num[1] / divider\
				, offset.y + num[0] / (dim[0]) / divider);
			num[0]++;
			num[1]++;
		}
	}
	return (SUCCESS);
}

int			display_target(t_env *env, t_pos offset, int *num)
{
	int		*tab;
	int		dim[2];

	dim[0] = env->target->width;
	dim[1] = env->target->height;
	tab = env->target->img_data;
	offset.y = env->height / 2 - dim[0] / (2 * env->target_divider);
	offset.x = env->width / 2 - dim[1] / (2 * env->target_divider);
	env->shot_box_x = offset.x + dim[0] / (2 * env->target_divider);
	env->shot_box_y = offset.y + dim[1] / (2 * env->target_divider);
	env->shot_box_size = dim[0];
	num[0] = 0;
	while (num[0] < dim[0] * dim[1])
	{
		num[1] = 0;
		while (num[1]++ < dim[0])
		{
			if (tab[num[0]] != 0x0000ff)
				ft_put_pixel(env->img, tab[num[0]], offset.x + num[1] /
				env->target_divider, offset.y + num[0] / (dim[0]) /
				env->target_divider);
			num[0]++;
		}
	}
	return (SUCCESS);
}

int			ft_disp_items(t_env *env)
{
	t_pos	offset;
	int		numb_tab[3];

	ft_bzero(&offset, sizeof(offset));
	change_weapon(env);
	display_bullet(env, offset, 2, numb_tab);
	display_target(env, offset, numb_tab);
	display_life(env, offset, numb_tab);
	display_weapon(*env, env->weapon_shot, offset, numb_tab);
	display_sound(env, offset, numb_tab);
	return (SUCCESS);
}
