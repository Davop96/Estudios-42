/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:16:55 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/14 01:37:37 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stack_clear(t_map **stack)
{
	t_map	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack)->map);
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

char	**free_matrix(char	**matrix, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
	return (matrix);
}

void	delete_texture(t_game **game)
{
	mlx_delete_texture((*game)->texture.player);
	(*game)->texture.player = NULL;
	mlx_delete_texture((*game)->texture.exit);
	(*game)->texture.exit = NULL;
	mlx_delete_texture((*game)->texture.collec);
	(*game)->texture.collec = NULL;
	mlx_delete_texture((*game)->texture.wall);
	(*game)->texture.wall = NULL;
	mlx_delete_texture((*game)->texture.ground);
	(*game)->texture.ground = NULL;
}

void	delete_image(t_game **game)
{
	mlx_delete_image((*game)->mlx, (*game)->image.player);
	(*game)->image.player = NULL;
	mlx_delete_image((*game)->mlx, (*game)->image.exit);
	(*game)->image.exit = NULL;
	mlx_delete_image((*game)->mlx, (*game)->image.collec);
	(*game)->image.collec = NULL;
	mlx_delete_image((*game)->mlx, (*game)->image.wall);
	(*game)->image.wall = NULL;
	mlx_delete_image((*game)->mlx, (*game)->image.ground);
	(*game)->image.ground = NULL;
}

void	free_game(t_game *game, int error)
{
	if (error == 1)
	{
		game->matrix = free_matrix(game->matrix, game->size.y);
		stack_clear(&game->map);
		free(game);
	}
	if (error == 0)
	{
		game->matrix = free_matrix(game->matrix, game->size.y);
		stack_clear(&game->map);
		delete_texture(&game);
		delete_image(&game);
		mlx_terminate(game->mlx);
		free(game);
	}
	if (error == 2)
	{
		stack_clear(&game->map);
		free(game);
	}
}
