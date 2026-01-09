/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:48:50 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 19:02:12 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_ennemy_top(t_all *all, int i, int j)
{
	if (verif_direction_wall(all, i, j, 0))
		return ;
	print_img(all, all->images.ground, j, i);
	print_img(all, all->images.ennemy, j, i - 1);
	all->window.map[i][j] = '0';
	all->window.map[i - 1][j] = 'Z';
}

void	move_ennemy_down(t_all *all, int i, int j)
{
	if (verif_direction_wall(all, i, j, 1))
		return ;
	print_img(all, all->images.ground, j, i);
	print_img(all, all->images.ennemy, j, i + 1);
	all->window.map[i][j] = '0';
	all->window.map[i + 1][j] = 'Z';
}

void	move_ennemy_left(t_all *all, int i, int j)
{
	if (verif_direction_wall(all, i, j, 2))
		return ;
	print_img(all, all->images.ground, j, i);
	print_img(all, all->images.ennemy, j - 1, i);
	all->window.map[i][j] = '0';
	all->window.map[i][j - 1] = 'Z';
}

void	move_ennemy_right(t_all *all, int i, int j)
{
	if (verif_direction_wall(all, i, j, 3))
		return ;
	print_img(all, all->images.ground, j, i);
	print_img(all, all->images.ennemy, j + 1, i);
	all->window.map[i][j] = '0';
	all->window.map[i][j + 1] = 'Z';
}

int	verif_direction_wall_v2(t_all *all, int i, int j)
{
	if (all->window.map[i][j] == '1' || all->window.map[i][j] == 'C'
		|| all->window.map[i][j] == 'X' || all->window.map[i][j] == 'E')
	{
		return (1);
	}
	return (0);
}
