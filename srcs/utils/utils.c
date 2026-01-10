/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:09:22 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 12:47:45 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	boucle_play(t_all *all)
{
	timer(all);
	verif_player_safe(all);
	return (0);
}

int	verif_player_safe(t_all *all)
{
	if (all->window.map[all->player_position.x][all->player_position.y
		+ 1] == 'X'
		|| all->window.map[all->player_position.x][all->player_position.y
		- 1] == 'X' || all->window.map[all->player_position.x
		+ 1][all->player_position.y] == 'X'
		|| all->window.map[all->player_position.x
		- 1][all->player_position.y] == 'X')
	{
		screen_game_over(all);
	}
	return (0);
}

void	finish_game(t_all *all, int x, int y)
{
	if (all->window.map[x][y] == 'E' && all->messure.nb_collect == 0)
		ft_finish(all);
}
