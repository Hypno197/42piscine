/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:47:49 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/29 03:04:57 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


/*
 * int chkcharh(char *linea)
{
	int	
}
*/


int	ft_strlen(char *str)
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

//mettere anche arg int n per allungare
char **crgrid(void)
{
	char	**matrix;
	int		i;
	int		j;

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

int validate(char *str, int i)
{
	char colup[4];
	char coldwn[4];
	char rowlt[4];
	char rowrt[4];

	while (*str && ++i <16)
	{
		if(i < 4)
			colup[(i % 4)] = str[i];
		if(i >= 4 && i < 8)
			coldwn[(i % 4)] = str[i];
		if(i >= 8 && i < 12)
			rowlt[(i % 4)] = str[i];
		if(i >= 12 && i < 16)
			rowrt[(i % 4)] = str[i];
	}
	if (conditions(colup, coldwn, rowlt, rowrt) == 0)
		return 0;
	return 1;
}

int conditions(char *cu, char *cd, char *rl, char *rr)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while(++i < 4)
	{
		if(cu[i] == 4 && cd[i] != 1 || cd[i] == 4 && cu[i] != 1)
			retu:rn 0;
		if(rl[i] == 4 && rr[i] != 1 || rr[i] == 4 && rl[i] != 1)
              return 0;
		if((cu[i] + cd[i]) > 5 || (rl[i] + rr[i]) > 5)
             return 0;
		if(rl[i] == 3 && rr[i] == 3 || rr[i] == 4 && rl[i] != 1)
                return 0;	
	}

}

int visibility(char **matrix)
{
	int max_val;
	int current;

	max_val = 0;
	current = 0;
}

char *extrval(char *str)
{
	int		i;
	int		j;
	char	*strex;

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
	if (validate(strex, -1) == 1)
		return ("Error");
	if (ft_strlen(strex) != 16)
        return ("Error");
	return strex;
}



int main(int ac, char **av)
{
	char	*views;
	char	**matrix;

	matrix = crgrid();
	if (ac != 2)
		return 0;
	views = extrval(av[1]);
	printf("%s\n", views);
	printf("%s\n", matrix[0]);/*
	printf("%s\n", matrix[1]);
	printf("%s\n", matrix[2]);
	printf("%s\n", matrix[3]);*/
	return 0;
}
