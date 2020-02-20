/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c	                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:15:57 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 15:26:18 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main_arg_check(int ac, char **av)
{
	int		error;

	error = 0;
	if (ac > 3)
		error = NB_ARG_ERROR_TOO_MANY;
	if (ac < 2)
		error = NB_ARG_ERROR_TOO_FEW;
	if (ac == 2)
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
			error = FILE_EXT_ERROR;
	if (ac == 3)
		if (ft_strncmp(av[2], "--save", 6) != 0)
			error = SAVE_FLAG_ERROR;
	if (error)
	{
		ft_error_arg(error);
		return (ARGUMENT_ERROR);
	}
	return (SUCCESS);
}

int			launch_env(t_arg arg, int ac)
{
	t_env	env;

	if (check_map(arg.map, 0, 0) != SUCCESS)
		return (MAP_ERROR);
	env = init_env(arg);
	if (ac == 3)
		env.save_flag = 1;
	events(env);
	return (SUCCESS);
}

int			main(int ac, char **av)
{
	int		fd1;
	int		ret;
	char	*buff;
	t_arg	arg;

	ft_bzero(&arg, sizeof(arg));
	ret = 0;
	buff = NULL;
	if (main_arg_check(ac, av) != SUCCESS)
		return (0);
	fd1 = open(av[1], O_RDWR);
	while ((ret = get_next_line(fd1, &buff)) > 0)
	{
		if (fetch_arguments(&arg, buff) != SUCCESS)
			return (ARGUMENT_ERROR);
		free(buff);
	}
	if (buff)
		free(buff);
	if (ret == -1)
		return (ft_error_arg(FILE_READ_ERROR));
	if (launch_env(arg, ac) != SUCCESS)
		return (MAP_ERROR);
	return (0);
}
