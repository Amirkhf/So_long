/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:45:18 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 18:24:05 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_map(char *str, char **map)
{
	int		fd;
	int		size;
	char	*buf;
	char	*str_map;

	size = 1;
	fd = open(str, O_RDONLY);
	str_map = NULL;
	buf = NULL;
	while (size > 0)
	{
		buf = malloc(100 * sizeof(char));
		size = read(fd, buf, 99);
		if (size == 0)
			break ;
		if (size == -1)
			exit(0);
		buf[size] = '\0';
		str_map = ft_strjoin(str_map, buf);
		free(buf);
	}
	map = ft_split(str_map, '\n');
	close(fd);
	return (free(buf), free(str_map), map);
}
