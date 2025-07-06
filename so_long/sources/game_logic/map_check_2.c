/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:22:33 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/23 18:22:37 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

// Function to create a duplicate of the map_grid and validate allocation
char	**validate_map_grid_allocation(t_game_data *game)
{
	char	**temp_map;
	int		y;

	temp_map = malloc(sizeof(char *) * (game->map_height + 1));
	y = 0;
	if (!temp_map)
		return (NULL);
	while (game->map_grid[y])
	{
		temp_map[y] = ft_strdup(game->map_grid[y]);
		if (!temp_map[y])
		{
			while (y >= 0)
			{
				free(temp_map[y]);
				y--;
			}
			free(temp_map);
			return (NULL);
		}
		y++;
	}
	temp_map[y] = 0;
	return (temp_map);
}

int	check_all_collectible(char **temp_map)
{
	int	x;
	int	y;

	y = 0;
	while (temp_map[y])
	{
		x = 0;
		while (temp_map[y][x])
		{
			if (temp_map[y][x] == 'C')
				return (FAIL);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

void	check_positions(t_game_data *game)
{
	int	x;
	int	y;

	y = 0;
	game->movement_count = 0;
	while (game->map_grid[y])
	{
		x = 0;
		while (game->map_grid[y][x])
		{
			if (game->map_grid[y][x] == 'P')
			{
				game->player_pos_x = x;
				game->player_pos_y = y;
			}
			x++;
		}
		y++;
	}
}

// Function to check the valid path using flood fill
int	check_valid_path(t_game_data *game, char **temp_map)
{
	check_positions(game);
	flood_fill(game, game->player_pos_y + 1, game->player_pos_x, temp_map);
	flood_fill(game, game->player_pos_y - 1, game->player_pos_x, temp_map);
	flood_fill(game, game->player_pos_y, game->player_pos_x + 1, temp_map);
	flood_fill(game, game->player_pos_y, game->player_pos_x - 1, temp_map);
	if (game->exit_found == 0 || !check_all_collectible(temp_map))
		return (FAIL);
	return (SUCCESS);
}

// Main valid path checker function
int	valid_path_checker(t_game_data *game)
{
	char	**temp_map;

	temp_map = validate_map_grid_allocation(game);
	if (!temp_map)
		return (FAIL);
	game->exit_found = 0;
	if (!check_valid_path(game, temp_map))
		return (ft_free(temp_map), 0);
	ft_free(temp_map);
	return (SUCCESS);
}
