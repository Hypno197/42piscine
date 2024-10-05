/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:00:59 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/05 21:48:48 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// questa prende c e confronta se é roba del cset
int	ft_chkdel(char c, char *cset)
{
	int	i;

	i = 0;
	while (cset[i])
	{
		if (c == cset[i])
			return (1);
	}
	return (0);
}

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

int	ft_wrdlen(char *str, int i, char *cset)
{
	int	c;
	int len;

	len = 0;
	c = i;
	while (str[c] != '\0' && ft_chkdel(str[c], cset) != 1)
	{
		len++;
		c++;
	}
	return (len);
}

	// dobbiamo fare in modo che inizia da 0 e inizia
	// a contare solo quando incontra il char del charset
	// e conta solo se è chiuso.
int	count_words(char *str, char *cset)
{
	int i;

	i = 0;
	while (str[i] && ft_chkdel(str[i], cset))

}

char	**ft_split(char *str, char *charset)
{
	/*
	strlen su str
	count words con chkdel come separatore
	mallocchiamo un **char per words+1 pk stringa 0 finale
	while che copia string in *char[i] MALLOCCATA E CHE NON PRENDE ANCHE INIZIO E FINE E POI LA NULLTERMINA.
	dopo while NULLiamo indirizzo dell'ultimo pointer malloccato in **char
	gg.
	*/
}
