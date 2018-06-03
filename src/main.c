/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:02:07 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/04 00:46:18 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

void	free_room(char **split)
{
	ft_memdel((void**)&split[0]);
	ft_memdel((void**)&split[1]);
	ft_memdel((void**)&split[2]);
	ft_memdel((void**)&split);
}

void	free_link(char **split)
{
	ft_memdel((void**)&split[0]);
	ft_memdel((void**)&split[1]);
	ft_memdel((void**)&split);
}

void	free_list(t_room *begin)
{
	t_room	*tmp;

	while (begin)
	{
		free(begin->source);
		free(begin->name);
		free(begin->links);
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}

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
	solver(&lemin, room);
	return (0);
}
