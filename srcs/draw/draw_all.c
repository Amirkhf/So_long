/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:45:27 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 18:58:42 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_ennemy(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == 'X')
				print_img(all, all->images.ennemy, j, i);
			j++;
		}
		i++;
	}
}

void	draw_ground(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == '0')
				print_img(all, all->images.ground, j, i);
			j++;
		}
		i++;
	}
}

void	draw_player(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == 'P')
				print_img(all, all->images.player, j, i);
			j++;
		}
		i++;
	}
}

void	draw_exit(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == 'E')
				print_img(all, all->images.exit, j, i);
			j++;
		}
		i++;
	}
}

void	draw_collectible(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == 'C')
				print_img(all, all->images.collect, j, i);
			j++;
		}
		i++;
	}
}
