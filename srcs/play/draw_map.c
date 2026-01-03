/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:26:22 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/03 17:49:59 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	draw_map(t_play *play, char **map, int len_line)
{
	draw_wall(play, map, len_line);
	draw_ground(play, map);
	draw_player(play, map);
	draw_exit(play, map);
	draw_collectible(play, map);
}
void	draw_collectible(t_play *play, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				mlx_put_image_to_window(play->mlx, play->mlx_win,
					play->collectible, j * play->width, i * play->height);
			}
			j++;
		}
		i++;
	}
}
void	draw_exit(t_play *play, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				mlx_put_image_to_window(play->mlx, play->mlx_win, play->exit, j
					* play->width, i * play->height);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_play *play, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				mlx_put_image_to_window(play->mlx, play->mlx_win, play->player,
					j * play->width, i * play->height);
			}
			j++;
		}
		i++;
	}
}

void	draw_ground(t_play *play, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				mlx_put_image_to_window(play->mlx, play->mlx_win, play->ground,
					j * play->width, i * play->height);
			}
			j++;
		}
		i++;
	}
}
