/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:23:48 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 17:39:56 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_raycasting(t_cub *cub, int i)
{
	if (cub->rays[i].horz.horz_distance > cub->rays[i].vert.vert_distance)
		cub->rays[i].was_vertical = true;
	else if (cub->rays[i].horz.horz_distance < cub->rays[i].vert.vert_distance)
		cub->rays[i].was_vertical = false;
	else if (i > 0)
		cub->rays[i].was_vertical = cub->rays[i - 1].was_vertical;
	else
		cub->rays[i].was_vertical = true;
	if (cub->rays[i].was_vertical)
	{
		cub->rays[i].hitx = cub->rays[i].vert.hitvertx;
		cub->rays[i].hity = cub->rays[i].vert.hitverty;
	}
	else
	{
		cub->rays[i].hitx = cub->rays[i].horz.hithorzx;
		cub->rays[i].hity = cub->rays[i].horz.hithorzy;
	}
}

void	ft_rays(t_cub *cub)
{
	float	ray_angle;
	int		i;

	ray_angle = cub->player.angle + M_PI / 6.0;
	i = -1;
	while (++i < NUMBER_RAYS)
	{
		ray_angle = ft_periodic(ray_angle);
		cub->rays[i].angle = ray_angle;
		cub->rays[i].up = ray_angle > 0 && ray_angle < M_PI;
		cub->rays[i].down = !cub->rays[i].up;
		cub->rays[i].left = ray_angle > M_PI_2 && ray_angle < 3.0 * M_PI_2;
		cub->rays[i].right = !cub->rays[i].left;
		cub->rays[i].horz.horz_distance = ft_horizontal(cub, i);
		cub->rays[i].vert.vert_distance = ft_vertical(cub, i);
		cub->rays[i].distance = ft_min(cub->rays[i].horz.horz_distance, \
		cub->rays[i].vert.vert_distance);
		ft_raycasting(cub, i);
		ray_angle -= (M_PI / (3.0 * NUMBER_RAYS));
	}
}
