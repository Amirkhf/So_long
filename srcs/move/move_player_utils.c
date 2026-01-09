/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:35:02 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 18:24:46 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	move_player(int direction, t_all *all)
{
	if (direction == W || direction == TOP)
		move_player_top(all);
	else if (direction == S || direction == DOWN)
		move_player_down(all);
	else if (direction == A || direction == LEFT)
		move_player_left(all);
	else if (direction == D || direction == RIGHT)
		move_player_right(all);
	else if (direction == ESC)
		ft_finish(all);
	return (0);
}

int	verif_move_player(t_all *all, int move, int x, int y)
{
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

int	its_collect(t_all *all, int move, int x, int y)
{
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
