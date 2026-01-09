/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:46 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 18:30:55 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	dfs(char **map, int x, int y)
{
	if (map[x][y] == 'A' || map[x][y] == '1')
		return ;
	if (x < 0 || x > ft_nb_line(map) || y < 0 || y > ft_strlen(map[0]))
		return ;
	else
		map[x][y] = 'A';
	dfs(map, x, y - 1);
	dfs(map, x, y + 1);
	dfs(map, x - 1, y);
	dfs(map, x + 1, y);
}

int	verif_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (printf("verif_path"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_nb_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
