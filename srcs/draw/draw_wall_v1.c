/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:27:20 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 20:23:35 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	random_wall_middle(t_all *all, int i, int j)
{
	int	ramdom;

	ramdom = rand() % 4;
	if (ramdom == 0)
		print_img(all, all->images.wall_middle, i, j);
	else if (ramdom == 1)
		print_img(all, all->images.wall_middle_v1, i, j);
	else if (ramdom == 2)
		print_img(all, all->images.wall_middle_v2, i, j);
	else if (ramdom == 3)
		print_img(all, all->images.wall_middle_v3, i, j);
}

void	print_ramdom_wall_top(t_all *all, int i, int j)
{
	int	ramdom;

	ramdom = rand() % 11;
	if (ramdom == 0 || ramdom == 6 || ramdom == 7 || ramdom == 8 || ramdom == 9
		|| ramdom == 10)
		print_img(all, all->images.wall_top, i, j);
	else if (ramdom == 1)
		print_img(all, all->images.wall_top_v3, i, j);
	else if (ramdom == 2)
		print_img(all, all->images.wall_top_v1, i, j);
	else if (ramdom == 3)
		print_img(all, all->images.wall_top_v2, i, j);
	else if (ramdom == 4)
		print_img(all, all->images.wall_top_v4, i, j);
	else if (ramdom == 5)
		print_img(all, all->images.wall_top_v5, i, j);
}

void	print_img(t_all *all, void *img, int i, int j)
{
	mlx_put_image_to_window(all->window.mlx, all->window.mlx_win, img, i
		* all->images.width, j * all->images.height);
}
