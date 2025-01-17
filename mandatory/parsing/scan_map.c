/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:26:45 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/15 18:59:01 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_search(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_neighbours(t_cub *cub, int r, int c)
{
	if (r == 0 || r == cub->rows - 1 || c == 0 || c == cub->cols - 1)
		return (FAILED);
	if (cub->map[r - 1][c] == ' ')
		return (FAILED);
	if (cub->map[r][c + 1] == ' ')
		return (FAILED);
	if (cub->map[r + 1][c] == ' ')
		return (FAILED);
	if (cub->map[r][c - 1] == ' ')
		return (FAILED);
	return (SUCCESS);
}

static void	ft_scan_map_help(t_cub *cub, int r, int c)
{
	if (ft_search(cub->map[r][c], "NSEW"))
	{
		if (cub->player.pr != -1 || cub->player.pc != -1)
		{
			ft_putstr_fd("Error\nmultiple player", 2, 1, RED);
			ft_free_data(cub);
			exit(FAILED);
		}
		cub->player.pr = r;
		cub->player.pc = c;
		cub->player.sens = cub->map[r][c];
	}
	if (ft_search(cub->map[r][c], "0NSEW") && ft_check_neighbours(cub, r, c))
	{
		ft_putstr_fd("Error\nInvalid map", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
}

void	ft_scan_map(t_cub *cub)
{
	int	r;
	int	c;

	r = -1;
	while (++r < cub->rows)
	{
		c = -1;
		while (++c < cub->cols)
		{
			ft_scan_map_help(cub, r, c);
		}
	}
}
