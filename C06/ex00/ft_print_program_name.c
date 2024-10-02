/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:15:18 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/02 00:21:36 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void ft_putstr(char *str)
{
    while(*str != '\0')
    {
        write(1, str, 1);
        str++;
    }
}
int main(int argc, char **argv)
{
	if (argc > 1)
		argc = 1;
	ft_putstr(argv[0]);
	write(1, "\n", 1);
	return (0);}
