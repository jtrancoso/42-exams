/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:38:22 by jtrancos          #+#    #+#             */
/*   Updated: 2020/10/21 19:44:51 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	int i;
	int j;
	int aux[255];

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
		{
			aux[i] = 0;
			i++;
		}
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (aux[(unsigned int)argv[i][j]] == 0)
				{
					aux[(unsigned int)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
