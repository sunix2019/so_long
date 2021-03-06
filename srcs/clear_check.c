/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:34:10 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/07 15:49:07 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_check(t_game *game, int clear, int *finish_position)
{
	if (clear == 1)
	{
		*finish_position = EXIT;
		ft_putendl_fd("Teleported to the next map...!!", STDOUT_FILENO);
		game_exit(game);
	}
}
