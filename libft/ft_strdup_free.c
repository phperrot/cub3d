/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:30:46 by phperrot          #+#    #+#             */
/*   Updated: 2019/12/21 14:19:11 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char *to_free, const char *s1)
{
	char	*output;
	int		i;
	int		size;

	if (!s1)
	{
		return (NULL);
	}
	size = ft_strlen(s1);
	if (!(output = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (output == NULL)
		return (NULL);
	i = 0;
	while ((char)s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	free(to_free);
	return (output);
}
