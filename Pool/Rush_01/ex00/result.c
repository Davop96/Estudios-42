/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiro-bo <dmiro-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:08:48 by dmiro-bo          #+#    #+#             */
/*   Updated: 2023/10/01 18:00:43 by dmiro-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int grid[4][4], int gap, int pattern[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (gap / 4 == 3)
	{
		while (i < 4)
		{
			if (grid[i][gap % 4] > max)
			{
				max = grid[i][gap % 4];
				count++;
			}
			i++;
		}
		if (pattern[gap % 4] != count)
			return (1);
	}
	return (0);
}

int	check_row_right(int grid[4][4], int gap, int pattern[16])
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = 4;
	max_size = 0;
	visible_towers = 0;
	if (gap % 4 == 3)
	{
		while (--i >= 0)
		{
			if (grid[gap / 4][i] > max_size)
			{
				max_size = grid[gap / 4][i];
				visible_towers++;
			}
		}
		if (pattern[12 + gap / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_col_down(int grid[4][4], int gap, int pattern[16])
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (gap / 4 == 3)
	{
		while (i >= 0)
		{
			if (grid[i][gap % 4] > max)
			{
				max = grid[i][gap % 4];
				count++;
			}
			i--;
		}
		if (pattern[4 + gap % 4] != count)
			return (1);
	}
	return (0);
}

int	check_row_left(int grid[4][4], int gap, int pattern[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (gap % 4 == 3)
	{
		while (i < 4)
		{
			if (grid[gap / 4][i] > max)
			{
				max = grid[gap / 4][i];
				count++;
			}
			i++;
		}
		if (pattern[8 + gap / 4] != count)
			return (1);
	}
	return (0);
}

int	check_cell(int grid[4][4], int gap, int pattern[16])
{
	if (check_row_left(grid, gap, pattern) == 1)
		return (1);
	if (check_row_right(grid, gap, pattern) == 1)
		return (1);
	if (check_col_down(grid, gap, pattern) == 1)
		return (1);
	if (check_col_up(grid, gap, pattern) == 1)
		return (1);
	return (0);
}
