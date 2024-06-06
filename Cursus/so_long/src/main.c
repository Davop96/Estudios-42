/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:29:47 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/06 16:08:41 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	load_textures(game);
	create_images(game);
	render_map(game);
	initialize_hooks(game);
	mlx_loop(game->mlx);
	free_map_memory(game->map, game->map_height);
}

void	close_window(t_game *game)
{
	ft_printf("Game Over\n");
	mlx_terminate(game->mlx);
	free_map_memory(game->map, game->map_height);
	exit(0);
}

void	create_images(t_game *game)
{
	load_textures(game);
	verify_images(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	initialize_game(&game);
	game.map = read_map(argv[1], &game.map_width, &game.map_height);
	if (!game.map)
	{
		ft_printf("Error: Failed to read map\n");
		return (1);
	}
	find_player_and_collectibles(&game);
	if (initialize_mlx(&game))
	{
		free_map_memory(game.map, game.map_height);
		return (1);
	}
	show_disclaimer(&game);
	mlx_loop(game.mlx);
	return (0);
}
