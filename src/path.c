/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 00:46:50 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/04 00:46:51 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		maxpath(t_lemin *lemin)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (!lemin->room_end->links || !lemin->room_begin->links)
		exit_error("In maxpath : not link on room_begin or room_end");
	while (lemin->room_end->links[a])
		++a;
	while (lemin->room_begin->links[b])
		++b;
	return (a < b ? a : b);
}

int		checkpath(t_lemin *lemin, t_room *room, int dist)
{
	int		a;
	t_room	*path;
	t_room	*tmp;

	while (room->links && (room->id != lemin->room_end->id))
	{
		path = NULL;
		a = 0;
		dist = -1;
		while (room->links && room->links[a])
		{
			tmp = room->links[a++];
			if ((dist == -1 || tmp->dist <= dist) && !tmp->path)
			{
				path = tmp;
				dist = tmp->dist;
			}
		}
		if (!path)
			return (0);
		path->path = lemin->paths;
		lemin->sizepath++;
		room = path;
	}
	return (1);
}

void	pathnumber(t_lemin *lemin, t_room *begin)
{
	int	max;

	max = maxpath(lemin);
	lemin->paths = 1;
	lemin->room_end->path = 0;
	lemin->room_begin->path = 1;
	checkpath(lemin, lemin->room_begin, 0);
	cleardist(begin);
	putdist(lemin->room_end, 1);
	lemin->paths++;
	while (lemin->paths <= max && (lemin->nb_ants > lemin->sizepath))
	{
		lemin->room_end->path = 0;
		lemin->room_begin->path = 1;
		if (checkpath(lemin, lemin->room_begin, 0))
			lemin->paths++;
		else
			max--;
		cleardist(begin);
		putdist(lemin->room_end, 1);
	}
}
