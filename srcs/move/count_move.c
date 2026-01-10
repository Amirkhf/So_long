/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:21:54 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 13:06:23 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	take_collect(t_all *all)
{
	char	*str_all;
	char	*str;

	all->images.count_collect += 1;
	str_all = ft_itoa(all->images.collect_nb);
	str = ft_itoa(all->images.count_collect);
	mlx_put_image_to_window(all->window.mlx, all->window.mlx_win,
		all->images.wall_top_right, (ft_strlen(all->window.map[0]) - 1)
		* all->images.width, 0 * all->images.height);
	mlx_string_put(all->window.mlx, all->window.mlx_win, all->messure.len_line, 15, 0xFFFFFF,
		"collect: ");
	mlx_string_put(all->window.mlx, all->window.mlx_win, all->messure.len_line + 5, 15, 0xFFFFFF,
		str);
	mlx_string_put(all->window.mlx, all->window.mlx_win, all->messure.len_line + 10, 15, 0xFFFFFF,
		"/");
	mlx_string_put(all->window.mlx, all->window.mlx_win, all->messure.len_line + 15, 15, 0xFFFFFF,
		str_all);
	free(str);
	free(str_all);
}

void	move(t_all *all)
{
	char	*str;

	all->images.count_move += 1;
	str = ft_itoa(all->images.count_move);
	mlx_put_image_to_window(all->window.mlx, all->window.mlx_win,
		all->images.wall_top_left, 0 * all->images.width, 0
		* all->images.height);
	mlx_string_put(all->window.mlx, all->window.mlx_win, 10, 15, 0xFFFFFF,
		"move: ");
	mlx_string_put(all->window.mlx, all->window.mlx_win, 50, 15, 0xFFFFFF, str);
	free(str);
}

int	nb_collect(t_all *all)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (all->window.map[i])
	{
		j = 0;
		while (all->window.map[i][j])
		{
			if (all->window.map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
