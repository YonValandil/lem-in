/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 00:46:32 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/04 00:46:34 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	printmoove(t_lemin *lemin, t_room *dest, int ant)
{
	if (dest->id == lemin->room_end->id)
		lemin->ants_end++;
	if (!ant)
	{
		dest->ant = lemin->antnum;
		lemin->antnum++;
	}
	else
		dest->ant = ant;
	ft_printf("L%d-%s", dest->ant, dest->name);
}

void	moovefromstart(t_lemin *lemin)
{
	int		path;
	t_room	*dest;

	path = 1;
	while (lemin->ants_start && path != lemin->paths)
	{
		dest = findplace(lemin->room_begin, path);
		printmoove(lemin, dest, 0);
		lemin->ants_start--;
		path++;
		if (path != lemin->paths)
			ft_printf(" ");
	}
	ft_printf("\n");
}

void	moovefromrooms(t_lemin *lemin, t_room *begin)
{
	int		a;
	int		flag;
	t_room	*room;
	t_room	*dest;

	a = 1;
	while (a <= ((lemin->nb_ants - lemin->ants_start) + lemin->ants_end))
	{
		room = begin;
		flag = 0;
		while (room && !flag)
		{
			if (room->ant == a && (room->id != lemin->room_end->id))
			{
				dest = findplace(room, room->path);
				printmoove(lemin, dest, room->ant);
				if (a != lemin->nb_ants)
					ft_printf(" ");
				room->ant = 0;
				++flag;
			}
			room = room->next;
		}
		++a;
	}
}

void	mooveants(t_lemin *lemin, t_room *begin)
{
	lemin->room_end->path = -1;
	lemin->room_begin->path = 0;
	while (lemin->ants_end != lemin->nb_ants)
	{
		moovefromrooms(lemin, begin);
		moovefromstart(lemin);
	}
}
