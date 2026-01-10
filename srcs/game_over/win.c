/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 13:38:41 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 13:43:39 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"



void	screen_game_win(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == 'E')
			{
				print_img(all, all->images.win, j, i);
				mlx_do_sync(all->window.mlx);
			}
			j++;
		}
		i++;
	}
	usleep(2000000);
	ft_finish(all);
}