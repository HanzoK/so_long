/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:21:06 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/24 19:23:00 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

int	is_map_grid_valid(t_game_data *game, int y, int x)
{
	char	tile;

	while (game->map_grid[y])
	{
		while (game->map_grid[y][x])
		{
			tile = game->map_grid[y][x];
			if (tile != '1' && tile != '0'
				&& tile != 'P' && tile != 'E' && tile != 'C')
				return (0);
			if (tile == 'P')
				game->player_count += 1;
			else if (tile == 'E')
				game->exit_count += 1;
			else if (tile == 'C')
				game->collectible_count += 1;
			x++;
		}
		x = 0;
		y++;
	}
	if (game->player_count != 1 || game->exit_count != 1
		|| game->collectible_count == 0)
		return (FAIL);
	return (SUCCESS);
}

int	check_valid_walls(t_game_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map_grid[0][x] && game->map_grid[game->map_height - 1][x])
	{
		if (game->map_grid[0][x] != '1'
			|| game->map_grid[game->map_height - 1][x] != '1')
			return (FAIL);
		x++;
	}
	y = 0;
	while (game->map_grid[y])
	{
		if (game->map_grid[y][0] != '1'
			|| game->map_grid[y][game->map_width - 1] != '1')
			return (FAIL);
		y++;
	}
	return (SUCCESS);
}

int	is_map_grid_rectangular(t_game_data *game)
{
	int	y;
	int	row_length;

	y = 0;
	row_length = ft_strlen(game->map_grid[0]);
	while (game->map_grid[y])
	{
		if (ft_strlen(game->map_grid[y]) != row_length)
			return (FAIL);
		y++;
	}
	game->map_width = row_length;
	game->map_height = y;
	return (SUCCESS);
}

void	map_grid_checker(t_game_data *game)
{
	game->collectible_count = 0;
	game->player_count = 0;
	game->exit_count = 0;
	if (!is_map_grid_valid(game, 0, 0) || !is_map_grid_rectangular(game)
		|| !check_valid_walls(game) || !valid_path_checker(game))
		free_map_on_error(game);
	return ;
}
