/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 13:38:41 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 14:27:53 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	screen_game_win(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	print_img(all, all->images.ground, all->player_position.y,
		all->player_position.x);
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == 'E')
			{
				all->player_position.x = i;
				all->player_position.y = j;
			}
			j++;
		}
		i++;
	}
	screen_game_win_v2(all);
}

void	screen_game_win_v2(t_all *all)
{
	print_img(all, all->images.win, all->player_position.y,
		all->player_position.x);
	mlx_do_sync(all->window.mlx);

	usleep(2000000);
	ft_finish(all);
}