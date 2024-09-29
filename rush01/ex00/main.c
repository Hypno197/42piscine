/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 04:13:35 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/29 05:02:49 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int solve(char grid[4][4], char strex[16], int pos)
{
	int	h;
	int	i;

	i = 0;
	if(pos == 16)
		return (1);
	h = 0;
	while (++size <= 4)
	{
	if (chkchar(grid)
	}
}


int validate(char *str, int i)
{
    char *colup;
    char *coldwn;
    char *rowlt;
    char *rowrt;

	colup = (char *)malloc(4 * sizeof (char));
	coldwn = (char *)malloc(4 * sizeof (char));
	rowlt = (char *)malloc(4 * sizeof (char));
	rowrt = (char *)malloc(4 * sizeof (char));
	i = 0;
    while (i <16)
    {
        if(i < 4)
            colup[(i % 4)] = str[i];
		else if(i >= 4 && i < 8)
            coldwn[(i % 4)] = str[i];
		else if(i >= 8 && i < 12)
            rowlt[(i % 4)] = str[i];
		else    
			rowrt[(i % 4)] = str[i];
    i++;
	}
    printf("%s\n", colup);
printf("%s\n", coldwn);
printf("%s\n", rowlt);
printf("%s\n", rowrt);

	return (conditions(colup, coldwn, rowlt, rowrt));
}

int vis_ltor(char **grid, int r)
{
    int	hmax;
    int	visible;
	int	i;

	i = 0;
    visible = 1;
	hmax = grid[r][0];
	while(i < 4)
	{
		if(grid[r][i] > hmax)
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
    visible = 1;
    hmax = grid[r][3];
    while(i >= 0 )
    {
        if(grid[r][i] > hmax)
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
    visible = 1;
    hmax = grid[3][i];
    while(i >= 0 )
    {
        if(grid[i][r] > hmax)
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
    visible = 1;
    hmax = grid[0][i];
    while(i < 3)
    {
        if(grid[i][r] > hmax)
        {
            visible++;
            hmax = grid[i][r];
        }
    i++;
    }
    return visible;
}

char *extrval(char *str)
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
    if (ft_strlen(strex) != 16 || validate(strex, -1) == 0)
		return ("Error");
    return strex;
}

int main(int ac, char **av)
{
    char    *views;
    char    **matrix;
	
	matrix = crgrid();
    if (ac != 2)
        return 0;
    views = extrval(av[1]);
    printf("%s\n", views);
    printf("%s\n", matrix[3]);
    return 0;
}
