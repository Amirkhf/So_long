/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_check_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:55:48 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/08 12:06:31 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"


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
		return (free_function(map), 1);
	dfs(map, position_player.x, position_player.y);
	if (verif_path(map))
		return (free_function(map), 1);
	return (free_function(map), 0);
}
