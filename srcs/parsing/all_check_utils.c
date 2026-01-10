/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:27:49 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 20:28:14 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_position	player_position(char **map)
{
	int			i;
	int			j;
	t_position	position;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				position.x = i;
				position.y = j;
			}
			j++;
		}
		i++;
	}
	return (position);
}

int	check_wall_top(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_wall(char **map)
{
	int	i;
	int	len_line;

	len_line = ft_strlen(map[0]);
	i = 0;
	if (check_wall_top(map[0]))
		return (1);
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][len_line - 1] != '1'))
			return (1);
		i++;
	}
	i--;
	if (check_wall_top(map[i]))
		return (1);
	return (0);
}

int	check_rectangular(char **map, int len)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}
