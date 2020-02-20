/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:05:18 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 15:05:37 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tex(t_env *env, t_tex *tex)
{
	if (tex)
	{
		mlx_destroy_image(env->mlx_ptr, tex->tex_ptr);
		free(tex);
		tex = NULL;
	}
}

void	ft_free_img(t_env *env, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(env->mlx_ptr, img->img_ptr);
		free(img);
		img = NULL;
	}
}
