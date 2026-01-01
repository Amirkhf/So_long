/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:15:30 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/01 18:21:16 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	dfs(char **map, int x, int y)
{
	if (map[x][y] == 'A' || map[x][y] == '1')
		return ;
	if (x < 0 || x > nb_ligne(map) || y < 0 || y > ft_strlen(map[0]))
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	nb_ligne(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}