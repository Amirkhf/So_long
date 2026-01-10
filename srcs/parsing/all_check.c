/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:55:32 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 20:28:30 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_ennemy(char **map, t_position *position)
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
		return (1);
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
				return (1);
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
