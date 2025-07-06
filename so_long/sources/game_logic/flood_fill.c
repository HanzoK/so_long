/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:30:50 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/23 18:22:26 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

void	flood_fill(t_game_data *game, int y, int x, char **dupe_map)
{
	if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width)
		return ;
	if (dupe_map[y] == NULL)
		return ;
	if (dupe_map[y][x] == '1' || dupe_map[y][x] == 'P')
		return ;
	else if (dupe_map[y][x] == '0')
		dupe_map[y][x] = 'P';
	else if (dupe_map[y][x] == 'C')
		dupe_map[y][x] = 'P';
	else if (dupe_map[y][x] == 'E')
	{
		game->exit_found += 1;
		dupe_map[y][x] = 'P';
	}
	flood_fill(game, y + 1, x, dupe_map);
	flood_fill(game, y - 1, x, dupe_map);
	flood_fill(game, y, x + 1, dupe_map);
	flood_fill(game, y, x - 1, dupe_map);
}
