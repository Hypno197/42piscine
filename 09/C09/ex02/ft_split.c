/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:00:59 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/08 16:04:07 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_chkdel(char c, char *cset)
{
	int	i;

	i = 0;
	while (cset[i])
	{
		if (c == cset[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_wrdlen(char *str, int i, char *cset)
{
	int	c;
	int	len;

	len = 0;
	c = i;
	while (str[c] != '\0' && ft_chkdel(str[c], cset) == 1)
	{
		len++;
		c++;
	}
	return (len);
}

int	count_words(char *str, char *cset, int i)
{
	int	words;
	int	len;

	words = 0;
	while (str[i])
	{
		len = 0;
		while (str[i] && ft_chkdel(str[i], cset) == 0)
		{
			i++;
		}
		while (str[i] && ft_chkdel(str[i], cset) == 1)
		{
			len++;
			i++;
		}
		if (ft_chkdel(str[i], cset) == 0 && ft_chkdel(str[i - len - 1],
				cset) == 0)
			words++;
		else if ((ft_chkdel(str[i], cset) == 0 && (i - len) == 0)
			|| (str[i] == '\0' && ft_chkdel(str[i - len - 1], cset) == 0))
			words++;
	}
	return (words);
}

char	**ft_splitloc(char **mtx, char *str, char *charset, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < count_words(str, charset, 0))
	{
		k = 0;
		while (ft_chkdel(str[i], charset) == 0)
			i++;
		mtx[j] = (char *)malloc((ft_wrdlen(str, i, charset) + 1)
				* sizeof(char));
		while (str[i] && ft_chkdel(str[i], charset) == 1)
		{
			mtx[j][k] = str[i];
			i++;
			k++;
		}
		mtx[j][k] = '\0';
		j++;
	}
	mtx[j] = NULL;
	return (mtx);
}

char	**ft_split(char *str, char *charset)
{
	char	**mtx;
	int		i;

	i = 0;
	if(count_words(str, charset, 0) > 0)
	{
	mtx = (char **)malloc(((count_words(str, charset, 0)) + 1)
			* sizeof(char *));
	ft_splitloc(mtx, str, charset, i);
	}
	return (mtx);
}
/*
int	main(int ac, char **av)
{
	char	**mtx;
	int		i;

	i = 0;
	if (ac != 3)
		return (2);
	mtx = ft_split(av[1], av[2]);
	while (mtx[i] != 0)
	{
		printf("%s\n", mtx[i]);
		i++;
	}
	return (0);
}
*/