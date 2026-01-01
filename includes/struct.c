/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:08:42 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/01 15:34:06 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	struct_count(t_count *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->j = 0;
	data->i = 0;
}

void	struct_position(t_position *position)
{
	position->x = 0;
	position->y = 0;
}