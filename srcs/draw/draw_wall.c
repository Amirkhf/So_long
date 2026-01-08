/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:16:30 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/08 13:27:55 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	draw_wall(t_all *all)
{
	int	i;
	int	len_line;
	int	nb_line;

	nb_line = ft_nb_line(all->window.map);
	len_line = ft_strlen(all->window.map[0]);
	i = 1;
	draw_wall_top(all, len_line, all->window.map[0]);
	while (i < nb_line - 1)
	{
		draw_wall_middle(all, len_line, i, all->window.map[i]);
		i++;
	}
	draw_wall_down(all, len_line, nb_line, all->window.map[i]);
}

void	draw_wall_middle(t_all *all, int len_line, int j, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
			print_img(all, all->images.wall_left, i, j);
		else if (i == len_line - 1)
			print_img(all, all->images.wall_right, i, j);
		else if (all->window.map[j][i] == '1')
			random_wall_middle(all, i, j);
		i++;
	}
}


void	draw_wall_down(t_all *all, int len_line, int nb_line, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
			print_img(all, all->images.wall_down_left, i, nb_line - 1);
		else if (i == len_line - 1)
			print_img(all, all->images.wall_down_right, i, nb_line - 1);
		else
			print_img(all, all->images.wall_down, i, nb_line - 1);
		i++;
	}
}

void	draw_wall_top(t_all *all, int len_line, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
			print_img(all, all->images.wall_top_left, i, 0);
		else if (i == len_line - 1)
			print_img(all, all->images.wall_top_right, i, 0);
		else
			print_ramdom_wall_top(all, i, 0);
		i++;
	}
}

