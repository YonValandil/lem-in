/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:02:07 by jjourne           #+#    #+#             */
/*   Updated: 2018/05/15 09:30:33 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

//free

int		main(int argc, char *argv[])
{
	t_lemin		lemin;
	t_room		*room;

	(void)argv;
	room = NULL;
	if (argc != 1)
		exit_error("Error: nombre d'arguments incorrecte.");
	ft_bzero(&lemin, sizeof(lemin));
	room = parser(&lemin, room);
	printf("\nsolver() => vient du main (parsing ok)\n");
	solver(&lemin, room);
	return (0);
}
