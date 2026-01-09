/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:30:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 19:00:57 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	verif_direction(t_all *all, int x, int y)
{
	if (all->window.map[x][y] == '1' || (all->window.map[x][y] == 'E'
			&& all->messure.nb_collect != 0))
		return (1);
	else if (all->window.map[x][y] == 'E' && all->messure.nb_collect == 0)
		ft_finish(all);
	return (0);
}

void	ft_finish(t_all *all)
{
	free_function(all->window.map);
	if (all->images.collect)
		mlx_destroy_image(all->window.mlx, all->images.collect);
	if (all->images.collect_v1)
		mlx_destroy_image(all->window.mlx, all->images.collect_v1);
	if (all->images.collect_v2)
		mlx_destroy_image(all->window.mlx, all->images.collect_v2);
	if (all->images.collect_v3)
		mlx_destroy_image(all->window.mlx, all->images.collect_v3);
	if (all->images.collect_v4)
		mlx_destroy_image(all->window.mlx, all->images.collect_v4);
	if (all->images.collect_v5)
		mlx_destroy_image(all->window.mlx, all->images.collect_v5);
	ft_finish_v2(all);
	exit(0);
}

void	ft_finish_v2(t_all *all)
{
	if (all->images.ennemy)
		mlx_destroy_image(all->window.mlx, all->images.ennemy);
	if (all->images.exit)
		mlx_destroy_image(all->window.mlx, all->images.exit);
	if (all->images.ground)
		mlx_destroy_image(all->window.mlx, all->images.ground);
	if (all->images.player)
		mlx_destroy_image(all->window.mlx, all->images.player);
	if (all->images.wall_down_left)
		mlx_destroy_image(all->window.mlx, all->images.wall_down_left);
	if (all->images.wall_down_right)
		mlx_destroy_image(all->window.mlx, all->images.wall_down_right);
	if (all->images.wall_down)
		mlx_destroy_image(all->window.mlx, all->images.wall_down);
	if (all->images.wall_down_v1)
		mlx_destroy_image(all->window.mlx, all->images.wall_down_v1);
	if (all->images.wall_down_v2)
		mlx_destroy_image(all->window.mlx, all->images.wall_down_v2);
	if (all->images.wall_left)
		mlx_destroy_image(all->window.mlx, all->images.wall_left);
	ft_finish_v3(all);
}

void	ft_finish_v3(t_all *all)
{
	if (all->images.wall_middle_v1)
		mlx_destroy_image(all->window.mlx, all->images.wall_middle_v1);
	if (all->images.wall_middle_v2)
		mlx_destroy_image(all->window.mlx, all->images.wall_middle_v2);
	if (all->images.wall_middle_v3)
		mlx_destroy_image(all->window.mlx, all->images.wall_middle_v3);
	if (all->images.wall_middle)
		mlx_destroy_image(all->window.mlx, all->images.wall_middle);
	if (all->images.wall_right)
		mlx_destroy_image(all->window.mlx, all->images.wall_right);
	if (all->images.wall_top_left)
		mlx_destroy_image(all->window.mlx, all->images.wall_top_left);
	if (all->images.wall_top_right)
		mlx_destroy_image(all->window.mlx, all->images.wall_top_right);
	if (all->images.wall_top_shark)
		mlx_destroy_image(all->window.mlx, all->images.wall_top_shark);
	if (all->images.wall_top)
		mlx_destroy_image(all->window.mlx, all->images.wall_top);
	if (all->window.mlx_win)
		mlx_destroy_window(all->window.mlx, all->window.mlx_win);
	if (all->window.mlx)
	{
		mlx_destroy_display(all->window.mlx);
		free(all->window.mlx);
	}
}
