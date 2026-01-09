/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:30:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 16:58:10 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

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
	exit(0);
}
