/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:30:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 13:00:08 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	verif_direction(t_all *all, int x, int y)
{
	if (all->window.map[x][y] == '1' || (all->window.map[x][y] == 'E'
			&& all->messure.nb_collect != 0))
	{
		return (1);
	}
	else if (all->window.map[x][y] == 'E' && all->messure.nb_collect == 0)
	{
		exit(0);
	}
	return (0);
}

int	verif_move_player(t_all *all, int move)
{
	int	x;
	int	y;

	x = all->player_position.x;
	y = all->player_position.y;
	if (move == 1)
	{
		printf("verif_direction_top\n");
		if (verif_direction(all, x - 1, y))
			return (1);
	}
	else if (move == 2)
	{
		printf("verif_direction_down\n");
		if (verif_direction(all, x + 1, y))
			return (1);
	}
	else if (move == 3)
	{
		printf("verif_direction_left\n");
		if (verif_direction(all, x, y - 1))
			return (1);
	}
	else if (move == 4)
	{
		printf("verif_direction_right\n");
		if (verif_direction(all, x, y + 1))
			return (1);
	}
	return (0);
}

int	its_collect(t_all *all, int move)
{
	int	x;
	int	y;

	x = all->player_position.x;
	y = all->player_position.y;
	if (move == 1)
	{
		if (all->window.map[x - 1][y] == 'C')
			return (1);
	}
	else if (move == 2)
	{
		if (all->window.map[x + 1][y] == 'C')
			return (1);
	}
	else if (move == 3)
	{
		if (all->window.map[x][y - 1] == 'C')
			return (1);
	}
	else if (move == 4)
	{
		if (all->window.map[x][y + 1] == 'C')
			return (1);
	}
	return (0);
}

void	ft_finish(t_all *all)
{
	free_function(all->window.map);
	exit(0);
}
