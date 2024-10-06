/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:54:10 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/04 11:54:16 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_boolean.h
#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

// Boolean type definition
typedef enum boolean
{
	FALSE = 0,
	TRUE = 1
}		t_bool;

// Macros
# define SUCCESS 0
# define EVEN(nbr) (nbr % 2 == 0)
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

// Function prototypes
void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif // FT_BOOLEAN_H
