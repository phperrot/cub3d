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

#include "cub3d.h"

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
	return (SUCCESS);
}
