/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:00:46 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 13:58:23 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	position_ennemy(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	printf("position_ennemy\n");
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

void	move_ennemy_top(t_all *all, int i, int j)
{
	printf("move_ennemy_top\n");
	if (verif_direction_wall(all, i, j, 0))
		return ;
	print_img(all, all->images.ground, j, i);
	print_img(all, all->images.ennemy, j, i - 1);
	all->window.map[i][j] = '0';
	all->window.map[i - 1][j] = 'Z';
}

void	move_ennemy_down(t_all *all, int i, int j)
{
	printf("move_ennemy_down\n");
	if (verif_direction_wall(all, i, j, 1))
		return ;
	print_img(all, all->images.ground, j, i);
	print_img(all, all->images.ennemy, j, i + 1);
	all->window.map[i][j] = '0';
	all->window.map[i + 1][j] = 'Z';
}

void	move_ennemy_left(t_all *all, int i, int j)
{
	printf("move_ennemy_left\n");
	if (verif_direction_wall(all, i, j, 2))
		return ;
	print_img(all, all->images.ground, j, i);
	print_img(all, all->images.ennemy, j - 1, i);
	all->window.map[i][j] = '0';
	all->window.map[i][j - 1] = 'Z';
}
void	move_ennemy_right(t_all *all, int i, int j)
{
	printf("move_ennemy_right\n");

	if (verif_direction_wall(all, i, j, 3))
		return ;
	print_img(all, all->images.ground, j, i);
	print_img(all, all->images.ennemy, j + 1, i);
	all->window.map[i][j] = '0';
	all->window.map[i][j + 1] = 'Z';
}