/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 04:13:35 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/29 19:13:02 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_valid(char **grid, int row, int col, int num);
void print_grid(char **grid);
int solve(char **matrix, char *views, int row, int col);
int validate(char *str, int i, char **matrix);
int check_visibility(char **m, char *views);
int vis_ltor(char **grid, int r);
int vis_rtol(char **grid, int r);
int vis_dtou(char **grid, int r);
int vis_utod(char **grid, int r);

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
int validate(char *str, int i, char **matrix)
{
    char *colup;
    char *coldwn;
    char *rowlt;
    char *rowrt;

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
		    return solve(matrix, str, 0, 0);
		return 0;
}

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
	
	matrix = crgrid();
    if (ac != 2)
        return 0;
    views = extrval(av[1], matrix);
    if (*views == 'E')
	{
		write(1, "Error\n", 6);
		return 1;
	}
		return 0;
}
