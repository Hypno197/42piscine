/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 04:13:35 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/29 21:54:00 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_visibility(char **grid, char *views);

int ft_strlen(char *str)
{
    int c;

    c = 0;
    while (*str != '\0')
    {
        str++;
        c++;
    }
    return (c);
}

char **crgrid(void)
{
    char    **matrix;
    int     i;
    int     j;

    i = 0;
    matrix = (char **)malloc(4 * sizeof (char*));
    if(matrix == NULL)
        return 0;
    while(i < 4)
	{
		matrix[i] = (char *)malloc(4 * sizeof (char));
        if (matrix[i] == NULL)
            return 0;
        j = -1;
        while(++j < 4)
            matrix[i][j] = '0';
        i++;
    }
    return matrix;
}

int conditions(char *cu, char *cd, char *rl, char *rr)
{
    int i;

    i = 0;
    while(i < 4)
    {
		if ((cu[i] == '4' && cd[i] != '1') ||( cd[i] == '4' && cu[i] != '1'))
	            return 0;
		else if((rl[i] == '4' && rr[i] != '1') ||( rr[i] == '4' && rl[i] != '1'))
              return 0;
		else if((cu[i] + cd[i] - '0') > '5' || (rl[i] + rr[i] - '0') > '5')
             return 0;
		else if((rl[i] == '3' && rr[i] == '3'))
                return 0;
    	i++;
	}
	return 1;
}

int is_valid(char **grid, int row, int col, char num)
{
    int i = 0;

    while (i < 4)
    {
        if ((grid[row][i] == num) || (grid[i][col] == num))
            return 0;
        i++;
    }
    return 1;
}

int print_grid(char **grid)
{
    int i = 0;

    while (i < 4)
    {
        write(1, grid[i], 4);
        write(1, "\n", 1);
        i++;
    }
	return 1;
}

int solve_grid(char **grid, char *views)
{
    int row;
    int col;
    int num;

    row = 0;
	while (row < 4)
    {
		print_grid(grid);
		write(1, "dio\n", 4);
        col = 0;
        while (col < 4)
        {
            if (grid[row][col] == '0') // Check for empty cell
            {
                num = '1'; // Start trying numbers from '1' to '4'
                while (num <= '4')
                {
                    if (is_valid(grid, row, col, num)) // Validate placement
                    {
                        grid[row][col] = num; // Place number
                        if (solve_grid(grid, views)) // Recursive call
                        {
                                return 1; // Valid solution found
                        }
                        grid[row][col] = '0'; // Backtrack
                    }
                    num++;
                }
                return 0; // If no number is valid, return 0
            }
            col++;
        }
        row++;
    }
	 if (check_visibility(grid, views) == 1)
    // If we reach here, it means the grid is full and valid
    return 1; // Print the completed grid
}
/*
int solve_grid(char **grid, char *views) {
    int row, col;
    char num;

    // Cerca una cella vuota
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            if (grid[row][col] == '0') {
                // Prova numeri da '1' a '4'
                for (num = '1'; num <= '4'; num++) {
                    if (is_valid(grid, row, col, num)) {
                        grid[row][col] = num;

                        // Ricorsione per il resto della griglia
                        if (solve_grid(grid, views))
                            return 0;

                        // Backtrack: resetta la cella se non va bene
                        grid[row][col] = '0';
                    }
                }
                return 0; // Nessun numero è valido, quindi fallimento
            }
        }
    }

    // Controlla la visibilità solo se tutta la griglia è riempita
    if (check_visibility(grid, views))
        return print_grid(grid);

    return 0;
}
*/

int validate(char *str, int i, char **matrix)
{
    char *colup;
    char *coldwn;
    char *rowlt;
    char *rowrt;
	
	colup = (char *)malloc(4 * sizeof (char));
	coldwn = (char *)malloc(4 * sizeof (char));
	rowlt = (char *)malloc(4 * sizeof (char));
	rowrt = (char *)malloc(4 * sizeof (char));
	while (++i <16)
    {
        if(i < 4)
            colup[(i % 4)] = str[i];
		else if(i >= 4 && i < 8)
            coldwn[(i % 4)] = str[i];
		else if(i >= 8 && i < 12)
            rowlt[(i % 4)] = str[i];
		else    
			rowrt[(i % 4)] = str[i];
	}
		if (conditions(colup, coldwn, rowlt, rowrt) == 1)
			return solve_grid(matrix, str);
		else
		return 0;
}
/*
int check_visibility(int *views, char **grid)
{
    int i = 0;

    while (i < 4)
    {
        if (vis_utod(grid, i) != views[i] || vis_dtou(grid, i) != views[i + 4])
            return 0;
        if (vis_ltor(grid, i) != views[i + 8] || vis_rtol(grid, i) != views[i + 12])
            return 0;
        i++;
    }
    return 1;
}
*/
int vis_ltor(char **grid, int r)
{
    int	hmax;
    int	visible;
	int	i;

	i = 0;
    visible = 0;
	hmax = 0;
	while(i < 4)
	{
		if(grid[r][i] - '0'> hmax)
		{
			visible++;
			hmax = grid[r][i];
		}
	i++;
	}
	return visible;
}

int vis_rtol(char **grid, int r)
{
    int hmax;
    int visible;
    int i;

    i = 3;
    visible = 0;
    hmax = 0;
    while(i >= 0 )
    {
        if(grid[r][i] - '0'> hmax)
        {
            visible++;
            hmax = grid[r][i];
        }
    i--;
    }
    return visible;
}

int vis_dtou(char **grid, int r)
{
    int hmax;
    int visible;
    int i;

    i = 3;
    visible = 0;
    hmax = 0;
    while(i >= 0 )
    {
        if(grid[i][r] - '0'> hmax)
        {
            visible++;
            hmax = grid[i][r];
        }
    i--;
    }
    return visible;
}

int vis_utod(char **grid, int r)
{
    int hmax;
    int visible;
    int i;

    i = 0;
    visible = 0;
    hmax = 0;
    while(i < 3)
    {
        if(grid[i][r] - '0'> hmax)
        {
            visible++;
            hmax = grid[i][r];
        }
    i++;
    }
    return visible;
}

int check_visibility(char **grid, char *views) {
    int i;

    for (i = 0; i < 4; i++) {
        if (vis_utod(grid, i) != views[i] - '0') return 0;
    }
    return 1;
}

/*
int check_visibility(char *views, char **grid, int row, int col)
{
    // Check visibility for the column (up to down and down to up)
    if (vis_utod(grid, col) != (views[col] - '0') || vis_dtou(grid, col) != (views[col + 4] - '0'))
        return 0;

    // Check visibility for the row (left to right and right to left)
    if (vis_ltor(grid, row) != (views[row + 8] - '0') || vis_rtol(grid, row) != (views[row + 12] - '0'))
        return 0;

    return 1; // If all conditions are satisfied
}
*/
char *extrval(char *str, char **matrix)
{
    int     i;
    int     j;
    char    *strex;

    strex = (char *)malloc(16 * sizeof (char));
    i=0;
    j=0;
    while (str[i])
    {
        if (str[i] >= '1' && str[i] <='4')
        {
            strex[j] = str[i];
            j++;
        }
        i++;
    }
    if (ft_strlen(strex) != 16 || validate(strex, -1, matrix) == 0)
		return ("Error");
    return strex;
}

int main(int ac, char **av)
{
    char    *views;
    char    **matrix;
	
	 if (ac != 2)
    {
        write(1, "Error\n", 6);
        return 1;
    }
	matrix = crgrid();
    views = extrval(av[1], matrix);
    if (*views == 'E')
	{
		write(1, "Error\n", 6);
		return 1;
	}
	free(matrix);
		return 0;
}
