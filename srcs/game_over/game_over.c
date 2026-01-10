/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:41:54 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 13:18:05 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	screen_game_over(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->player_position.x == i && all->player_position.y == j)
			{
				print_img(all, all->images.game_over, j, i);
				mlx_do_sync(all->window.mlx);
			}
			j++;
		}
		i++;
	}
	usleep(2000000);
	ft_finish(all);
}