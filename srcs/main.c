/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:35:43 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/07 18:31:37 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_map(argv[1]))
			return (write(1, "Error\n", 6), 0);
	}
	return (1);
}

int	check_map(char *str)
{
	char		**map;
	p_position	position_player;

	map = NULL;
	if (check_name(str))
		return (1);
	map = read_map(str, map);
	position_player = player_position(map);
	if (check_rectangular(map, ft_strlen(map[0])) || check_wall(map)
		|| check_character(map) || count_elements(map) || check_ennemy(map,
			&position_player))
		return (1);
	dfs(map, position_player.x, position_player.y);
	if (verif_path(map))
		return (1);
	return (0);
}
