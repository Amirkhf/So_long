/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:55:32 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/07 18:07:30 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	check_ennemy(char **map, p_position *position)
{
	if (map[position->x - 1][position->y] == 'X' || map[position->x
		+ 1][position->y] == 'X' || map[position->x][position->y - 1] == 'X'
		|| map[position->x][position->y + 1] == 'X')
		return (1);
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
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'X')
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

	printf("check_name\n");
	i = ft_strlen(str);
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i
		- 3] != '.')
	{
		return (1);
	}
	return (0);
}

p_position	player_position(char **map)
{
	int			i;
	int			j;
	p_position	position;

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
			return (printf("check wall top"), 1);
		i++;
	}
	return (0);
}

int	check_wall(char **map)
{
	int i;
	int len_line;

	len_line = ft_strlen(map[0]);
	i = 0;
	if (check_wall_top(map[0]))
		return (1);
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][len_line - 1] != '1'))
			return (printf("check wall"), 1);
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