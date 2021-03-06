/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:19:50 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/07 16:49:35 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

static void	destroy_img(void *mlx, t_img *texs)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(mlx, texs[i].img);
		i++;
	}
}

int	game_exit(t_game *game)
{
	destroy_map(&game->map);
	destroy_img(game->mlx, game->texs);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_putendl_fd("Exit", STDOUT_FILENO);
	exit(0);
	return (0);
}
