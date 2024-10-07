/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:00:59 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/07 12:53:40 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	count_words(char *str, char *cset)
{
	int	i;
	int	words;
	int	len;

	len = 0;
	words = 0;
	i = 0;
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
	}
	return (words);
}

char	**ft_splitloc(char **mtx, char *str, char *charset, int i)
{
	int	j;
	int	k;

	j = 0;
	while (ft_chkdel(str[i], charset) == 1)
		i++;
	while (str[i] && j < count_words(str, charset))
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
	mtx = (char **)malloc(((count_words(str, charset)) + 1) * sizeof(char *));
	ft_splitloc(mtx, str, charset, i);
	return (mtx);
}
/*
int main(int ac, char **av)
{
	int i =0;
	if (ac != 3)
		return 2;
	char **mtx = ft_split(av[1], av[2]);
	while (mtx[i])
	{
	printf("%s\n", mtx[i]);
		i++;
	}
	return 0;
}
*/
