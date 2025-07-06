/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:21:10 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/25 13:30:35 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

void	up(t_game_data *game)
{
	move_player(game, game->player_pos_y - 1, game->player_pos_x);
}

void	down(t_game_data *game)
{
	move_player(game, game->player_pos_y + 1, game->player_pos_x);
}

void	left(t_game_data *game)
{
	move_player(game, game->player_pos_y, game->player_pos_x - 1);
}

void	right(t_game_data *game)
{
	move_player(game, game->player_pos_y, game->player_pos_x + 1);
}

int	key_press_handler(int key, t_game_data *game)
{
	if (key == 'w')
		up(game);
	else if (key == 'a')
		left(game);
	else if (key == 's')
		down(game);
	else if (key == 'd')
		right(game);
	else if (key == 65307)
		thanos_snap(game, 1);
	return (SUCCESS);
}
