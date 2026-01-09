/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:48:50 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 14:20:07 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	timer(t_all *all)
{
	static long long	timer = 0;

	printf("un\n");
	if (timer == 1500000)
	{
		position_ennemy(all);
		timer = 0;
	}
	timer++;
	return (0);
}

void	move_ennemy_random_direction(t_all *all, int i, int j)
{
	int	direction;

	printf("move_ennemy_random_direction\n");
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

	printf("clen_map\n");
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

void	kill_ennemy(t_all *all, int i, int j)
{
	if (all->window.map[i - 1][j] == 'P' || all->window.map[i + 1][j] == 'P'
		|| all->window.map[i][j + 1] == 'P' || all->window.map[i][j - 1] == 'P')
	{
		ft_finish(all);
	}
}

int	verif_direction_wall(t_all *all, int i, int j, int direction)
{
	if (direction == 0)
	{
		if (all->window.map[i - 1][j] == '1')
			return (1);
	}
	else if (direction == 1)
	{
		if (all->window.map[i + 1][j] == '1')
			return (1);
	}
	else if (direction == 3)
	{
		if (all->window.map[i][j + 1] == '1')
			return (1);
	}
	else if (direction == 2)
	{
		if (all->window.map[i][j - 1] == '1')
			return (1);
	}
	return (0);
}