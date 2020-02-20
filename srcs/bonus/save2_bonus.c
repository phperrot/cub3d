/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:56:57 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/20 08:47:19 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int				ft_save(t_env *env)
{
	t_save save;

	save.height = env->height - 1;
	save.width = env->width;
	save.pad = (4 - ((int)save.width * 3) % 4) % 4;
	save.file_header = create_file_header(env, save.pad);
	save.img_header = create_img_header(save.height, save.width);
	if ((save.fd = open(SCREEN_PATH, O_WRONLY | O_CREAT, RIGHTS)) < 0)
		return (OPEN_ERROR);
	if (write_headers(&save) != SUCCESS)
	{
		close(save.fd);
		return (COLOR_ERROR);
	}
	if (write_colors(env, save.fd, save.height, save.width) != SUCCESS)
	{
		close(save.fd);
		return (COLOR_ERROR);
	}
	close(save.fd);
	return (SUCCESS);
}

int				launch_save(t_env *env)
{
	ft_save(env);
	env->save_flag = 0;
	return (SUCCESS);
}
