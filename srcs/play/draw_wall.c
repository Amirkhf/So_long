/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:41:14 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/03 19:24:47 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	draw_wall(t_play *play, char **map, int len_line)
{
	int	i;
	int	j;

	i = 1;
	draw_wall_top(play, map[0], len_line);
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (j == 0)
				mlx_put_image_to_window(play->mlx, play->mlx_win,
					play->wall_left, j * play->width, i * play->height);
			else if (j == len_line - 1)
				mlx_put_image_to_window(play->mlx, play->mlx_win,
					play->wall_right, j * play->width, i * play->height);
			else if (j != len_line - 1 && j != 0 && map[i][j] == '1')
				draw_wall_middle(play, j, i);
			j++;
		}
		i++;
	}
	draw_wall_down(play, map[i], len_line, i);
}

void	draw_wall_middle(t_play *play, int j, int i)
{
	mlx_put_image_to_window(play->mlx, play->mlx_win, play->wall_middle, j
		* play->width, i * play->height);
}

void	draw_wall_top(t_play *play, char *str, int len_line)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
			mlx_put_image_to_window(play->mlx, play->mlx_win,
				play->wall_top_left, i * play->width, 0);
		if (i == len_line - 1)
			mlx_put_image_to_window(play->mlx, play->mlx_win,
				play->wall_top_right, i * play->width, 0);
		else
			mlx_put_image_to_window(play->mlx, play->mlx_win, play->wall_top, i
				* play->width, 0);
		i++;
	}
}

void	draw_wall_down(t_play *play, char *str, int len_line, int j)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			mlx_put_image_to_window(play->mlx, play->mlx_win,
				play->wall_down_left, i * play->width, j * play->height);
		}
		else if (i == len_line - 1)
		{
			mlx_put_image_to_window(play->mlx, play->mlx_win,
				play->wall_down_right, i * play->width, j * play->height);
		}
		else
		{
			mlx_put_image_to_window(play->mlx, play->mlx_win, play->wall_down, i
				* play->width, j * play->height);
		}
		i++;
	}
}