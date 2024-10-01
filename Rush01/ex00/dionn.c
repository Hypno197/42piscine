/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dionn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:16:54 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/29 23:25:21 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		check_visibility(char	**grid,	char	*views);
int		solve_grid(char	**grid,	char	*views);
void	print_grid(char	**grid);

int	ft_strlen(char	*str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

char	**crgrid(void)
{
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	matrix = (char **)malloc(4 * sizeof(char *));
	if (matrix == NULL)
		return (0);
	while (i < 4)
	{
		matrix[i] = (char *)malloc(4 * sizeof(char));
		if (matrix[i] == NULL)
			return (0);
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = '0';
			j++;
		}
		i++;
	}
	return (matrix);
}

int	is_valid(char **grid, int row, int col, char num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	print_grid(char	**grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &grid[i][j], 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (1)
}

int	vis_ltor(char **grid, int r)
{
	int	hmax;
	int	visible;
	int	i;

	hmax = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[r][i] - '0' > hmax)
		{
			visible++;
			hmax = grid[r][i] - '0';
		}
		i++;
	}
	return (visible);
}

int	vis_rtol(char **grid, int r)
{
	int	hmax;
	int	visible;
	int	i;

	hmax = 0;
	visible = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[r][i] - '0' > hmax)
		{
			visible++;
			hmax = grid[r][i] - '0';
		}
		i--;
	}
	return (visible);
}

int	vis_utod(char **grid, int c)
{
	int	hmax;
	int	visible;
	int	i;

	hmax = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][c] - '0' > hmax)
		{
			visible++;
			hmax = grid[i][c] - '0';
		}
		i++;
	}
	return (visible);
}

int	vis_dtou(char **grid, int c)
{
	int	hmax;
	int	visible;
	int	i;

	hmax = 0;
	visible = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][c] - '0' > hmax)
		{
			visible++;
			hmax = grid[i][c] - '0';
		}
		i--;
	}
	return (visible);
}

int	check_visibility(char	**grid,	char	*views)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (vis_utod(grid, i) != views[i] - '0')
			return (0);
		if (vis_dtou(grid, i) != views[i + 4] - '0')
			return (0);
		if (vis_ltor(grid, i) != views[i + 8] - '0')
			return (0);
		if (vis_rtol(grid, i) != views[i + 12] - '0')
			return (0);
		i++;
	}
	return (1);
}

int	solve_grid(char	**grid,	char	*views, int row, int col)
{
	char	num;

	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
			if (grid[row][col] == '0')
			{
				num = '0';
				while (++num <= '4')
					if (is_valid(grid, row, col, num))
					{
						grid[row][col] = num;
						if (solve_grid(grid, views))
							return (1);
						grid[row][col] = '0';
					}
				return (0);
			}
		row++;
	}
	if (check_visibility(grid, views))
		return print_grid(grid);
	return (0);
}

char	*extract_views(char *str)
{
	int		i;
	int		j;
	char	*views;

	i = 0;
	j = 0;
	views = (char *)malloc(16 * sizeof(char));
	if (!views)
		return (NULL);
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
			views[j++] = str[i];
		i++;
	}
	if (j != 16)
		return ("Error");
	return (views);
}

int	main(int ac, char **av)
{
	char	**matrix;
	char	*views;

	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	matrix = crgrid();
	if (!matrix)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	views = extract_views(av[1]);
	if (*views == 'E')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!solve_grid(matrix, views, -1, -1))
		write(1, "Error\n", 6);
	return (0);
}
