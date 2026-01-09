/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:07:07 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 18:57:15 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_map(t_all *all)
{
	draw_wall(all);
	draw_ground(all);
	draw_exit(all);
	draw_player(all);
	draw_collectible(all);
	draw_ennemy(all);
}
