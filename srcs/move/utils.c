/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:30:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/08 15:17:34 by amkhelif         ###   ########.fr       */
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
		if (verif_direction(all, x - 1, y))
			return (1);
	}
	else if (move == 2)
	{
		if (verif_direction(all, x + 1, y))
			return (1);
	}
	else if (move == 3)
	{
		if (verif_direction(all, x, y - 1))
			return (1);
	}
	else if (move == 4)
	{
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
void	finish_game(t_all *all, int x, int y)
{
	if (all->window.map[x][y] == 'E' && all->messure.nb_collect == 0)
		exit(0);
}