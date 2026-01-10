/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:00:46 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 19:57:46 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	timer(t_all *all)
{
	static long long	timer = 0;

	if (timer >= 100000)
	{
		position_ennemy(all);
		timer = 0;
	}
	timer++;
	return (0);
}

void	position_ennemy(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == 'X')
			{
				move_ennemy_random_direction(all, i, j);
			}
			j++;
		}
		i++;
	}
	clean_map(all);
}

void	move_ennemy_random_direction(t_all *all, int i, int j)
{
	int	direction;

	direction = rand() % 4;
	if (direction == 0)
		move_ennemy_top(all, i, j);
	else if (direction == 1)
		move_ennemy_down(all, i, j);
	else if (direction == 2)
		move_ennemy_left(all, i, j);
	else if (direction == 3)
		move_ennemy_right(all, i, j);
}

void	clean_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == 'Z')
				all->window.map[i][j] = 'X';
			j++;
		}
		i++;
	}
}

int	verif_direction_wall(t_all *all, int i, int j, int direction)
{
	if (direction == 0)
	{
		if (verif_direction_wall_v2(all, i - 1, j))
			return (1);
	}
	else if (direction == 1)
	{
		if (verif_direction_wall_v2(all, i + 1, j))
			return (1);
	}
	else if (direction == 3)
	{
		if (verif_direction_wall_v2(all, i, j + 1))
			return (1);
	}
	else if (direction == 2)
	{
		if (verif_direction_wall_v2(all, i, j - 1))
			return (1);
	}
	return (0);
}
