/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 13:03:49 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/01 18:25:54 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	parsing(char *str, char **map)
{
	t_position	position;

	if (check_name(str))
		return (1);
	map = read_map(str, map);
	if (check_map(map))
		return (free_function(map), 1);
	position = player_position(map);
	dfs(map, position.x, position.y);
	if (verif_path(map))
		return (free_function(map), 1);
	return (free_function(map), 0);
}

int	check_map(char **map)
{
	int	len_line;

	len_line = ft_strlen(map[0]);
	if (check_rectangular(map, len_line) || check_wall(map)
		|| check_character(map) || count_elements(map))
		return (printf("check map"), 1);
	return (0);
}

int	count_elements(char **map)
{
	t_count	count;

	struct_count(&count);
	while (map[count.i])
	{
		count.j = 0;
		while (map[count.i][count.j])
		{
			if (map[count.i][count.j] == 'E')
				count.e++;
			if (map[count.i][count.j] == 'P')
				count.p++;
			if (map[count.i][count.j] == 'C')
				count.c++;
			count.j++;
		}
		count.i++;
	}
	if (count.c == 0 || count.e != 1 || count.p != 1)
		return (printf("count_elements"), 1);
	return (0);
}

int	check_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != '0' && map[i][j] != '1')
			{
				return (printf("check_character"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i
		- 3] != '.')
	{
		return (1);
	}
	return (0);
}
