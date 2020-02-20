/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:50:33 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 16:44:52 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_tex	*ft_new_tex(t_env *env, char *file, char *type)
{
	t_tex *tex;

	if (!(tex = malloc(sizeof(t_tex))))
		return (NULL);
	if (!(tex->tex_ptr = mlx_xpm_file_to_image(env->mlx_ptr, file,
		&tex->width, &tex->height)))
	{
		free(tex);
		return (NULL);
	}
	if (!(tex->tex_data = (int *)mlx_get_data_addr(tex->tex_ptr, &tex->bpp,
		&tex->size_line, &tex->endian)))
	{
		free(tex->tex_ptr);
		free(tex);
		return (NULL);
	}
	tex->type = type;
	return (tex);
}

void	init_tex_ennemy2(t_env *env)
{
	if ((env->tex_ennemy_5 = ft_new_tex(env, "./ennemy/ennemy-5.xpm", \
	"ennemy")) == NULL)
		env->error = TEX_ERROR_E5;
	if ((env->tex_ennemy_6 = ft_new_tex(env, "./ennemy/ennemy-6.xpm", \
	"ennemy")) == NULL)
		env->error = TEX_ERROR_E6;
	if ((env->tex_ennemy_7 = ft_new_tex(env, "./ennemy/ennemy-7.xpm", \
	"ennemy")) == NULL)
		env->error = TEX_ERROR_E7;
	if ((env->tex_ennemy_8 = ft_new_tex(env, "./ennemy/ennemy-8.xpm", \
	"ennemy")) == NULL)
		env->error = TEX_ERROR_E8;
	if ((env->tex_ennemy_9 = ft_new_tex(env, "./ennemy/ennemy-9.xpm", \
	"ennemy")) == NULL)
		env->error = TEX_ERROR_E9;
}

void	init_tex_ennemy1(t_env *env)
{
	if ((env->tex_ennemy_1 = ft_new_tex(env, "./ennemy/ennemy-1.xpm", \
	"ennemy")) == NULL)
		env->error = TEX_ERROR_E1;
	if ((env->tex_ennemy_2 = ft_new_tex(env, "./ennemy/ennemy-2.xpm", \
	"ennemy")) == NULL)
		env->error = TEX_ERROR_E2;
	if ((env->tex_ennemy_3 = ft_new_tex(env, "./ennemy/ennemy-3.xpm", \
	"ennemy")) == NULL)
		env->error = TEX_ERROR_E3;
	if ((env->tex_ennemy_4 = ft_new_tex(env, "./ennemy/ennemy-4.xpm", \
	"ennemy")) == NULL)
		env->error = TEX_ERROR_E4;
	init_tex_ennemy2(env);
}

void	init_tex_wall_sprite(t_env *env)
{
	if ((env->tex_n = ft_new_tex(env, env->arg.no, "NO")) == NULL)
		env->error = TEX_ERROR_N;
	if ((env->tex_s = ft_new_tex(env, env->arg.so, "SO")) == NULL)
		env->error = TEX_ERROR_S;
	if ((env->tex_w = ft_new_tex(env, env->arg.we, "WE")) == NULL)
		env->error = TEX_ERROR_W;
	if ((env->tex_e = ft_new_tex(env, env->arg.ea, "EA")) == NULL)
		env->error = TEX_ERROR_E;
	if ((env->tex_sprite = ft_new_tex(env, env->arg.sprite, "sprite")) == NULL)
		env->error = TEX_ERROR_SP;
	if ((env->tex_sprite1 = ft_new_tex(env, env->arg.sprite1, "sprite1"))\
			== NULL)
		env->error = TEX_ERROR_SP1;
	if ((env->tex_door = ft_new_tex(env, env->arg.door, "door")) == NULL)
		env->error = TEX_ERROR_D;
	if ((env->tex_bonus = ft_new_tex(env, env->arg.bonus, "bonus")) == NULL)
		env->error = TEX_ERROR_B;
	if ((env->tex_ammo = ft_new_tex(env, env->arg.ammo, "ammo")) == NULL)
		env->error = TEX_ERROR_A;
	if ((env->tex_treasure = ft_new_tex(env, env->arg.treasure, "treasure"))\
			== NULL)
		env->error = TEX_ERROR_T;
}

int		init_tex(t_env *env)
{
	env->error = 0;
	init_tex_wall_sprite(env);
	if (env->error)
	{
		env->error = TEX_ERROR;
		ft_error(env->error, env);
	}
	init_tex_ennemy1(env);
	if (env->error)
	{
		env->error = TEX_ERROR_ENNEMY;
		ft_error(env->error, env);
	}
	if (env->error)
		return (TEX_ERROR);
	return (SUCCESS);
}
