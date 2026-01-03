/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:22:05 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/03 20:12:46 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_play	play;
	t_map	map_size;

	map = NULL;
	if (argc != 2)
		return (0);
	else if (parsing(argv[1], map))
		return (write(1, "Error\n", 6), 0);
	map = read_map(argv[1], map);
	struct_map(&map_size, map);
	struct_play(&play, &map_size);
	draw_map(&play, map, ft_strlen(map[0]));
	mlx_loop(play.mlx);
	return (0);
}
