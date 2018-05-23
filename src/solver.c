#include "lemin.h"

void	putdist(t_room *room, int dist)
{
	int		a;
	t_room	*tmp;
	char	*source;

	a = 0;
	source = ft_strdup(room->name);
	while (room->links && room->links[a])
	{
		tmp = room->links[a];
		if (tmp && !tmp->path && (tmp->dist == -1 || dist < tmp->dist))
		{
			tmp->dist = dist;
			if (tmp->source)
				free(tmp->source);
			tmp->source = ft_strdup(source);
			if (ft_strcmp(tmp->name, room->source))
				putdist(tmp, dist + 1);
		}
		++a;
	}
	free(source);
}

void	cleardist(t_room *begin)
{
	t_room	*tmp;

	tmp = begin;
	while (tmp)
	{
		if (!tmp->path)
			tmp->dist = -1;
		tmp = tmp->next;
	}
}

t_room	*findplace(t_room *from, int path)
{
	int		a;
	int		dist;
	t_room	*tmp;
	t_room	*dest;

	a = 0;
	dist = -1;
	while (from->links[a])
	{
		tmp = from->links[a];
		if ((tmp->path == path || tmp->path == -1) &&
		(dist < 0 || tmp->dist < dist))
		{
			dist = tmp->dist;
			dest = tmp;
		}
		++a;
	}
	return (dest);
}

void solver(t_lemin *lemin, t_room *first_room)
{
	if (!lemin->room_begin || !lemin->room_end || !first_room)
		exit_error("In solver() : Impossible to start solver");
	lemin->room_end->source = ft_strdup(lemin->room_end->name);
	lemin->room_end->dist = 0;
	putdist(lemin->room_end, 1);
	if (lemin->room_begin->dist == -1)
		exit_error("In solver() : room_begin->dist == -1");
	printf("%s\n", lemin->displayline);//
	free(lemin->displayline);
	pathnumber(lemin, first_room);
	mooveants(lemin, first_room);
	free_list(first_room);
	exit(1);
}
