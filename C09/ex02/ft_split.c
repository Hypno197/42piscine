/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:00:59 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/05 18:11:59 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_chkdel(char c, char *cset)
{
//questa prende c e confronta se é roba del cset
//dobbiamo fare in modo che inizia da 0 e inizia
//a contare solo quando incontra il char del charset
//e conta solo se è chiuso.
}

ft_strlen {}

int count_words(char *str, char *cset)
{
}

char **ft_split(char *str, char *charset)
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
