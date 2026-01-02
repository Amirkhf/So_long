/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:22:05 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/02 15:24:57 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int	main(int argc, char **argv)
{
	char		**map;
	t_images	data;

	map = NULL;
	if (argc != 2)
		return (0);
	else if (parsing(argv[1], map))
		return (write(1, "Error\n", 6), 0);
	struct_play(&data);
	map = read_map(argv[1], map);
	draw_map(&data, map);
	return (0);
}

void	draw_map(t_images *data, char **map)
{
	draw_ground(data, map);
	draw_wall(data, map);
	draw_exit(data, map);
	draw_pieces(data, map);
	draw_player(data, map);
	mlx_loop(data->mlx);
}

void	draw_pieces(t_images *data, char **map)
{
	while (map[data->i])
	{
		data->j = 0;
		while (map[data->i][data->j])
		{
			if (map[data->i][data->j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->collectible, data->j * 63, data->i * 20);
			}
			data->j++;
		}
		data->i++;
	}
}

void	draw_player(t_images *data, char **map)
{
	while (map[data->i])
	{
		data->j = 0;
		while (map[data->i][data->j])
		{
			if (map[data->i][data->j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
					data->j * 63, data->i * 20);
			}
			data->j++;
		}
		data->i++;
	}
}

void	draw_ground(t_images *data, char **map)
{
	while (map[data->i])
	{
		data->j = 0;
		while (map[data->i][data->j])
		{
			if (map[data->i][data->j] == '0')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
					data->j * 63, data->i * 20);
			}
			data->j++;
		}
		data->i++;
	}
}
void	draw_exit(t_images *data, char **map)
{
	while (map[data->i])
	{
		data->j = 0;
		while (map[data->i][data->j])
		{
			if (map[data->i][data->j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
					data->j * 63, data->i * 20);
			}
			data->j++;
		}
		data->i++;
	}
}

void	draw_wall(t_images *data, char **map)
{
	while (map[data->i])
	{
		data->j = 0;
		while (map[data->i][data->j])
		{
			if (map[data->i][data->j] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->Wall,
					data->j * 63, data->i * 20);
			}
			data->j++;
		}
		data->i++;
	}
}